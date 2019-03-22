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
    get_input_names(fsm).iter().fold("".to_string(), |r, i| {
      format!(
        "{}  virtual SState in(const {}_t& in, Fsm& fsm) = 0;\n",
        r, i
      )
    })
  };

  let override_inputs = || {
    get_input_names(fsm).iter().fold("".to_string(), |r, i| {
      format!("{}  SState in(const {}_t& in, Fsm& fsm) override;\n", r, i)
    })
  };

  let fsm_in = || {
    get_input_names(fsm).iter().fold("".to_string(), |r, i| {
      format!(
        "{}void Fsm::in(const {}_t& in) {{ state ->in(in, *this); }}\n",
        r, i
      )
    })
  };

  let status_clases_declaration = || {
    get_status_names(fsm).iter().fold("".to_string(), |r, i| {
      format!(
        r#"{}class {1} : public BaseState {{
public:
    {1}(const {1}_info_t& i) : info(i) {{}}
    virtual ~{1}(){{}}

private:
    {1}_info_t info;

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
      transitions4input(sn, input)
        .iter()
        .fold("    if(false) {;\n".to_string(), |acc, tr| {
          if let Some(guard) = &tr.guard {
            fomat!((acc)r#"    } else if(fsm."# (guard) r#"(in, info)) {
        return std::make_shared<"# (tr.new_status) r#">(fsm.in2"# (tr.new_status) r#"(in));
"#)
          } else {
            fomat!((acc)r#"    } else {
        return std::make_shared<"# (tr.new_status) r#">(fsm.in2"# (tr.new_status) r#"(in));
    }              
"#)
          }
        })
    };
    let state_impl = |sn: &str| {
      get_input_names(fsm)
        .iter()
        .fold("".to_string(), |r, input| {
          fomat!((r)r#"
  SState "# (sn) r#"::in(const "# (input) r#"_t& in, Fsm& fsm) {
"# (impl_input_trans(sn, input)) r#"}
    "#)
        })
    };
    // let state_impl = |sn: &str, trans: &[crate::parser::Transition]| {
    //     transitions4input(sn, &tans).fold("".to_string(), |acc, t|{
    //         fomat!((acc)r#"
    // SState "# (sn) r#"::in(const "# (tr.input) r#"_t& in) {
    //   return std::make_shared<"# (tr.new_status) r#">("# (tr.new_status) r#"_info_t{});
    // }
    // "#)
    //     })
    //   )
    // };

    fsm.iter().fold("".to_string(), |r, st| {
      format!("{}{}", r, state_impl(&st.name))
    })
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

Fsm::Fsm() {}
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
