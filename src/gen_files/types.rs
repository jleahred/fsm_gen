mod support;

use crate::parser::types as parser;
use chrono::prelude::*;
use serde::{Deserialize, Serialize};
use std::path::PathBuf;
use support::*;

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct GuardInput {
    guard: parser::GuardName,
    input: parser::InputName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct ActionInput {
    action: parser::Action,
    input: parser::InputName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct TransitionToFromInput {
    to: parser::StatusName,
    from: parser::StatusName,
    input: parser::InputName,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone, Hash)]
pub(crate) struct StatusNameOrTransform(pub(crate) String);

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct ActionTo {
    action: parser::ActionName,
    to: StatusNameOrTransform,
}

#[derive(Serialize, Deserialize, Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct GuardFromInput {
    guard: parser::GuardName,
    from: parser::StatusName,
    input: parser::InputName,
}

#[derive(Serialize, Deserialize)]
pub(crate) struct Context {
    pub(crate) ast: parser::Ast,
    pub(crate) inputs: Vec<parser::InputName>,
    pub(crate) guard_inputs: Vec<GuardInput>,
    pub(crate) action_to: Vec<ActionTo>,
    pub(crate) action_inputs: Vec<ActionInput>,
    pub(crate) guard_from_input: Vec<GuardFromInput>,
    pub(crate) transition_from_input_to: Vec<TransitionToFromInput>,
    pub(crate) transition_from_input_to_error: Vec<TransitionToFromInput>,
    pub(crate) transformers: Vec<parser::Transformer>,
    pub(crate) gen_time: String,
    pub(crate) in_file: InFile,
}

impl Context {
    pub(crate) fn new(ast: parser::Ast, path: &PathBuf) -> Result<Self, String> {
        let (dir, stem_name) = get_dir_stem_name(&path)?;
        let inputs = get_inputs(&ast);
        let guard_inputs = get_guard_inputs(&ast);
        let action_inputs = get_action_inputs(&ast);
        let action_to = get_action_from_input_to(&ast);
        let guard_from_input = get_guard_from_input(&ast);
        let transition_from_input_to = get_transition_from_input_to(&ast);
        let transition_from_input_to_error = get_transition_from_input_to_error(&ast);
        let transformers = get_transformers(&ast);

        Ok(Context {
            ast,
            inputs,
            guard_inputs,
            action_inputs,
            action_to,
            guard_from_input,
            transition_from_input_to,
            transition_from_input_to_error,
            transformers,
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
