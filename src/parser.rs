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
use std::result::Result;

pub(crate) mod fsm_peg {
    use crate::parser::*;
    use idata::cont::IVec;
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

pub fn parse(input: &str) -> Result<Fsm, String> {
    match fsm_peg::fsm(input) {
        Ok(fsm) => Ok(fsm),
        Err(e) => Err(format!("{:?}", e)),
    }
}
