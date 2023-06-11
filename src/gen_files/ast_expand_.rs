use crate::parser::{Ast, InputName, Input_};

pub(crate) fn expand(mut ast: Ast) -> Ast {
    use std::collections::BTreeSet;

    let set_inputs: BTreeSet<InputName> = {
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

    for st in &mut ast.0 {
        let mut nw_inputs: Vec<Input_> = st
            .inputs
            .clone()
            .into_iter()
            .filter(|i| i.name.0 != "_")
            .collect();
        for input in &mut st.inputs {
            let set_used_inputs = {
                let mut set_used_inputs = BTreeSet::new();
                for _trans in &input.transitions {
                    if input.name.0 != "_" {
                        set_used_inputs.insert(input.name.clone());
                    }
                }
                set_used_inputs
            };

            for _trans in &input.transitions {
                if input.name.0 == "_" {
                    for i in &set_inputs {
                        if !set_used_inputs.contains(i) {
                            let ni = crate::parser::Input_ {
                                name: i.clone(),
                                transitions: input.transitions.clone(),
                            };
                            nw_inputs.push(ni);
                        }
                    }
                }
            }
        }
        st.inputs = nw_inputs;
    }

    ast
}
