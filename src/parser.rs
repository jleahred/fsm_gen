use idata::cont::IVec;
use peg::parser;
use std::collections::{BTreeMap, BTreeSet};
use std::result::Result;

///Ast(
///    [
///        Status {
///            name: StatusName(
///                "init",
///            ),
///            inputs: [
///                Input_ {
///                    name: InputName(
///                        "rq_key",
///                    ),
///                    transitions: [
///                        Transition {
///                            guard: [],
///                            actions: [
///                                ActionName(
///                                    "send_key",
///                                ),
///                            ],
///                            new_status: StatusRef {
///                                name: StatusName(
///                                    "w_login",
///                                ),
///                                pos: 55,
///                            },
///                        },
///         ...

#[derive(Debug)]
pub(crate) struct Ast(pub(crate) Vec<Status>);

#[derive(Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct StatusName(pub(crate) String);
#[derive(Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct InputName(pub(crate) String);
#[derive(Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct GuardName(pub(crate) String);
#[derive(Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct ActionName(pub(crate) String);
#[derive(Debug, PartialEq, PartialOrd, Ord, Eq, Clone)]
pub(crate) struct StatusRef {
    pub(crate) name: StatusName,
    pos: usize,
}

#[derive(Debug, PartialEq, PartialOrd, Ord, Eq)]
pub(crate) struct Status {
    pub(crate) name: StatusName,
    pub(crate) inputs: Vec<Input_>,
}

#[derive(Debug, PartialEq, PartialOrd, Ord, Eq)]
pub(crate) struct Input_ {
    pub(crate) name: InputName,
    pub(crate) transitions: Vec<Transition>,
}

#[derive(Debug, PartialEq, PartialOrd, Ord, Eq)]
pub(crate) struct Guard {
    pub(crate) name: GuardName,
    pub(crate) positiv: bool,
}

#[derive(Debug, PartialEq, PartialOrd, Ord, Eq)]
pub(crate) struct Transition {
    pub(crate) guards: Vec<Guard>,
    pub(crate) actions: Vec<ActionName>,
    pub(crate) new_status: StatusRef,
}

fn parse_error2string(input: &str, pe: ::peg::error::ParseError<peg::str::LineCol>) -> String {
    let location = pe.location.clone();
    let error_txt = format!("{}", pe);
    let line = input.split('\n').nth(location.line - 1).unwrap_or("");
    let indicator = " ".repeat(6 + location.column);
    format!("{}\nline: {:?}\n{}^", error_txt, line, indicator)
}

fn get_status(ast: &Ast) -> (BTreeSet<StatusName>, BTreeMap<StatusName, usize>) {
    let status = ast.0.iter().fold(BTreeSet::new(), |mut acc, st| {
        acc.insert(st.name.clone());
        acc
    });
    let status_refs = ast.0.iter().fold(BTreeMap::new(), |acc, st| {
        st.inputs.iter().fold(acc, |acc, input| {
            input.transitions.iter().fold(acc, |mut acc, transition| {
                acc.insert(
                    transition.new_status.name.clone(),
                    transition.new_status.pos,
                );
                acc
            })
        })
    });
    (status, status_refs)
}

pub(crate) fn parse(input: &str) -> Result<Ast, String> {
    fsm_peg::compile(input)
        .or_else(|e| Err(parse_error2string(input, e)))
        .and_then(|ast| check_status_refs(input, ast))
}

parser! {
    grammar fsm_peg() for str {
        pub(crate)  rule  compile() -> Ast
            =  st:status()+ { Ast(st) }

        rule status() -> Status
            =   __()  "["  name: status_name()  "]"  __()
                inputs:input()+  __()
                { Status { name, inputs: inputs } }

        rule input() -> Input_
            =   _()  name:InputName()  _()  endl()?   transitions:transition()+  __()
                { Input_{name, transitions} }

        rule transition() -> Transition
            =   _()  guards:guard()*  _() "->"  _()  new_status:status_ref()  _()  actions:actions()  __endl()
                { Transition {guards, actions, new_status} }


        rule guard() -> Guard
            =   _ "&" _  "!" name:guard_name()   {  Guard{name, positiv: false}  }
            /   _ "&" _      name:guard_name()   {  Guard{name, positiv: true }  }


        rule actions() -> Vec<ActionName>
            =   "/"  actions:action_name()*     { actions }
            /                                   { vec![]  }

        rule action_name() -> ActionName
            =   _()  name:id()
                {  ActionName(name.to_string())  }
        rule guard_name() -> GuardName
            =   name:id()
                {  GuardName(name.to_string())  }
        rule InputName() -> InputName
            =   name:id()
                {  InputName(name.to_string())  }

        rule status_name() -> StatusName
            =   name:id()
                {  StatusName(name.to_string())  }
        rule status_ref() -> StatusRef
            =   name:id() pos:position!()
                {  StatusRef{name: StatusName(name.to_string()), pos}  }

        rule id()    ->  String
            =   id:$( ['a'..='z' | 'Z'..='Z' | '_']
                      ['a'..='z' | 'Z'..='Z' | '_' | '0'..='9']*)
                { id.to_string() }

        rule _()        = quiet!{[' ' | '\t']*}
        rule comment()  = "//" (!endl() [_])*
        rule __()       = ([' ' | '\t' | '\n'] / comment())*
        rule __endl()   = [' ' | '\t']* endl()   __()
                        / comment()   __()


        rule _endls()   = quiet!{ [' ' | '\t' | '\n']* }
        rule endl()     = quiet!{ ['\n'] }
        rule endls()    = quiet!{ endl()* }
    }
}

fn get_line_from_pos(txt: &str, pos: usize) -> String {
    let res = txt
        .chars()
        .rev()
        .skip(txt.len() - pos)
        .take_while(|ch| !ch.is_control())
        .collect::<String>()
        .chars()
        .rev()
        .collect();
    dbg!(&res);
    res
}

fn check_status_refs(input: &str, ast: Ast) -> Result<Ast, String> {
    let (status, status_refs) = get_status(&ast);
    let status_no_refs = status.iter().fold(vec![], |acc, k| {
        if !status_refs.contains_key(k) && *k != StatusName("init".to_string()) {
            acc.ipush(k)
        } else {
            acc
        }
    });
    if !status_no_refs.is_empty() {
        Err(format!("status not referenced\n{:#?}", status_no_refs))
    } else {
        let status_refs_non_exists = status_refs.iter().fold(vec![], |acc, (k, v)| {
            if !status.contains(k) {
                acc.ipush((k, v))
            } else {
                acc
            }
        });
        if !status_refs_non_exists.is_empty() {
            let lines =
                status_refs_non_exists
                    .iter()
                    .fold("".to_string(), |mut acc, (st_name, &pos)| {
                        acc = format!(
                            "{}\n  {} >> {}",
                            &acc,
                            st_name.0,
                            get_line_from_pos(input, pos)
                        );
                        acc
                    });
            Err(format!("reference to non existing status{}", lines))
        } else {
            Ok(ast)
        }
    }
}

pub(crate) fn get_all_input_names(ast: &Ast) -> BTreeSet<InputName> {
    ast.0.iter().fold(BTreeSet::new(), |acc, st| {
        st.inputs.iter().fold(acc, |mut acc, inputs| {
            if inputs.name.0 != "_" {
                acc.insert(inputs.name.clone());
            }
            acc
        })
    })
}

pub(crate) fn get_all_status_names(ast: &Ast) -> Vec<StatusName> {
    ast.0
        .iter()
        .fold(vec![], |acc, st| acc.ipush(st.name.clone()))
}
