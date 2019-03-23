/*  Example:
 *
 *  [init]
 *      rq_key                  ->  w_login     /   send_key
 *      rq_login                ->  logout      /   log_err
 *      rq_logout               ->  logout      /   log_err
 *      heartbeat               ->  logout      /   log_err
 *      timer                   ->  init
 *
 *
 *  [w_login]
 *      rq_key                  ->  logout      /   log_err
 *      rq_login    &   valid   ->  login       /   send_login
 *      rq_login                ->  logout      /   log_err
 *      rq_logout               ->  logout      /   log_err
 *      heartbeat               ->  logout      /   log_err
 *      timer       &   timeout ->  logout      /   log_err
 *      timer                   ->  w_login
 *
 *
 *  [login]
 *      rq_key                  ->  logout      /   log_err
 *      rq_login                ->  logout      /   log_err
 *      rq_logout               ->  logout      /   send_logout
 *      heartbeat               ->  logout      /   log_err
 *      timer       &   on_time ->  login
 *      timer                   ->  logout
 *
 *
 *  [logout]
 *      rq_key                  ->  logout      /   log_err
 *      rq_login                ->  logout      /   log_err
 *      rq_logout               ->  logout      /   logout
 *      heartbeat               ->  logout      /   log_err
 *      timer                   ->  logout      /   log_err
 *
 */
use idata::cont::IVec;
use std::collections::BTreeSet;
use std::result::Result;

pub(crate) mod fsm_peg {
    use crate::parser::*;
    include!(concat!(env!("OUT_DIR"), "/fsm.rs"));
}

pub(crate) type Fsm = Vec<Status>;

#[derive(Debug)]
pub struct Status {
    pub(crate) name: String,
    pub(crate) transitions: Vec<Transition>,
}

#[derive(Debug, Clone)]
pub struct Transition {
    pub(crate) input: String,
    pub(crate) guard: Option<String>,
    pub(crate) action: Option<String>,
    pub(crate) new_status: String,
}

pub fn parse(input: &str) -> Result<(Fsm, Fsm), String> {
    match fsm_peg::fsm(input) {
        Ok(fsm) => Ok((complete_fsm(&fsm), fsm)),
        Err(e) => Err(format!("{:?}", e)),
    }
}

fn complete_fsm(fsm: &[Status]) -> Fsm {
    let allstinputs = get_all_input_names(&fsm);
    let get_full_status_in = |st: &Status, allstinputs: &BTreeSet<String>| -> Status {
        let missing_inputs = |st: &Status, allstinputs: &BTreeSet<String>| -> Vec<String> {
            let stinputs: BTreeSet<_> = st
                .transitions
                .iter()
                .filter(|t| t.input != "_")
                .map(|t| t.input.clone())
                .collect();
            let missing_inputs: Vec<String> = allstinputs
                .difference(&stinputs)
                .map(|i| (*i).clone())
                .collect();
            missing_inputs
        };
        let nt = st.transitions.iter().fold(vec![], |acc, t| {
            if t.input != "_" {
                acc.ipush(t.clone())
            } else {
                missing_inputs(st, allstinputs).iter().fold(acc, |acc, mi| {
                    acc.ipush(Transition {
                        input: mi.clone(),
                        guard: t.guard.clone(),
                        action: t.action.clone(),
                        new_status: t.new_status.clone(),
                    })
                })
            }
        });
        Status {
            name: st.name.clone(),
            transitions: nt,
        }
    };

    let fsm = fsm.iter().fold(Fsm::new(), |acc, st| {
        acc.ipush(get_full_status_in(st, &allstinputs))
    });
    println!("{:#?}", fsm);
    fsm
}

pub(crate) fn get_status_names(fsm: &[crate::parser::Status]) -> Vec<String> {
    fsm.iter().fold(vec![], |r, i| r.ipush(i.name.clone()))
}

pub(crate) fn get_all_input_names(fsm: &[crate::parser::Status]) -> BTreeSet<String> {
    fsm.iter().fold(BTreeSet::new(), |r, s| {
        s.transitions
            .iter()
            .filter(|t| t.input != "_")
            .fold(r, |mut r, t| {
                r.insert(t.input.clone());
                r
            })
    })
}

pub(crate) fn get_transchange_in_to(fsm: &[crate::parser::Status]) -> BTreeSet<(String, String)> {
    fsm.iter().fold(BTreeSet::new(), |r, s| {
        s.transitions.iter().fold(r, |mut r, t| {
            r.insert((t.input.clone(), t.new_status.clone()));
            r
        })
    })
}
