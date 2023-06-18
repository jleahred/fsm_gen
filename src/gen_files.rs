pub(crate) mod cpp2;
mod dot;
mod support;
mod types;

use crate::config::Config;
use std::fs::File;
use std::io::Read;
use std::path::PathBuf;
use types::*;

pub(crate) fn process(path: &PathBuf, config: &Config) -> std::result::Result<(), String> {
    let ast = crate::parser::compile(&read_file(path)?)?;
    let context = Context::new(ast, path)?;

    let fn_gen_file_if_missing = if config.force {
        support::generate_file
    } else {
        support::generate_file_if_missing
    };

    match config.templ {
        crate::cli_params::Templ::Cpp2 => {
            cpp2::generate_files(&context, fn_gen_file_if_missing).map_err(|e| e.to_string())?
        }
    }

    if config.dot {
        dot::generate_files(&context).map_err(|e| e.to_string())?;
    }
    Ok(())
}

fn read_file(path: &PathBuf) -> std::result::Result<String, String> {
    let mut file = File::open(path).map_err(|e| format!("{}", e))?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .map_err(|e| format!("{}", e))?;
    Ok(contents.to_string())
}
