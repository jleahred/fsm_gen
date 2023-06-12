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
    if !std::path::Path::new(&full_file_name).exists() {
        generate_file(context, &full_file_name, template)
    } else {
        Ok(())
    }
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

use std::fs::File;
use std::io::prelude::*;

pub(crate) fn write_file(full_file_name: &str, content: &str) -> Result<(), String> {
    println!("Generating file... {}", full_file_name);
    let mut f = File::create(full_file_name).map_err(|e| format!("{}", e))?;

    f.write_all(content.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}

fn snake2camel(txt: &str) -> String {
    txt.to_owned()
}

#[test]
fn test_tera_filter_2snake() {
    assert_eq!("Rq", snake2camel("Rq"));
    assert_eq!("RqNw", snake2camel("RqNw"));
    assert_eq!("RqNw", snake2camel("rq_nw"));
    assert_eq!("RqNwA", snake2camel("rq_nw_a"));
}
