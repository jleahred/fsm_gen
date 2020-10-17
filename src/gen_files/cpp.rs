use crate::gen_files::sup::*;
use crate::gen_files::Context;

mod cpp_gen_file;
mod h_gen_file;
mod hpp_file;
mod templates;
mod types_h_file;

pub(super) fn generate_files(context: &Context) -> std::result::Result<(), String> {
    generate_file(
        context,
        &h_gen_file::get_full_name(context),
        templates::h_gen_file::t(),
    )?;

    generate_file(
        context,
        &cpp_gen_file::get_full_name(context),
        templates::cpp_gen_file::t(),
    )?;

    generate_file_if_missing(
        context,
        &types_h_file::get_full_name(context),
        templates::types_h_file::t(),
    )?;
    generate_file(
        context,
        &format!("{}{}", &types_h_file::get_full_name(context), ".reference"),
        templates::types_h_file::t(),
    )?;

    generate_file_if_missing(
        context,
        &hpp_file::get_full_name(context),
        templates::hpp_file::t(),
    )?;
    generate_file(
        context,
        &format!("{}{}", &hpp_file::get_full_name(context), ".reference"),
        templates::hpp_file::t(),
    )?;

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
