
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-14 00:06:31


#pragma once


#include "../types.hpp"


namespace fsm_login {
    namespace impl {
    struct act {        //  struct instead of action, trick to detect dead code  ;-)

    //  actions
    static void send_key(const StWLogin& to);
    static void send_login(const StLogin& to);
    static void send_logout(const StLogout& to);
    static void send_logout(const StTesting& to);
    static void update_hb(const StLogin& to);
    

    };  //  struct act
    } // namespace impl
} // namespace login

