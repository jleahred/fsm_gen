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

    let in_methods_forward_decl = || {
        crate::parser::get_all_input_names(fsm)
            .iter()
            .fold("".to_string(), |r, i| {
                format!("{}  void in(const in_{}_t& in);\n", r, i)
            })
    };

    let template = fomat!(r#"
//  generated automatically  "# (Local::now().format("%Y-%m-%d %H:%M:%S").to_string()) r#"
//  do not modify it manually

#ifndef "# (header_guard()) r#"
#define "# (header_guard()) r#"

#include <iostream>
#include <memory>

#include "fsm_"# (stem_name) r#"_types.h"

namespace "# (stem_name) r#" {

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

} // namespace "# (stem_name) r#"

#endif // "# (header_guard()) r#"
"#
    );

    f.write_all(template.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}
