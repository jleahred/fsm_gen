
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on 2020-11-23 08:56:26


#pragma once

#include "gen_fsm_login_types_forward.hpp"

namespace login {

  //  status info types

  struct st_init_t{};
  struct st_w_login_t{};
  struct st_login_t{};
  struct st_logout_t{};
  struct st_error_t{};
  


  //  input types

    struct in_rq_login_t{};
    struct in_heartbeat_t{};
    struct in_rq_key_t{};
    struct in_rq_logout_t{};
    struct in_timer_t{};
    

} // namespace login

