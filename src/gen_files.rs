pub(crate) mod cpp1;
pub(crate) mod cpp2;
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
        crate::cli_params::Templ::Cpp1 => {
            cpp1::generate_files(&context).map_err(|e| e.to_string())?
        }
        crate::cli_params::Templ::Cpp2 => {
            cpp2::generate_files(&context).map_err(|e| e.to_string())?
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

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct TransitionToFromInput {
    to: crate::parser::StatusName,
    from: crate::parser::StatusName,
    input: crate::parser::InputName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct ActionFromInputTo {
    action: crate::parser::ActionName,
    from: crate::parser::StatusName,
    input: crate::parser::InputName,
    to: crate::parser::StatusName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct GuardFromInput {
    guard: crate::parser::GuardName,
    from: crate::parser::StatusName,
    input: crate::parser::InputName,
}

#[derive(Serialize, Deserialize)]
pub(crate) struct Context {
    pub(crate) ast: Ast,
    pub(crate) inputs: Vec<crate::parser::InputName>,
    pub(crate) guard_inputs: Vec<GuardInput>,
    pub(crate) action_init_param_to: Vec<ActionFromInputTo>,
    pub(crate) action_inputs: Vec<ActionInput>,
    pub(crate) guard_from_input: Vec<GuardFromInput>,
    pub(crate) transition_from_input_to: Vec<TransitionToFromInput>,
    pub(crate) transition_from_input_to_error: Vec<TransitionToFromInput>,
    pub(crate) gen_time: String,
    pub(crate) in_file: InFile,
}

impl Context {
    fn new(ast: Ast, path: &PathBuf) -> Result<Self, String> {
        let (dir, stem_name) = get_dir_stem_name(&path)?;
        let inputs = get_inputs(&ast);
        let guard_inputs = get_guard_inputs(&ast);
        let action_inputs = get_action_inputs(&ast);
        let action_init_param_to = get_action_from_input_to(&ast);
        let guard_from_input = get_guard_from_input(&ast);
        let transition_from_input_to = get_transition_from_input_to(&ast);
        let transition_from_input_to_error = get_transition_from_input_to_error(&ast);

        Ok(Context {
            ast,
            inputs,
            guard_inputs,
            action_inputs,
            action_init_param_to,
            guard_from_input,
            transition_from_input_to,
            transition_from_input_to_error,
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

fn get_action_from_input_to(ast: &Ast) -> Vec<ActionFromInputTo> {
    use std::collections::HashSet;

    let action_set: HashSet<ActionFromInputTo> = {
        let mut action_set = HashSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for action in &trans.actions {
                        action_set.insert(ActionFromInputTo {
                            action: action.clone(),
                            from: st.name.clone(),
                            input: input.name.clone(),
                            to: trans.new_status.name.clone(),
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

fn get_guard_from_input(ast: &Ast) -> Vec<GuardFromInput> {
    use std::collections::HashSet;

    let set: HashSet<GuardFromInput> = {
        let mut set = HashSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for guard in &trans.guards {
                        set.insert(GuardFromInput {
                            guard: guard.name.clone(),
                            from: st.name.clone(),
                            input: input.name.clone(),
                        });
                    }
                }
            }
        }
        set
    };

    set.iter().fold(vec![], |mut acc, ai| {
        acc.push(ai.clone());
        acc
    })
}

fn get_transition_from_input_to(ast: &Ast) -> Vec<TransitionToFromInput> {
    use std::collections::BTreeSet;

    // #[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
    // struct FromInput {
    //     from: crate::parser::StatusName,
    //     input: crate::parser::InputName,
    // }

    // let set_inputs: BTreeSet<crate::parser::InputName> = {
    //     let mut set = BTreeSet::new();
    //     for st in &ast.0 {
    //         for input in &st.inputs {
    //             set.insert(input.name.clone());
    //         }
    //     }
    //     set
    // };

    // let set_from_input: BTreeSet<FromInput> = {
    //     let mut set = BTreeSet::new();
    //     for st in &ast.0 {
    //         for input in &set_inputs {
    //             set.insert(FromInput {
    //                 from: st.name.clone(),
    //                 input: input.clone(),
    //             });
    //         }
    //     }
    //     set
    // };

    let set: BTreeSet<TransitionToFromInput> = {
        let mut set = BTreeSet::new();

        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    if input.name.0 != "_" && trans.new_status.name.0 != "error" {
                        set.insert(TransitionToFromInput {
                            to: trans.new_status.name.clone(),
                            from: st.name.clone(),
                            input: input.name.clone(),
                        });
                    }
                }
            }
        }

        set
    };

    set.iter().fold(vec![], |mut acc, ai| {
        acc.push(ai.clone());
        acc
    })
}

fn get_transition_from_input_to_error(ast: &Ast) -> Vec<TransitionToFromInput> {
    use std::collections::BTreeSet;

    #[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
    struct FromInput {
        from: crate::parser::StatusName,
        input: crate::parser::InputName,
    }

    let set_inputs: BTreeSet<crate::parser::InputName> = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                set.insert(input.name.clone());
            }
        }
        set
    };

    let set_from_input: BTreeSet<FromInput> = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &set_inputs {
                set.insert(FromInput {
                    from: st.name.clone(),
                    input: input.clone(),
                });
            }
        }
        set
    };

    let set: BTreeSet<TransitionToFromInput> = {
        let mut set = BTreeSet::new();
        for from_input in &set_from_input {
            if from_input.input.0 != "_" {
                set.insert(TransitionToFromInput {
                    to: crate::parser::StatusName("error".to_owned()),
                    from: from_input.from.clone(),
                    input: from_input.input.clone(),
                });
            }
        }

        set
    };

    set.iter().fold(vec![], |mut acc, ai| {
        acc.push(ai.clone());
        acc
    })
}
