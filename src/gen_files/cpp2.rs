use crate::gen_files::support::generate_file;
use crate::gen_files::Context;

mod file_names;
mod templates;

use file_names::*;

pub(super) fn generate_files(
    context: &Context,
    gen_file_if_missing: fn(&Context, &str, &str) -> Result<(), String>,
) -> std::result::Result<(), String> {
    {
        let folder = format!("{}/fsm_{}", context.in_file.dir, context.in_file.stem_name);
        match std::fs::create_dir_all(folder) {
            Ok(_) => (),
            Err(e) => panic!("Error al crear el directorio: {}", e),
        }
    }

    {
        let folder = format!(
            "{}/fsm_{}/impl",
            context.in_file.dir, context.in_file.stem_name
        );
        match std::fs::create_dir_all(folder) {
            Ok(_) => (),
            Err(e) => panic!("Error al crear el directorio: {}", e),
        }
    }

    generate_file(
        context,
        &file_names::fsm_h::get_full_name(context),
        templates::fsm_h::t(),
    )?;

    generate_file(
        context,
        &fsm_cpp::get_full_name(context),
        templates::fsm_cpp::t(),
    )?;

    generate_file(
        context,
        &types_h_reference::get_full_name(context),
        templates::types_h_reference::t(),
    )?;

    // generate_file(
    gen_file_if_missing(
        context,
        &types_h_file::get_full_name(context),
        templates::types_h_file::t(),
    )?;

    generate_file(
        context,
        &types_transformers_forward_h_file::get_full_name(context),
        templates::types_transformers_forward_h::t(),
    )?;

    gen_file_if_missing(
        context,
        &types_transformers_h_file::get_full_name(context),
        templates::types_transformers_h::t(),
    )?;

    gen_file_if_missing(
        context,
        &guards_cpp::get_full_name(context),
        templates::guards_cpp::t(),
    )?;

    generate_file(
        context,
        &guards_h::get_full_name(context),
        templates::guards_h::t(),
    )?;

    gen_file_if_missing(
        context,
        &actions_cpp::get_full_name(context),
        templates::actions_cpp::t(),
    )?;

    generate_file(
        context,
        &actions_h::get_full_name(context),
        templates::actions_h::t(),
    )?;

    gen_file_if_missing(
        context,
        &transitions_cpp::get_full_name(context),
        templates::transitions_cpp::t(),
    )?;

    generate_file(
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
