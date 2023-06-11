
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-11 23:28:39


#pragma once

#include "../types.hpp"


namespace fsm_login {
    namespace impl {
  
    bool is_hia(const st_testing_t& /*from*/, const in_heartbeat_t& /*input*/);
    bool is_hia(const st_testing_t& /*from*/, const in_rq_key_t& /*input*/);
    bool is_hia(const st_testing_t& /*from*/, const in_rq_login_t& /*input*/);
    bool is_hia(const st_testing_t& /*from*/, const in_rq_logout_t& /*input*/);
    bool is_hia(const st_testing_t& /*from*/, const in_timer_t& /*input*/);
    bool is_ho(const st_testing_t& /*from*/, const in_rq_key_t& /*input*/);
    bool is_timeout(const st_login_t& /*from*/, const in_timer_t& /*input*/);
    bool is_timeout(const st_w_login_t& /*from*/, const in_timer_t& /*input*/);
    

    } // namespace impl
} // namespace login

