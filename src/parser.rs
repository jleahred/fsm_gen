pub(crate) mod types;

use peg::parser;
use std::result::Result;
use types::Ast;
use types::*;

fn parse_error2string(input: &str, pe: ::peg::error::ParseError<peg::str::LineCol>) -> String {
    let location = pe.location.clone();
    let error_txt = format!("{}", pe);
    let line = input.split('\n').nth(location.line - 1).unwrap_or("");
    let indicator = " ".repeat(6 + location.column);
    format!("{}\nline: {:?}\n{}^", error_txt, line, indicator)
}

pub(crate) fn compile(input: &str) -> Result<Ast, String> {
    fsm_peg::compile(input)
        .or_else(|e| Err(parse_error2string(input, e)))
        .and_then(|ast| ast.check_status_refs(input))
        .and_then(|ast| ast.expand_())
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
            =   _()  guards:guard()*  _() "->"  _()  new_status:status_ref() adapter_name:adapter_name()?  _()  actions:actions()  __endl()
                { Transition {guards, actions, new_status, adapter_name} }


        rule guard() -> Guard
            =   _ "&" _  "!" name:guard_name()  adapter_name:adapter_name()?    {  Guard{name, positiv: false, adapter_name}  }
            /   _ "&" _      name:guard_name()  adapter_name:adapter_name()?    {  Guard{name, positiv: true , adapter_name}  }


        rule actions() -> Vec<Action>
            =   "/"  actions:action()*          { actions }
            /                                   { vec![]  }

        rule action() -> Action
            =   name:action_name() adapter_name:adapter_name()? { Action{ name, adapter_name} }

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

        rule adapter_name() -> AdapterName
            =   "|" _() name:id()  { AdapterName(name) }

        rule id()    ->  String
            =   id:$( ['a'..='z' | 'Z'..='Z' | '_']
                      ['a'..='z' | 'Z'..='Z' | '_' | '0'..='9']*)
                { id.to_string() }

        rule _()        = quiet!{[' ' | '\t']*}
        rule comment()  = "//" (!endl() [_])*
        rule __()       = ([' ' | '\t' | '\n'] / comment())*
        rule __endl()   = _() endl()   __()
                        / _() comment()   __()


        rule _endls()   = quiet!{ [' ' | '\t' | '\n']* }
        rule endl()     = quiet!{ ['\n'] }
        rule endls()    = quiet!{ endl()* }
    }
}
