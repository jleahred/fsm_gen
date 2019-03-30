
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

    
#ifndef FSM_LOGIN_H
#define FSM_LOGIN_H

#include <string>

#include "fsm_login_gen.h"

namespace login {

  //  status info types
  struct st_init_info_t{};
  struct st_w_login_info_t{};
  struct st_login_info_t{};
  struct st_logout_info_t{};


  //  input types
  struct in_heartbeat_t {};
  struct in_rq_key_t {};
  struct in_rq_login_t {};
  struct in_rq_logout_t {};
  struct in_timer_t {};



    //  log
template <typename IN, typename INIT_ST, typename END_ST>
void log(const std::string &txt_trans, const IN &, const INIT_ST &, const END_ST &) {
  std::cout << txt_trans << std::endl;
}

} // namespace login
#endif // FSM_LOGIN_H
