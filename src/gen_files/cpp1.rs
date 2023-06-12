use crate::gen_files::support::generate_file;
use crate::gen_files::Context;

mod cpp_gen_file;
mod h_gen_file;
mod private_hpp_file;
mod private_hpp_file_forward_gen;
mod templates;
mod types_h_file;
mod types_h_file_forward_gen;

pub(super) fn generate_files(
    context: &Context,
    gen_file_if_missing: fn(&Context, &str, &str) -> Result<(), String>,
) -> std::result::Result<(), String> {
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

    gen_file_if_missing(
        context,
        &types_h_file::get_full_name(context),
        templates::types_h_file::t(),
    )?;

    generate_file(
        context,
        &private_hpp_file_forward_gen::get_full_name(context),
        templates::private_hpp_file_forward_gen::t(),
    )?;

    gen_file_if_missing(
        context,
        &private_hpp_file::get_full_name(context),
        templates::private_hpp_file::t(),
    )?;

    Ok(())
}

pub(crate) fn print_cpp_help_message() {
    println!(
        r#"
Being "name.fsm" the name of the file with the definition of the machine, four files will be generated.

    gen_fsm_<name>.h
    fsm_<name>_types.h
    fsm_<name>_private.hpp

    gen_fsm_<name>.cpp


About fsm_<name>_private.hpp

    //  Code generated automatically to be filled manually
    //  This file will not be updated by generator
    //  It's created just the first time as a reference
    //  but a file with same name ended wiht .reference will be created always
    //    generated on xxxxx

    //  This file will be included in gen_fsm_<name>.cpp
    //  (anywhere else)

    Logic to fill guards functions, transitions, logging...

About fsm_<name>_types.h

    //  Code generated automatically to be filled manually
    //  This file will not be updated by generator
    //  It's created just the first time as a reference
    //  but a file with same name ended wiht .reference will be created always

    You can write your logic on data types for fsm

About   gen_fsm_<name>.h  and   gen_fsm_<name>.cpp

    //  generated automatically  2020-11-02 00:15:18
    //  do not modify it manually

"#
    );
}
