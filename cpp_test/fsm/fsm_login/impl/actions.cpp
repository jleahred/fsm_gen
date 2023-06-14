
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-15 00:20:20


#include "actions.h"

#include "../types.h"


namespace fsm_login {
    namespace impl {
    
        //  actions
        void act::send_key(const transf::act::Tr& /*p*/)
        {
        }
        void act::send_login(const transf::act::Tr& /*p*/)
        {
        }
        void act::send_logou(const transf::act::Tr& /*p*/)
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
        
    
        } // namespace impl
    } // namespace login
    
