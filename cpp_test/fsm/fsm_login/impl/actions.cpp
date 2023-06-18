
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-18 13:01:00


#include "actions.h"

#include "../types_adapters.h"

namespace fsm_login {
    namespace impl {
    
        //  actions

        void act::send_key(const StInit& /*from*/, const InRqKey& /*rq_key*/, const StWLogin& /*to*/)
        {
        }
        void act::send_login(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/, const StLogin& /*to*/)
        {
        }
        void act::send_logout(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/, const StLogout& /*to*/)
        {
        }
        void act::send_logout(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/, const StTesting& /*to*/)
        {
        }
        void act::send_logout(const StLogout& /*from*/, const InRqKey& /*rq_key*/, const StTesting& /*to*/)
        {
        }
        void act::send_logout(const StLogout& /*from*/, const InRqLogin& /*rq_login*/, const StTesting& /*to*/)
        {
        }
        void act::send_logout(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/, const StTesting& /*to*/)
        {
        }
        void act::send_logout(const StLogout& /*from*/, const InTimer& /*timer*/, const StTesting& /*to*/)
        {
        }
        void act::update_hbr(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/, const StLogin& /*to*/)
        {
        }
        
    
        //  with adapters
        
    
        } // namespace impl
    } // namespace login
    
