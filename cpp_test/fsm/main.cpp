/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "fsm_login/login.h"

int main() {
  fsm_login::Fsm login;
  login.process(fsm_login::InRqKey{});
  //  login.in(login::rq_login_t{"key", "login"});
  login.process(fsm_login::InRqLogin{});
  login.process(fsm_login::InRqLogout{});
  login.process(fsm_login::InRqLogout{});
  return 0;
}
