use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp

pub(crate) fn generate_hpp_fsm_code(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/fsm_{}_private.hpp", dir, stem_name);
    println!("Generating file... {}", file_name);

    if std::path::Path::new(&file_name).exists() {
        return Ok(());
    }

    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let guards = || {
        let st_gen_guards = |st: &crate::parser::Status| {
            st.transitions.iter().fold("".to_string(), |acc, t| {
                if let Some(g) = &t.guard {
                    format!(
                        "{}    bool {}(const in_{}_t& /*in*/, const  st_{}_t& /*st_info*/) {{ return true; }}\n",
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

    let actions = || {
        let st_gen_actions = |st: &crate::parser::Status| {
            st.transitions.iter().fold("".to_string(), |acc, t| {
                if let Some(a) = &t.action {
                    format!(
                        "{}    void act_{}(const st_{}_t& /*st_orig*/, const in_{}_t& /*in*/, const  st_{}_t& /*st_dest*/) {{}}\n",
                        acc,
                        a.to_string(),
                        st.name,
                        t.input,
                        t.new_status,
                    )
                } else {
                    acc
                }
            })
        };
        fsm.iter().fold("".to_string(), |acc, st| {
            format!("{}{}", acc, st_gen_actions(st))
        })
    };

    let status_change_functions = || {
        fsm.iter().fold("".to_string(), |acc, st| {
            format!("{0}    template <typename FROM, typename IN> st_{1}_t from_in2{1}(const FROM&, const IN&) {{ return st_{1}_t{{}}; }}\n", acc, st.name)
        })
    };

    let template = fomat!(
        r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

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
