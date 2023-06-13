
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-14 00:06:31


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

