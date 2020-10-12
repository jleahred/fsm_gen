use crate::file::*;
use chrono::prelude::*;
use fomat_macros::fomat;
use std::fs::File;
use std::path::PathBuf;
use support::get_dir_stem_name;

//  -------------
//      cpp

pub(crate) fn generate(ast: &crate::parser::Ast, orig_path: &PathBuf) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/fsm_{}_gen.cpp", dir, stem_name);
    println!("Generating file... {}", file_name);

    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let in_methods_forward_virtual = || {
        crate::parser::get_all_input_names(ast).iter().fold(
      "".to_string(),
      |acc, input_name| fomat!((acc)"  virtual SState input(const in_"(input_name.0)"_t& in) = 0;\n"),
    )
    };

    let override_inputs = || {
        crate::parser::get_all_input_names(ast).iter().fold(
      "".to_string(),
      |acc, input_name| fomat!((acc)"\n        SState input(const in_"(input_name.0)"_t& in) override;"),
    )
    };

    let fsm_in = || {
        crate::parser::get_all_input_names(ast)
      .iter()
      .fold("".to_string(), |acc, input_name| {
        fomat!(
          (acc)"void Fsm::process(const in_"(input_name.0)"_t& in) { state = state ->input(in); }\n"
        )
      })
    };

    let status_clases_declaration = || {
        crate::parser::get_all_status_names(ast)
            .iter()
            .fold("".to_string(), |acc, input_name| {
                format!(
                    r#"{}class {1} : public BaseState {{
    public:
        {1}(const st_{1}_t& i) : info(i) {{}}
        virtual ~{1}(){{}}

    private:
        st_{1}_t info;
    {2}
    }};

    "#,
                    acc,
                    input_name.0,
                    override_inputs()
                )
            })
    };

    let guard_checks = |status: &crate::parser::Status,
                        transition_input_name: &crate::parser::InputName,
                        input_name: &crate::parser::InputName| {
        //     if(timeout(in, info)) {
        //         auto nw_st_info = from_in2error<st_w_login_t, in_timer_t>(this->info, in);
        //         log("[w_login] timer(timeout) -> error", in, info, nw_st_info);
        //         return std::make_shared<error>(nw_st_info);
        //     }
        let mut result = String::new();
        for input in status.inputs.iter() {
            if input.name == *input_name {
                for transition in input.transitions.iter() {
                    let mut guards_cond = String::new();
                    let mut guards_list = String::new();
                    for guard in transition.guards.iter() {
                        guards_cond += &fomat!(" && "(guard.name.0)"(in, info)");
                        guards_list += &fomat!("("(guard.name.0)")");
                    }
                    let new_status_name = transition.new_status.name.clone();

                    let mut actions = String::new();
                    for action_name in transition.actions.iter() {
                        actions += &fomat!("act_"(action_name.0)"(this->info, in, nw_st_info);");
                    }

                    let guards_body = fomat!(
                      r#"
          auto nw_st_info = from_in2"#(new_status_name.0)r#"<st_"#(status.name.0)r#"_t, in_"#(transition_input_name.0)r#"_t>(this->info, in);
          log("["#(status.name.0)r#"] "#(transition_input_name.0)r#""#(guards_list)r#" -> "#(new_status_name.0)r#"", in, info, nw_st_info);
          "#(actions)r#"
          return std::make_shared<"#(new_status_name.0)r#">(nw_st_info);"#
                    );
                    result +=
                        &fomat!("\n       if(true "(guards_cond)") {"(guards_body)"\n       }");
                }
            }
        }
        result
    };

    let error_transition = |status: &crate::parser::Status,
                            input_name: &crate::parser::InputName| {
        fomat!(
          r#"
    auto nw_st_info = from_in2error<st_"#(status.name.0)r#"_t, in_"#(input_name.0)r#"_t>(this->info, in);
    log("["#(status.name.0)r#"] "#(input_name.0)r#" error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    "#
        )
    };

    let all_states_in = || {
        // SState w_login::in(const in_timer_t& in) {
        //   if(false) {;
        //   } else if(timeout(in, info)) {
        //       auto nw_st_info = from_in2error<st_w_login_t, in_timer_t>(this->info, in);
        //       log("[w_login] timer(timeout) -> error", in, info, nw_st_info);
        //       return std::make_shared<error>(nw_st_info);
        //   } else {
        //       auto nw_st_info = from_in2w_login<st_w_login_t, in_timer_t>(this->info, in);
        //       log("[w_login] timer -> w_login", in, info, nw_st_info);
        //       return std::make_shared<w_login>(nw_st_info);
        //   }
        // }
        let mut result = String::new();
        for status in ast.0.iter() {
            let status_name = status.name.clone();
            for input_name in crate::parser::get_all_input_names(ast) {
                result += &fomat!(
                  r#"
  SState "#(status_name.0)r#"::input(const in_"#(input_name.0)r#"_t& in) {
    try {"#(guard_checks(status, &input_name, &input_name))r#""#(guard_checks(status, &input_name, &crate::parser::InputName("_".to_string())))r#"
    } catch (...) {}
    "#(error_transition(status, &input_name))r#"
  }"#
                );
            }
        }
        result

        // let transitions4input =
        //   |sn: &crate::parser::StatusName, input: &str| -> Vec<crate::parser::Transition> {
        //     ast
        //       .0
        //       .iter()
        //       .filter(|st| st.name == *sn)
        //       .take(1)
        //       .fold(vec![], |acc, st| {
        //         acc.iappend(st.transitions.iter().fold(vec![], |acc, tr| {
        //           if tr.input == input {
        //             acc.ipush(tr.clone())
        //           } else {
        //             acc
        //           }
        //         }))
        //       })
        //   };
        //     let impl_input_trans = |sn: &str, input: &str| {
        //       let change_trans = |sn, tr: &crate::parser::Transition, guard_txt: &str| {
        //         let action_code = if let Some(action) = &tr.action {
        //           format!("act_{}(this->info, in, nw_st_info);\n        ", action)
        //         } else {
        //           "".to_string()
        //         };
        //         fomat!(r#"auto nw_st_info = from_in2"# (tr.new_status) r#"<st_"# (sn) r#"_t, in_"# (tr.input) r#"_t>(this->info, in);
        //         log("["# (sn) r#"] "# (tr.input) r#""# (guard_txt) r#" -> "# (tr.new_status) r#"", in, info, nw_st_info);
        //         "# (action_code) r#"return std::make_shared<"# (tr.new_status) r#">(nw_st_info);
        // "#)
        //       };
        //       transitions4input(sn, input)
        //         .iter()
        //         .fold("    if(false) {;}\n".to_string(), |acc, tr| {
        //           if let Some(guard) = &tr.guard {
        //             let guard_txt = format!("({})", guard);
        //             fomat!((acc)r#"    else if("# (guard) r#"(in, info)) {
        //         "# (change_trans(sn, tr, &guard_txt)) r#"
        //     }
        //     "#)
        //           } else {
        //             fomat!((acc)r#"    else {
        //         "# (change_trans(sn, tr, "")) r#"
        //     }
        // "#)
        //           }
        //         })
        //     };
        //     let state_impl = |sn: &str| {
        //       crate::parser::get_all_input_names(fsm)
        //         .iter()
        //         .fold("".to_string(), |r, input| {
        //           fomat!((r)r#"
        //   SState "# (sn) r#"::in(const in_"# (input) r#"_t& in) {
        // "# (impl_input_trans(sn, input)) r#"}
        //     "#)
        //         })
        //     };

        //     fsm.iter().fold("".to_string(), |r, st| {
        //       format!("{}{}", r, state_impl(&st.name))
        //     })
    };

    let first_state_name = || {
        ast.0
            .iter()
            .take(1)
            .fold("".to_string(), |_, st| st.name.0.clone())
    };

    let template = fomat!(r#"
//  generated automatically  "# (Local::now().format("%Y-%m-%d %H:%M:%S").to_string()) r#"
//  do not modify it manually

#include "fsm_"# (stem_name) r#"_gen.h"

#include "fsm_"# (stem_name) r#"_private.hpp"

namespace "# (stem_name) r#" {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

public:
"# (in_methods_forward_virtual()) r#"
};


"# (status_clases_declaration()) r#"

Fsm::Fsm() : state(std::make_shared<"# (first_state_name()) r#">(st_"# (first_state_name()) r#"_t{})) {}
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
