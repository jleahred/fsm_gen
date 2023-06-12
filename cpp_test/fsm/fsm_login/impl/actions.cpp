
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 21:01:03


#include "actions.h"

#include "../types.hpp"


namespace fsm_login {
    namespace impl {

    //  actions
    void act_send_key(const StInit& /*from*/, const InRqKey& /*rq_key*/, const StWLogin& /*to*/)
    {
    }
    void act_send_login(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/, const StLogin& /*to*/)
    {
    }
    void act_send_logout(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/, const StLogout& /*to*/)
    {
    }
    void act_update_hb(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/, const StLogin& /*to*/)
    {
    }
    

    } // namespace impl
} // namespace login

