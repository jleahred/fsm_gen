
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on 2023-06-11 21:20:40


#pragma once


// #include "types_forward.h"

namespace fsm_login {

  //  status info types

  struct st_init_t{};
  struct st_w_login_t{};
  struct st_login_t{};
  struct st_logout_t{};
  struct st_error_t{};
  


  //  input types

    //  provisinal code, delete it when replace the nexts usings
      struct provisinal_in_heartbeat_t{};
      struct provisinal_in_rq_login_t{};
      struct provisinal_in_rq_key_t{};
      struct provisinal_in_timer_t{};
      struct provisinal_in_rq_logout_t{};
      

    //  usings
    using in_heartbeat_t = provisinal_in_heartbeat_t;
    using in_rq_login_t = provisinal_in_rq_login_t;
    using in_rq_key_t = provisinal_in_rq_key_t;
    using in_timer_t = provisinal_in_timer_t;
    using in_rq_logout_t = provisinal_in_rq_logout_t;
    


} // namespace login

