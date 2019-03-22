
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_login.h"
#include "fsm_login_gen.h"

namespace login {

//  status change functions
logout_info_t Fsm::in2logout(const heartbeat_t &i) {}
logout_info_t Fsm::in2logout(const rq_key_t &i) {}
w_login_info_t Fsm::in2w_login(const rq_key_t &i) {}
login_info_t Fsm::in2login(const rq_login_t &i) {}
logout_info_t Fsm::in2logout(const rq_login_t &i) {}
logout_info_t Fsm::in2logout(const rq_logout_t &i) {}
login_info_t Fsm::in2login(const timer_t &i) {}
logout_info_t Fsm::in2logout(const timer_t &i) {}

//  guards
bool Fsm::valid(const rq_login_t &in, const w_login_info_t &st_info) {
  return true;
}
bool Fsm::on_time(const timer_t &in, const login_info_t &st_info) {
  return true;
}

} // namespace login
