use crate::files::*;
use crate::gen_files::Context;
use tera::Tera;

pub(crate) fn generate_file(
    context: &Context,
    full_file_name: &str,
    template: &str,
) -> Result<(), String> {
    let content = get_processed_txt(context, template)?;

    write_file(&full_file_name, &content)?;

    Ok(())
}

pub(crate) fn generate_file_if_missing(
    context: &Context,
    full_file_name: &str,
    template: &str,
) -> Result<(), String> {
    //  todo:0
    // if !std::path::Path::new(&full_file_name).exists() {
    generate_file(context, &full_file_name, template)
    // } else {
    //     Ok(())
    // }
}

fn err2string<E: std::fmt::Display>(err: E) -> String {
    format!("{}", err)
}

fn get_processed_txt(context: &Context, template: &str) -> Result<String, String> {
    Tera::one_off(
        template,
        &tera::Context::from_serialize(context).map_err(err2string)?,
        false,
    )
    .map_err(err2string)
}
