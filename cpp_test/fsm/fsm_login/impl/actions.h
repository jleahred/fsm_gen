
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-15 00:20:20

#pragma once

#include "../types.h"

namespace fsm_login
{
    namespace impl
    {
        struct act
        { //  struct instead of namespace action, trick to detect dead code  ;-)

            //  actions
            static void send_key(const transf::act::Tr & /*p*/);
            static void send_login(const transf::act::Tr & /*p*/);
            static void send_logou(const transf::act::Tr & /*p*/);
            static void send_logout(const StLogout &from, const InHeartbeat &heartbeat, const StTesting &to);
            static void send_logout(const StLogout &from, const InRqKey &rq_key, const StTesting &to);
            static void send_logout(const StLogout &from, const InRqLogin &rq_login, const StTesting &to);
            static void send_logout(const StLogout &from, const InRqLogout &rq_logout, const StTesting &to);
            static void send_logout(const StLogout &from, const InTimer &timer, const StTesting &to);
            static void update_hbr(const StLogin &from, const InHeartbeat &heartbeat, const StLogin &to);

        }; //  struct act
    }      // namespace impl
} // namespace login
