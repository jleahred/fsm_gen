use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp

pub(crate) fn generate_cpp_fsm_code(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/fsm_{}.cpp", dir, stem_name);
    println!("Generating file... {}", file_name);

    // if std::path::Path::new(&file_name).exists() {
    //     return Ok(());
    // }

    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let transactions_changes = || {
        crate::parser::get_transchange_in_to(fsm)
            .iter()
            .fold("".to_string(), |r, i| {
                format!(
                    "{0}    st_{3}_info_t from_in2{3}(const st_{1}_info_t& /*from*/, const in_{2}_t& /*in*/){{ return st_{3}_info_t{{}};}}\n",
                    r, i.0, i.1, i.2
                )
            })
    };

    let guards = || {
        let st_gen_guards = |st: &crate::parser::Status| {
            st.transitions.iter().fold("".to_string(), |acc, t| {
                if let Some(g) = &t.guard {
                    format!(
                        "{}    bool {}(const in_{}_t& /*in*/, const  st_{}_info_t& /*st_info*/) {{ return true; }}\n",
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
                        "{}    void act_{}(const st_{}_info_t& /*st_orig*/, const in_{}_t& /*in*/, const  st_{}_info_t& /*st_dest*/) {{}}\n",
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

    let template = fomat!(
        r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_"# (stem_name) r#".h"
#include "fsm_"# (stem_name) r#"_gen.h"

namespace "# (stem_name) r#" {

    //  status change functions
"# (transactions_changes()) r#"

    //  guards
"# (guards()) r#"

    //  actions
"# (actions()) r#"

} // namespace "# (stem_name) r#"
"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
