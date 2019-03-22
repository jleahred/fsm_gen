/*
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

#include <iostream>

#include "fsm_login.h"
//#include "fsm_login_gen.h"

int main() {
  login::Fsm login;
  login.in(login::rq_key_t{});
  //  login.in(login::rq_login_t{"key", "login"});
  //  login.in(login::rq_login_t{"key", "login"});
  return 0;
}
