use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp
pub(crate) fn generate(ast: &crate::parser::Ast, orig_path: &PathBuf) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;
    {
        // generate if don't exists
        let full_file_name = format!("{}/fsm_{}_private.hpp", dir, stem_name);
        if !std::path::Path::new(&full_file_name).exists() {
            generate_file(ast, &full_file_name, &stem_name)?;
        }
    }
    {
        // generate reference allways
        let full_file_name = format!("{}/fsm_{}_private.hpp.reference", dir, stem_name);
        generate_file(ast, &full_file_name, &stem_name)?;
    }
    Ok(())
}

fn generate_file(
    ast: &crate::parser::Ast,
    full_file_name: &str,
    stem_name: &str,
) -> Result<(), String> {
    println!("Generating file... {}", full_file_name);

    let mut f = File::create(full_file_name).map_err(|e| format!("{}", e))?;

    let guards = || {
        let mut result = "".to_string();
        for st in ast.0.iter() {
            let st_name = st.name.clone();
            for input in &st.inputs {
                let input_name = input.name.clone();
                for tr in &input.transitions {
                    for guard in &tr.guards {
                        let guard_name = guard.name.clone();
                        let line = fomat!("    bool "(guard_name.0) "(const in_"(input_name.0)"_t& /*in*/, const st_"(st_name.0)"_t& /*st_from*/) { return true; }\n");
                        result += &line;
                    }
                }
            }
        }
        result
    };

    let actions = || {
        let mut result = "".to_string();
        for st in ast.0.iter() {
            let st_from_name = st.name.clone();
            for input in &st.inputs {
                let input_name = input.name.clone();
                use std::collections::BTreeSet;
                let mut generated_actions: BTreeSet<(
                    crate::parser::ActionName,
                    crate::parser::StatusName,
                )> = BTreeSet::new();
                for tr in &input.transitions {
                    let new_status_name = tr.new_status.name.clone();
                    for action in &tr.actions {
                        let action_name = action.clone();
                        if !generated_actions
                            .contains(&(action_name.clone(), new_status_name.clone()))
                        {
                            generated_actions
                                .insert((action_name.clone(), new_status_name.clone()));
                            let line = if input_name.0 != "_" {
                                fomat!("    void act_"(action_name.0) "(const st_"(st_from_name.0) "_t& /*from*/, const in_"(input_name.0)"_t& /*input*/, const st_"(new_status_name.0)"_t& /*st_dest*/) {}\n")
                            } else {
                                fomat!("    template<typename IN> void act_"(action_name.0) "(const st_"(st_from_name.0) "_t& /*from*/, const IN& /*input*/, const st_"(new_status_name.0)"_t& /*st_dest*/) {}\n")
                            };
                            result += &line;
                        }
                    }
                }
            }
        }
        result
    };

    let status_change_functions = || {
        let mut result = String::new();

        for st in ast.0.iter() {
            let st_name = st.name.clone();
            result += &fomat!("    template <typename FROM, typename IN> st_"(st_name.0)"_t from_in2"(st_name.0)"(const FROM&, const IN&) { return st_"(st_name.0)"_t{}; }\n");
        }
        result
    };

    let template = fomat!(
        r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  Generator will allways create a  .reference file to help with
//  new methods and so

//  This file will be included in _gen.cpp
//  (anywhere else)

//  to make happy some IDEs
#include "fsm_"# (stem_name) r#"_types.h"
#include "fsm_"# (stem_name) r#"_gen.h"

namespace {
    using namespace "# (stem_name) r#";

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << txt_trans << std::endl;
    }

    //  status change functions
"# (status_change_functions()) r#"

    //  guards
"# (guards()) r#"

    //  actions
"# (actions()) r#"

} // namespace anonymous
"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
