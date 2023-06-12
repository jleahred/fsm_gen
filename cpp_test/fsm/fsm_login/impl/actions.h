
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-12 18:54:48


#pragma once


#include "../types.hpp"


namespace fsm_login {
    namespace impl {

    //  actions
    void act_send_key(const StInit& /*from*/, const InRqKey& /*input*/, const StWLogin& /*to*/);
    void act_send_login(const StWLogin& /*from*/, const InRqLogin& /*input*/, const StLogin& /*to*/);
    void act_send_logout(const StLogin& /*from*/, const InRqLogout& /*input*/, const StLogout& /*to*/);
    void act_update_hb(const StLogin& /*from*/, const InHeartbeat& /*input*/, const StLogin& /*to*/);
    

    } // namespace impl
} // namespace login

