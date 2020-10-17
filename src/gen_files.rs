pub(crate) mod cpp;
mod dot;
mod sup;

use crate::config::Config;
use crate::files::*;
use crate::parser::Ast;
use chrono::prelude::*;
use serde::{Deserialize, Serialize};
use std::path::PathBuf;

pub(crate) fn process(path: &PathBuf, config: &Config) -> std::result::Result<(), String> {
    let ast = crate::parser::compile(&read_file(path)?)?;
    let context = Context::new(ast, path)?;

    match config.lang {
        crate::cli_params::Lang::Cpp => {
            cpp::generate_files(&context, &path).map_err(|e| e.to_string())?
        }
    }

    if config.dot {
        dot::generate_file(&context.ast, &path).map_err(|e| e.to_string())?;
    }
    Ok(())
}

#[derive(Serialize, Deserialize)]
pub(crate) struct Context {
    pub(crate) ast: Ast,
    pub(crate) inputs: Vec<crate::parser::InputName>,
    pub(crate) gen_time: String,
    pub(crate) in_file: InFile,
}

impl Context {
    fn new(ast: Ast, path: &PathBuf) -> Result<Self, String> {
        let (dir, stem_name) = get_dir_stem_name(&path)?;
        let inputs = get_inputs(&ast);

        Ok(Context {
            ast,
            inputs,
            gen_time: Local::now().format("%Y-%m-%d %H:%M:%S").to_string(),
            in_file: InFile { dir, stem_name },
        })
    }
}

#[derive(Serialize, Deserialize)]
pub(crate) struct InFile {
    pub(crate) dir: String,
    pub(crate) stem_name: String,
}

fn get_inputs(ast: &Ast) -> Vec<crate::parser::InputName> {
    use std::collections::HashSet;

    let input_set = {
        let mut input_set = HashSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                if &input.name.0 != "_" {
                    input_set.insert(&input.name.0);
                }
            }
        }
        input_set
    };

    input_set
        .iter()
        .map(|&i| crate::parser::InputName(i.to_string()))
        .collect()
}
