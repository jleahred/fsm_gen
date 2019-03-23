use fomat_macros::fomat;
use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

use crate::file::*;

//  -------------
//      cpp

pub(crate) fn generate_header_fsm_code(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> Result<(), String> {
    let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

    let file_name = format!("{}/fsm_{}.h", dir, stem_name);
    println!("Generating file... {}", file_name);

    if std::path::Path::new(&file_name).exists() {
        return Ok(());
    }

    let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

    let header_guard = || fomat!("FSM_" (stem_name.to_uppercase()) "_H");

    let status_info_empty = || {
        get_status_names(fsm).iter().fold("".to_string(), |r, i| {
            format!("{}  struct {}_info_t{{}};\n", r, i)
        })
    };

    let in_types_empty_decl = || {
        get_input_names(fsm).iter().fold("".to_string(), |r, i| {
            format!("{}  struct {}_t {{}};\n", r, i)
        })
    };

    let template = fomat!(
        r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

    
#ifndef "# (header_guard()) r#"
#define "# (header_guard()) r#"

#include <string>

#include "fsm_"# (stem_name) r#"_gen.h"

namespace "# (stem_name) r#" {

  //  status info types
"# (status_info_empty()) r#"

  //  input types
"# (in_types_empty_decl()) r#"


    //  log
template <typename IN, typename INIT_ST, typename END_ST>
void log(const std::string &context, const IN &, const INIT_ST &, const END_ST &) {
  std::cout << context << std::endl;
}

} // namespace "# (stem_name) r#"
#endif // "# (header_guard()) r#"
"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
