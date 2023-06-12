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
    let mut tera = Tera::default();
    tera.register_filter("ToCamel", tera_filter_snake2camel);
    tera.add_raw_template("template", template)
        .map_err(err2string)?;
    tera.render(
        "template",
        &tera::Context::from_serialize(context).map_err(err2string)?,
    )
    .map_err(err2string)
    // Tera::one_off(
    //     template,
    //     &tera::Context::from_serialize(context).map_err(err2string)?,
    //     false,
    // )
    // .map_err(err2string)
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

pub(crate) fn tera_filter_snake2camel(
    val: &tera::Value,
    _args: &std::collections::HashMap<String, tera::Value>,
) -> tera::Result<tera::Value> {
    Ok(tera::Value::from(snake2camel(
        val.as_str()
            .ok_or(tera::Error::from("val is not an string"))?,
    )))
}

fn snake2camel(txt: &str) -> String {
    txt //
        .split("_")
        .map(|w| capitalize_first_letter(w))
        .collect()
}

#[test]
fn test_snake2camel() {
    assert_eq!("Rq", snake2camel("Rq"));
    assert_eq!("RqNw", snake2camel("RqNw"));
    assert_eq!("RqNw", snake2camel("rq_nw"));
    assert_eq!("RqNwA", snake2camel("rq_nw_a"));
}

fn capitalize_first_letter(s: &str) -> String {
    s.char_indices()
        .map(|(i, c)| {
            if i == 0 {
                c.to_uppercase().to_string()
            } else {
                c.to_string()
            }
        })
        .collect()
}
