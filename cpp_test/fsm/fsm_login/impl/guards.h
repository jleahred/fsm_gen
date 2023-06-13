
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-13 20:58:55


#pragma once

#include "../types.hpp"


namespace fsm_login {
    namespace impl {
    struct guard {      //  struct instead of namespace, trick to detect dead code
  
    static bool is_hia(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
    static bool is_hia(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
    static bool is_hia(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
    static bool is_hia(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
    static bool is_hia(const StTesting& /*from*/, const InTimer& /*timer*/);
    static bool is_ho(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
    static bool is_timeout(const StLogin& /*from*/, const InTimer& /*timer*/);
    static bool is_timeout(const StWLogin& /*from*/, const InTimer& /*timer*/);
    

    };  //  struct guard
    } // namespace impl
} // namespace login

