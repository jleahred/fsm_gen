use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

pub(crate) mod cpp;
mod dot;
mod support;

pub(crate) struct Config {
    pub(crate) lang: crate::cli_params::Langs,
    pub(crate) dot: bool,
}

pub(crate) fn process(path: &PathBuf, config: &Config) -> std::result::Result<(), String> {
    let ast = crate::parser::parse(&read_file(path)?)?;

    match config.lang {
        crate::cli_params::Langs::Cpp => {
            cpp::generate_files(&ast, &path).map_err(|e| e.to_string())?
        }
    }

    if config.dot {
        dot::generate_file(&ast, &path).map_err(|e| e.to_string())?;
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
