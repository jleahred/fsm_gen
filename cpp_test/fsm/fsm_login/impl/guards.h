
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-18 13:01:00


#pragma once

#include "../types.h"
#include"../types_adapters_forward.h"

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
    

    //  with adapters
    static bool is_timeout(const adapt::guard::Tr& /*tr*/);
    

    };  //  struct guard
    } // namespace impl
} // namespace login

