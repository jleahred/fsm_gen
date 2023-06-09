use crate::gen_files::sup::*;
use crate::gen_files::Context;

// mod cpp_gen_file;
// mod h_gen_file;
// mod private_hpp_file;
// mod private_hpp_file_forward_gen;
mod templates;
mod types_h_file;
mod types_h_file_forward_gen;

pub(super) fn generate_files(context: &Context) -> std::result::Result<(), String> {
    // generate_file(
    //     context,
    //     &h_gen_file::get_full_name(context),
    //     templates::h_gen_file::t(),
    // )?;

    // generate_file(
    //     context,
    //     &cpp_gen_file::get_full_name(context),
    //     templates::cpp_gen_file::t(),
    // )?;

    generate_file(
        context,
        &types_h_file_forward_gen::get_full_name(context),
        templates::types_h_file_forward_gen::t(),
    )?;

    // generate_file(
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

    // generate_file(
    //     context,
    //     &private_hpp_file_forward_gen::get_full_name(context),
    //     templates::private_hpp_file_forward_gen::t(),
    // )?;
    // // generate_file(
    // generate_file_if_missing(
    //     context,
    //     &private_hpp_file::get_full_name(context),
    //     templates::private_hpp_file::t(),
    // )?;

    Ok(())
}

pub(crate) fn print_cpp_help_message() {
    println!(
        r#"
Being "name.fsm" the name of the file with the definition of the machine, four files will be generated.

    Main entry point. Do not modify
        fsm_<name>.h
        fsm_<name>.cpp

    Types. To be filled
        fsm/<name>_types.h

    Support functions. To be filled
        fsm/<name>_log.hpp
        fsm/<name>_guards.h
        fsm/<name>_guards.cpp
        fsm/<name>_actions.h
        fsm/<name>_actions.cpp
        fsm/<name>_transitions.h
        fsm/<name>_transitions.cpp


"#
    );
}
