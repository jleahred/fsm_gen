use chrono::prelude::*;
use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp

pub(crate) fn generate_header_fsm_code_generated(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/fsm_{}_gen.h", dir, stem_name);
    println!("Generating file... {}", file_name);
    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let header_guard = || fomat!("FSM_" (stem_name.to_uppercase()) "_GENERATED_H");

    let forward_status_info = || {
        get_status_names(fsm).iter().fold("".to_string(), |r, i| {
            format!("{}struct {}_info_t;\n", r, i)
        })
    };

    let forward_struct_in = || {
        get_input_names(fsm)
            .iter()
            .fold("".to_string(), |r, i| format!("{}struct {}_t;\n", r, i))
    };

    let transactions_changes_forward_decl = || {
        get_transchange_in_to(fsm)
            .iter()
            .fold("".to_string(), |r, i| {
                format!("{0}  {1}_info_t in2{1}(const {2}_t& i);\n", r, i.1, i.0)
            })
    };

    let guards2implement = || {
        let st_gen_guards = |st: &crate::parser::Status| {
            st.transitions.iter().fold("".to_string(), |acc, t| {
                if let Some(g) = &t.guard {
                    format!(
                        "{}  bool {}(const {}_t& in, const  {}_info_t& st_info);\n",
                        acc,
                        g.to_string(),
                        t.input,
                        st.name
                    )
                } else {
                    acc
                }
            })
        };
        fsm.iter().fold("".to_string(), |acc, st| {
            format!("{}{}", acc, st_gen_guards(st))
        })
    };

    let in_methods_forward_decl = || {
        get_input_names(fsm).iter().fold("".to_string(), |r, i| {
            format!("{}  void in(const {}_t& in);\n", r, i)
        })
    };

    let template = fomat!(r#"
//  generated automatically  "# (Local::now().format("%Y-%m-%d %H:%M:%S").to_string()) r#"
//  do not modify it manually

#ifndef FSM_"# (header_guard()) r#"
#define FSM_"# (header_guard()) r#"

#include <iostream>
#include <memory>

namespace login {

//  ----------------------------------------------------
//      TO FILL BY HAND

//  declaration on fsm_"# (stem_name) r#".h
//  forward_status_info
"# (forward_status_info()) r#"

//  in
"# (forward_struct_in()) r#"

//      TO FILL BY HAND
//  ----------------------------------------------------

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
  Fsm();
  ~Fsm();

"# (in_methods_forward_decl()) r#"



private:
  SState state;
};

//      F S M
//  -------------------

  //  ----------------------------------------------------
  //      TO FILL BY HAND
  
  //  implementation in fsm_"# (stem_name) r#".cpp

  //  status change functions
"# (transactions_changes_forward_decl()) r#"

  //  guards to implement
"# (guards2implement()) r#"

  //      TO FILL BY HAND
  //  ----------------------------------------------------

} // namespace login

#endif // "# (header_guard()) r#"

"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
