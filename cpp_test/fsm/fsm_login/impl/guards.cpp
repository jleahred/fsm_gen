
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-18 13:27:21


#include "guards.h"
#include "../types_adapters.h"

namespace fsm_login {
    namespace impl {

        bool guard::is_hia(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/){
            return true;        //  pending!
        }
        bool guard::is_hia(const StTesting& /*from*/, const InRqKey& /*rq_key*/){
            return true;        //  pending!
        }
        bool guard::is_hia(const StTesting& /*from*/, const InRqLogin& /*rq_login*/){
            return true;        //  pending!
        }
        bool guard::is_hia(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/){
            return true;        //  pending!
        }
        bool guard::is_hia(const StTesting& /*from*/, const InTimer& /*timer*/){
            return true;        //  pending!
        }
        bool guard::is_ho(const StTesting& /*from*/, const InRqKey& /*rq_key*/){
            return true;        //  pending!
        }
        bool guard::is_timeout(const StLogin& /*from*/, const InTimer& /*timer*/){
            return true;        //  pending!
        }
        bool guard::is_timeout(const StWLogin& /*from*/, const InTimer& /*timer*/){
            return true;        //  pending!
        }
        
    
        //  with adapters
        
    
    } // namespace impl
} // namespace login

