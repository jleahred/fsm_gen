use chrono::prelude::*;
use fomat_macros::fomat;
use idata::cont::IVec;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp

pub(crate) fn generate_cpp_fsm_code_generated(
  fsm: &[crate::parser::Status],
  orig_path: &PathBuf,
) -> Result<(), String> {
  let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

  let file_name = format!("{}/fsm_{}_gen.cpp", dir, stem_name);
  println!("Generating file... {}", file_name);

  let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

  let in_methods_forward_virtual = || {
    crate::parser::get_all_input_names(fsm)
      .iter()
      .fold("".to_string(), |r, i| {
        format!("{}  virtual SState in(const in_{}_t& in) = 0;\n", r, i)
      })
  };

  let override_inputs = || {
    crate::parser::get_all_input_names(fsm)
      .iter()
      .fold("".to_string(), |r, i| {
        format!("{}  SState in(const in_{}_t& in) override;\n", r, i)
      })
  };

  let fsm_in = || {
    crate::parser::get_all_input_names(fsm)
      .iter()
      .fold("".to_string(), |r, i| {
        format!(
          "{}void Fsm::in(const in_{}_t& in) {{ state = state ->in(in); }}\n",
          r, i
        )
      })
  };

  let status_clases_declaration = || {
    crate::parser::get_status_names(fsm)
      .iter()
      .fold("".to_string(), |r, i| {
        format!(
          r#"{}class {1} : public BaseState {{
public:
    {1}(const st_{1}_info_t& i) : info(i) {{}}
    virtual ~{1}(){{}}

private:
    st_{1}_info_t info;

{2}
}};

"#,
          r,
          i,
          override_inputs()
        )
      })
  };

  let all_states_in = || {
    let transitions4input = |sn: &str, input: &str| -> Vec<crate::parser::Transition> {
      fsm
        .iter()
        .filter(|st| st.name == sn)
        .take(1)
        .fold(vec![], |acc, st| {
          acc.iappend(st.transitions.iter().fold(vec![], |acc, tr| {
            if tr.input == input {
              acc.ipush(tr.clone())
            } else {
              acc
            }
          }))
        })
    };
    let impl_input_trans = |sn: &str, input: &str| {
      let change_trans = |sn, tr: &crate::parser::Transition, guard_txt: &str| {
        let action_code = if let Some(action) = &tr.action {
          format!("act_{}(this->info, in, nw_st_info);\n", action)
        } else {
          "".to_string()
        };
        fomat!(r#"auto nw_st_info = from_in2"# (tr.new_status) r#"(this->info, in);
        log("["# (sn) r#"] "# (tr.input) r#""# (guard_txt) r#" -> "# (tr.new_status) r#"", in, info, nw_st_info);
        "# (action_code) r#"        return std::make_shared<"# (tr.new_status) r#">(nw_st_info);
"#)
      };
      transitions4input(sn, input)
        .iter()
        .fold("    if(false) {;\n".to_string(), |acc, tr| {
          if let Some(guard) = &tr.guard {
            let guard_txt = format!("({})", guard);
            fomat!((acc)r#"    } else if("# (guard) r#"(in, info)) {
        "# (change_trans(sn, tr, &guard_txt)) r#""#)
          } else {
            fomat!((acc)r#"    } else {
        "# (change_trans(sn, tr, "")) r#"
    }              
"#)
          }
        })
    };
    let state_impl = |sn: &str| {
      crate::parser::get_all_input_names(fsm)
        .iter()
        .fold("".to_string(), |r, input| {
          fomat!((r)r#"
  SState "# (sn) r#"::in(const in_"# (input) r#"_t& in) {
"# (impl_input_trans(sn, input)) r#"}
    "#)
        })
    };

    fsm.iter().fold("".to_string(), |r, st| {
      format!("{}{}", r, state_impl(&st.name))
    })
  };

  let first_state_name = || {
    fsm
      .iter()
      .take(1)
      .fold("".to_string(), |_, st| st.name.to_string())
  };

  let template = fomat!(r#"
//  generated automatically  "# (Local::now().format("%Y-%m-%d %H:%M:%S").to_string()) r#"
//  do not modify it manually

#include "fsm_"# (stem_name) r#"_gen.h"
#include "fsm_"# (stem_name) r#".h"

namespace "# (stem_name) r#" {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

public:
"# (in_methods_forward_virtual()) r#"
};


"# (status_clases_declaration()) r#"

Fsm::Fsm() : state(std::make_shared<"# (first_state_name()) r#">(st_"# (first_state_name()) r#"_info_t{})) {}
Fsm::~Fsm() {}

"# (fsm_in()) r#"

"# (all_states_in()) r#"

} // namespace "# (stem_name) r#"

"#
    );

  f.write_all(template.as_bytes())
    .map_err(|e| format!("{}", e))?;

  f.sync_all().map_err(|e| format!("{}", e))?;
  Ok(())
}
