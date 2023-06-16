use super::*;
use crate::parser::types::{self as parser};

pub(crate) fn get_inputs(ast: &parser::Ast) -> Vec<parser::InputName> {
    let input_set = {
        let mut input_set = BTreeSet::new();
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
        .map(|&i| parser::InputName(i.to_string()))
        .collect()
}

pub(crate) fn get_guard_inputs(ast: &parser::Ast) -> Vec<GuardInput> {
    let set = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for guard in &trans.guards {
                        set.insert(GuardInput {
                            guard: guard.name.clone(),
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

pub(crate) fn get_action_inputs(ast: &parser::Ast) -> Vec<ActionInput> {
    let set = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for action in &trans.actions {
                        set.insert(ActionInput {
                            action: action.clone(),
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

pub(crate) fn get_action_from_input_to(ast: &parser::Ast) -> BTreeSet<ActionFromInputTo> {
    let mut action_set = BTreeSet::new();
    for st in &ast.0 {
        for input in &st.inputs {
            for trans in &input.transitions {
                for action in &trans.actions {
                    if action.transformer_name.is_none() {
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
    }
    action_set
}

pub(crate) fn get_action_transformers(ast: &parser::Ast) -> BTreeSet<ActionTransformer> {
    let mut action_set = BTreeSet::new();
    for st in &ast.0 {
        for input in &st.inputs {
            for trans in &input.transitions {
                for action in &trans.actions {
                    if let Some(transformer_name) = &action.transformer_name {
                        action_set.insert(ActionTransformer {
                            action_name: action.name.clone(),
                            transformer_name: transformer_name.clone(),
                        });
                    }
                }
            }
        }
    }
    action_set
}

pub(crate) fn get_guard_from_input(ast: &parser::Ast) -> Vec<GuardFromInput> {
    let set: BTreeSet<GuardFromInput> = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    for guard in &trans.guards {
                        if guard.transformer_name.is_none() {
                            set.insert(GuardFromInput {
                                guard: guard.name.clone(),
                                from: st.name.clone(),
                                input: input.name.clone(),
                            });
                        }
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

pub(crate) fn get_guard_transformers(ast: &parser::Ast) -> BTreeSet<GuardTransformer> {
    let mut action_set = BTreeSet::new();
    for st in &ast.0 {
        for input in &st.inputs {
            for trans in &input.transitions {
                for guard in &trans.guards {
                    if let Some(transformer_name) = &guard.transformer_name {
                        action_set.insert(GuardTransformer {
                            guard_name: guard.name.clone(),
                            transformer_name: transformer_name.clone(),
                        });
                    }
                }
            }
        }
    }
    action_set
}

pub(crate) fn get_transition_from_input_to(ast: &parser::Ast) -> Vec<TransitionToFromInput> {
    #[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
    struct FromInput {
        from: parser::StatusName,
        input: parser::InputName,
    }

    let set_inputs: BTreeSet<parser::InputName> = {
        let mut set = BTreeSet::new();
        for st in &ast.0 {
            for input in &st.inputs {
                if input.name.0 != "_" {
                    set.insert(input.name.clone());
                }
            }
        }
        set
    };

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
        let mut set_consumed_from_input = BTreeSet::new();

        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    if input.name.0 != "_" && trans.new_status.name.0 != "error" {
                        set.insert(TransitionToFromInput {
                            to: trans.new_status.name.clone(),
                            from: st.name.clone(),
                            input: input.name.clone(),
                        });
                        set_consumed_from_input.insert(FromInput {
                            from: st.name.clone(),
                            input: input.name.clone(),
                        });
                    }
                }
            }
        }

        for st in &ast.0 {
            for input in &st.inputs {
                for trans in &input.transitions {
                    if input.name.0 == "_" && trans.new_status.name.0 != "error" {
                        for i in &set_inputs {
                            if !set_consumed_from_input.contains(&FromInput {
                                from: st.name.clone(),
                                input: input.name.clone(),
                            }) {
                                set.insert(TransitionToFromInput {
                                    to: trans.new_status.name.clone(),
                                    from: st.name.clone(),
                                    input: i.clone(),
                                });
                            }
                        }
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

pub(crate) fn get_transition_from_input_to_error(ast: &parser::Ast) -> Vec<TransitionToFromInput> {
    #[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
    struct FromInput {
        from: parser::StatusName,
        input: parser::InputName,
    }

    let set_inputs: BTreeSet<parser::InputName> = {
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
                    to: parser::StatusName("error".to_owned()),
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

pub(crate) fn get_dir_stem_name(orig_path: &PathBuf) -> Result<(String, String), String> {
    let to_string = |p: &Option<&str>| -> Result<String, String> {
        Ok(p.ok_or(format!(
            "cannot take original file name from {:?}",
            orig_path
        ))?
        .to_string())
    };

    let dir = {
        let mut dir = orig_path.clone();
        dir.pop();
        dir
    };

    let dir_string = to_string(&dir.to_str())?;
    let dir_string = if dir_string == "" {
        ".".to_string()
    } else {
        dir_string
    };

    Ok((
        dir_string,
        to_string(&orig_path.file_stem().and_then(|fname| fname.to_str()))?,
    ))
}

pub(crate) fn get_transformers(ast: &parser::Ast) -> Transformers {
    let mut transformers = Transformers(BTreeMap::new());

    for st in &ast.0 {
        for input in &st.inputs {
            for trans in &input.transitions {
                if let Some(name) = trans.transformer_name.clone() {
                    let params = vec![
                        Param {
                            name: ParamName(st.name.0.clone()),
                            kind: ParamKind::Status,
                        },
                        Param {
                            name: ParamName(input.name.0.clone()),
                            kind: ParamKind::Input,
                        },
                        Param {
                            name: ParamName(trans.new_status.name.0.clone()),
                            kind: ParamKind::Status,
                        },
                    ];
                    transformers
                        .0
                        .entry(name)
                        .or_insert(BTreeSet::new())
                        .insert(Params(params));
                }
                for guard in &trans.guards {
                    if let Some(name) = guard.transformer_name.clone() {
                        let params = vec![
                            Param {
                                name: ParamName(st.name.0.clone()),
                                kind: ParamKind::Status,
                            },
                            Param {
                                name: ParamName(input.name.0.clone()),
                                kind: ParamKind::Input,
                            },
                        ];
                        transformers
                            .0
                            .entry(name)
                            .or_insert(BTreeSet::new())
                            .insert(Params(params));
                    }
                }
                for action in &trans.actions {
                    if let Some(name) = action.transformer_name.clone() {
                        let params = vec![
                            Param {
                                name: ParamName(st.name.0.clone()),
                                kind: ParamKind::Status,
                            },
                            Param {
                                name: ParamName(input.name.0.clone()),
                                kind: ParamKind::Input,
                            },
                            Param {
                                name: ParamName(trans.new_status.name.0.clone()),
                                kind: ParamKind::Status,
                            },
                        ];
                        transformers
                            .0
                            .entry(name)
                            .or_insert(BTreeSet::new())
                            .insert(Params(params));
                    }
                }
            }
        }
    }

    transformers
}
