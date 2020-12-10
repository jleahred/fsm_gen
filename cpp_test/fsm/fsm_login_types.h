
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on 2020-12-10 10:55:01


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

    //  provisinal code, delete it when replace the nexts usings
      struct provisinal_in_heartbeat_t{};
      struct provisinal_in_timer_t{};
      struct provisinal_in_rq_logout_t{};
      struct provisinal_in_rq_key_t{};
      struct provisinal_in_rq_login_t{};
      

    //  usings
    using in_heartbeat_t = provisinal_in_heartbeat_t;
    using in_timer_t = provisinal_in_timer_t;
    using in_rq_logout_t = provisinal_in_rq_logout_t;
    using in_rq_key_t = provisinal_in_rq_key_t;
    using in_rq_login_t = provisinal_in_rq_login_t;
    


} // namespace login

