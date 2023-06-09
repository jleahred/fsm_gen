/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "login_fsm.h"

int main() {
  login::Fsm login;
  login.process(login::in_rq_key_t{});
  //  login.in(login::rq_login_t{"key", "login"});
  login.process(login::in_rq_login_t{});
  login.process(login::in_rq_logout_t{});
  login.process(login::in_rq_logout_t{});
  return 0;
}
