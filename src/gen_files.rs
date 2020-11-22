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

    match config.templ {
        crate::cli_params::Templ::Cpp => {
            cpp::generate_files(&context).map_err(|e| e.to_string())?
        }
    }

    if config.dot {
        dot::generate_files(&context).map_err(|e| e.to_string())?;
    }
    Ok(())
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct GuardInput {
    guard: crate::parser::GuardName,
    input: crate::parser::InputName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct ActionInput {
    action: crate::parser::ActionName,
    input: crate::parser::InputName,
}

#[derive(Serialize, Deserialize)]
pub(crate) struct Context {
    pub(crate) ast: Ast,
    pub(crate) inputs: Vec<crate::parser::InputName>,
    pub(crate) guard_inputs: Vec<GuardInput>,
    pub(crate) action_inputs: Vec<ActionInput>,
    pub(crate) gen_time: String,
    pub(crate) in_file: InFile,
}

impl Context {
    fn new(ast: Ast, path: &PathBuf) -> Result<Self, String> {
        let (dir, stem_name) = get_dir_stem_name(&path)?;
        let inputs = get_inputs(&ast);
        let guard_inputs = get_guard_inputs(&ast);
        let action_inputs = get_action_inputs(&ast);

        Ok(Context {
            ast,
            inputs,
            guard_inputs,
            action_inputs,
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

fn get_guard_inputs(ast: &Ast) -> Vec<GuardInput> {
    use std::collections::HashSet;

    let action_set = {
        let mut action_set = HashSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for guard in &trans.guards {
                        action_set.insert(GuardInput {
                            guard: guard.name.clone(),
                            input: input.name.clone(),
                        });
                    }
                }
            }
        }
        action_set
    };

    action_set.iter().fold(vec![], |mut acc, ai| {
        acc.push(ai.clone());
        acc
    })
}

fn get_action_inputs(ast: &Ast) -> Vec<ActionInput> {
    use std::collections::HashSet;

    let action_set = {
        let mut action_set = HashSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for action in &trans.actions {
                        action_set.insert(ActionInput {
                            action: action.clone(),
                            input: input.name.clone(),
                        });
                    }
                }
            }
        }
        action_set
    };

    action_set.iter().fold(vec![], |mut acc, ai| {
        acc.push(ai.clone());
        acc
    })
}
