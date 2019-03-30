/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "fsm_login_gen.h"

int main() {
  login::Fsm login;
  login.in(login::in_rq_key_t{});
  //  login.in(login::rq_login_t{"key", "login"});
  login.in(login::in_rq_login_t{});
  login.in(login::in_rq_logout_t{});
  login.in(login::in_rq_logout_t{});
  return 0;
}
