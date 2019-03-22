/*  Example:
 *
 *  [init]
 *      rq_key                  -   send_key        ->  w_login
 *      rq_login                -   log_err         ->  logout
 *      rq_logout               -   log_err         ->  logout
 *      heartbeat               -   log_err         ->  logout
 *      timer                   -   log_err         ->  logout
 *
 *
 *  [w_login]
 *      rq_key                  -   log_err         ->  logout
 *      rq_login    &   valid   -   send_login      ->  login
 *      rq_login                -   log_err         ->  logout
 *      rq_logout               -   log_err         ->  logout
 *      heartbeat               -   log_err         ->  logout
 *      timer                   -                   ->  logout
 *
 *
 *  [login]
 *      rq_key                  -   log_err         ->  logout
 *      rq_login                -   log_err         ->  logout
 *      rq_logout               -   send_logout     ->  logout
 *      heartbeat               -   log_err         ->  logout
 *      timer       &   on_time -                   ->  login
 *      timer                   -                   ->  logout
 *
 *
 *  [logout]
 *      rq_key                  -   log_err         ->  logout
 *      rq_login                -   log_err         ->  logout
 *      rq_logout               -   logout          ->  logout
 *      heartbeat               -   log_err         ->  logout
 *      timer                   -   log_err         ->  logout
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
