
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-11 21:20:40


#include "actions.h"

#include "../types.hpp"


namespace fsm_login {
    namespace impl {

    //  actions
    void act_send_logout(const st_login_t& /*from*/, const in_rq_logout_t& /*input*/, const st_logout_t& /*to*/)
    {
    }
    void act_send_login(const st_w_login_t& /*from*/, const in_rq_login_t& /*input*/, const st_login_t& /*to*/)
    {
    }
    void act_send_key(const st_init_t& /*from*/, const in_rq_key_t& /*input*/, const st_w_login_t& /*to*/)
    {
    }
    void act_update_hb(const st_login_t& /*from*/, const in_heartbeat_t& /*input*/, const st_login_t& /*to*/)
    {
    }
    

    } // namespace impl
} // namespace login

