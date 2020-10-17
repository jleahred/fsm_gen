// use crate::files::*;
// use crate::gen_files::cpp::templates;
use crate::gen_files::Context;
// use tera::Tera;

//  -------------
//      cpp

pub(crate) fn get_full_name(context: &Context) -> String {
    format!(
        "{}/fsm_{}_gen.h",
        context.in_file.dir, context.in_file.stem_name
    )
}

// pub(crate) fn generate(context: &Context) -> Result<(), String> {
//     let full_file_name = format!(
//         "{}/fsm_{}_gen.h",
//         context.in_file.dir, context.in_file.stem_name
//     );

//     let content = get_processed_txt(context)?;

//     write_file(&full_file_name, &content)?;

//     Ok(())
// }

// fn err2string<E: std::fmt::Display>(err: E) -> String {
//     format!("{}", err)
// }

// fn get_processed_txt(context: &Context) -> Result<String, String> {
//     Tera::one_off(
//         templates::h_gen_file::t(),
//         &tera::Context::from_serialize(context).map_err(err2string)?,
//         false,
//     )
//     .map_err(err2string)
// }

// pub(crate) fn generate(ast: &crate::parser::Ast, orig_path: &PathBuf) -> Result<(), String> {
//     let (file_name, stem_name) = file_name_stem(orig_path)?;

//     println!("Generating file... {}", file_name);
//     let mut f = File::create(file_name).map_err(|e| format!("{}", e))?;

//     let header_guard = || fomat!("FSM_" (stem_name.to_uppercase()) "_GENERATED_H");

//     let in_methods_forward_decl = || {
//         crate::parser::get_all_input_names(ast).iter().fold(
//             "".to_string(),
//             |acc, name| fomat!((acc) "  void process(const in_"(name.0)"_t& in);\n"),
//         )
//     };

//     let template = fomat!(r#"
// //  generated automatically  "# (Local::now().format("%Y-%m-%d %H:%M:%S").to_string()) r#"
// //  do not modify it manually

// #ifndef "# (header_guard()) r#"
// #define "# (header_guard()) r#"

// #include <iostream>
// #include <memory>

// #include "fsm_"# (stem_name) r#"_types.h"

// namespace "# (stem_name) r#" {

// class BaseState;
// typedef std::shared_ptr<BaseState> SState;

// //  -------------------
// //      F S M
// class Fsm {
// public:
//   Fsm();
//   ~Fsm();

// "# (in_methods_forward_decl()) r#"

// private:
//   SState state;
// };

// //      F S M
// //  -------------------

// } // namespace "# (stem_name) r#"

// #endif // "# (header_guard()) r#"
// "#
//     );

//     f.write_all(template.as_bytes())
//         .map_err(|e| format!("{}", e))?;

//     f.sync_all().map_err(|e| format!("{}", e))?;
//     Ok(())
// }

// fn file_name_stem(orig_path: &PathBuf) -> Result<(String, String), String> {
//     let (dir, stem_name) = get_dir_stem_name(&orig_path)?;

//     Ok((format!("{}/fsm_{}_gen.h", dir, stem_name), stem_name))
// }
