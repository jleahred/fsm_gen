use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  --------------------
//      dot graphviz

pub(crate) fn generate_file(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/{}.dot", dir, stem_name);
    println!("Generating file... {}", file_name);

    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let transitions_fsm = || {
        let transition_st = |st: &crate::parser::Status| {
            let guard = |oguard: &Option<String>| {
                if let Some(g) = oguard {
                    format!("({})", g)
                } else {
                    "".to_string()
                }
            };
            let action = |oaction: &Option<String>| {
                if let Some(a) = oaction {
                    format!(" / {}", a)
                } else {
                    "".to_string()
                }
            };
            st.transitions
                .iter()
                .filter(|t| t.input != "_")
                .filter(|t| !(t.action.is_none() && t.guard.is_none() && st.name == t.new_status))
                .fold("".to_string(), |acc, t| {
                    format!(
                        "{}\n{} -> {} [label=\"{}{}{}\"]",
                        acc,
                        st.name,
                        t.new_status,
                        t.input,
                        guard(&t.guard),
                        action(&t.action)
                    )
                })
        };
        fsm.iter().fold("".to_string(), |acc, st| {
            format!("{}\n{}", acc, transition_st(st))
        })
    };

    let template = fomat!(
        r#"
digraph finite_state_machine {
	rankdir=LR;
	size="8,5"
	node [shape = circle, width=1];

"# (transitions_fsm()) r#"
}

"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
