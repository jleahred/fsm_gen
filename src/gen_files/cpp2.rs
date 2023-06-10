use crate::gen_files::sup::*;
use crate::gen_files::Context;

mod cpp_gen_file;
mod h_gen_file;
// mod private_hpp_file;
// mod private_hpp_file_forward_gen;
mod actions_cpp;
mod actions_h;
mod guards_cpp;
mod guards_h;
mod templates;
mod transitions_cpp;
mod transitions_h;
mod types_h_file;
mod types_h_file_forward_gen;

pub(super) fn generate_files(context: &Context) -> std::result::Result<(), String> {
    let folder = format!("{}/fsm_{}", context.in_file.dir, context.in_file.stem_name);
    match std::fs::create_dir_all(folder) {
        Ok(_) => (),
        Err(e) => panic!("Error al crear el directorio: {}", e),
    }

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

    generate_file_if_missing(
        context,
        &guards_cpp::get_full_name(context),
        templates::guards_cpp::t(),
    )?;

    generate_file_if_missing(
        context,
        &guards_h::get_full_name(context),
        templates::guards_h::t(),
    )?;

    generate_file_if_missing(
        context,
        &actions_cpp::get_full_name(context),
        templates::actions_cpp::t(),
    )?;

    generate_file(
        context,
        &actions_h::get_full_name(context),
        templates::actions_h::t(),
    )?;

    generate_file_if_missing(
        context,
        &transitions_cpp::get_full_name(context),
        templates::transitions_cpp::t(),
    )?;

    generate_file_if_missing(
        context,
        &transitions_h::get_full_name(context),
        templates::transitions_h::t(),
    )?;

    Ok(())
}

pub(crate) fn print_cpp_help_message() {
    println!(
        r#"
Being "name.fsm" the name of the file with the definition of the machine, four files will be generated.

    Main entry point. Do not modify
        fsm_<name>.h
        fsm_<name>.cpp

    Types
        fsm/<name>_types.h  (to be filled)
        fsm/<name>_types_forward.h

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
