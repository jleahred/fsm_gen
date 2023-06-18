
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-18 13:01:00


#pragma once


#include "../types.h"
#include"../types_adapters_forward.h"

//  actions     ----------------------------------------------


namespace fsm_login {
    namespace impl {
    struct act {        //  struct instead of namespace action, trick to detect dead code  ;-)

    static void send_key(const StInit& from, const InRqKey& rq_key, const StWLogin& to);
    static void send_login(const StWLogin& from, const InRqLogin& rq_login, const StLogin& to);
    static void send_logout(const StLogin& from, const InRqLogout& rq_logout, const StLogout& to);
    static void send_logout(const StLogout& from, const InHeartbeat& heartbeat, const StTesting& to);
    static void send_logout(const StLogout& from, const InRqKey& rq_key, const StTesting& to);
    static void send_logout(const StLogout& from, const InRqLogin& rq_login, const StTesting& to);
    static void send_logout(const StLogout& from, const InRqLogout& rq_logout, const StTesting& to);
    static void send_logout(const StLogout& from, const InTimer& timer, const StTesting& to);
    static void update_hbr(const StLogin& from, const InHeartbeat& heartbeat, const StLogin& to);
    

    //  with adapters
    

    };  //  struct act
    } // namespace impl
} // namespace login

