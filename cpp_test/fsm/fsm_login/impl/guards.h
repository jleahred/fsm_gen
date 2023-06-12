
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 21:01:03


#pragma once

#include "../types.hpp"


namespace fsm_login {
    namespace impl {
  
    bool is_hia(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
    bool is_hia(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
    bool is_hia(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
    bool is_hia(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
    bool is_hia(const StTesting& /*from*/, const InTimer& /*timer*/);
    bool is_ho(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
    bool is_timeout(const StLogin& /*from*/, const InTimer& /*timer*/);
    bool is_timeout(const StWLogin& /*from*/, const InTimer& /*timer*/);
    

    } // namespace impl
} // namespace login

