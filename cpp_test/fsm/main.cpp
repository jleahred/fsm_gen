/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "fsm_login/login.h"

int main() {
  fsm_login::Fsm login;
  login.process(fsm_login::in_rq_key_t{});
  //  login.in(login::rq_login_t{"key", "login"});
  login.process(fsm_login::in_rq_login_t{});
  login.process(fsm_login::in_rq_logout_t{});
  login.process(fsm_login::in_rq_logout_t{});
  return 0;
}
