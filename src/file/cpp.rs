use std::path::PathBuf;

mod cpp_gen_file;
mod h_gen_file;
mod hpp_file;
mod types_h_file;

pub(super) fn generate_files(
    ast: &crate::parser::Ast,
    orig_path: &PathBuf,
) -> std::result::Result<(), String> {
    h_gen_file::generate(ast, orig_path).map_err(|e| e.to_string())?;
    cpp_gen_file::generate(ast, orig_path).map_err(|e| e.to_string())?;
    types_h_file::generate(ast, orig_path).map_err(|e| e.to_string())?;
    hpp_file::generate(ast, orig_path).map_err(|e| e.to_string())?;
    Ok(())
}

pub(crate) fn print_cpp_help_message() {
    println!(
        r#"
Being "name.fsm" the name of the file with the definition of the machine, two files will be generated.

    fsm_name_gen.cpp
    fsm_name_gen.h

In them the declarations and definitions of the state machine will be generated.

In fsm_name_gen.h it is indicated with comments, the methods to overwrite manually and the file where it is convenient to do it.

The manual implementation of the methods and declarations of the types, it is recommended to do it in the following files.

    fsm_name_gen.cpp
    fsm_name_gen.h

If they do not exist, they will be created with an empty implementation.
"#
    );
}
