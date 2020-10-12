use fomat_macros::fomat;
// use idata::cont::IVec;
// use std::collections::BTreeSet;
use crate::gen_files::get_dir_stem_name;
use std::fs::File;
use std::io::Write;
use std::path::PathBuf;

//  -------------
//      cpp
pub(crate) fn generate(ast: &crate::parser::Ast, orig_path: &PathBuf) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;
    {
        // generate if don't exists
        let full_file_name = format!("{}/fsm_{}_types.h", dir, stem_name);
        if !std::path::Path::new(&full_file_name).exists() {
            generate_file(ast, &full_file_name, &stem_name)?;
        }
    }
    {
        // generate reference allways
        let full_file_name = format!("{}/fsm_{}_types.h.reference", dir, stem_name);
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

    let header_guard = || fomat!("FSM_" (stem_name.to_uppercase()) "_H");

    let status_info_empty = || {
        crate::parser::get_all_status_names(ast).iter().fold(
            "".to_string(),
            |acc, name| fomat!((acc)"\n  struct st_" (name.0) "_t{};\n"),
        )
    };

    let in_types_empty_decl = || {
        crate::parser::get_all_input_names(ast).iter().fold(
            "".to_string(),
            |acc, name| fomat!((acc)"\n  struct in_" (name.0) "_t{};\n"),
        )
    };

    let template = fomat!(
        r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  Generator will allways create a  .reference file to help with
//  new methods and so

    
#ifndef "# (header_guard()) r#"
#define "# (header_guard()) r#"

#include <string>

namespace "# (stem_name) r#" {

  //  status info types
"# (status_info_empty()) r#"

  //  input types
"# (in_types_empty_decl()) r#"

} // namespace "# (stem_name) r#"
#endif // "# (header_guard()) r#"
"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
