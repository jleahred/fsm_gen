
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-13 20:58:55


#pragma once


#include "../types.hpp"


namespace fsm_login {
    namespace impl {
    struct act {        //  struct instead of action, trick to detect dead code  ;-)

    //  actions
    static void send_key(const StInit& from, const InRqKey& rq_key, const StWLogin& to);
    static void send_login(const StWLogin& from, const InRqLogin& rq_login, const StLogin& to);
    static void send_logout(const StLogin& from, const InRqLogout& rq_logout, const StLogout& to);
    static void update_hb(const StLogin& from, const InHeartbeat& heartbeat, const StLogin& to);
    

    };  //  struct act
    } // namespace impl
} // namespace login

