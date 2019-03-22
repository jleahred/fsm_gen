
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

    
#ifndef FSM_LOGIN_H
#define FSM_LOGIN_H

#include <string>

#include "fsm_login_gen.h"

namespace login {

  //  status info types
  struct init_info_t{};
  struct w_login_info_t{};
  struct login_info_t{};
  struct logout_info_t{};


  //  input types
  struct heartbeat_t {};
  struct rq_key_t {};
  struct rq_login_t {};
  struct rq_logout_t {};
  struct timer_t {};


} // namespace login
#endif // FSM_LOGIN_H
