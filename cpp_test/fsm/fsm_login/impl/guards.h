
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 18:54:48


#pragma once

#include "../types.hpp"


namespace fsm_login {
    namespace impl {
  
    bool is_hia(const StTesting& /*from*/, const InHeartbeat& /*input*/);
    bool is_hia(const StTesting& /*from*/, const InRqKey& /*input*/);
    bool is_hia(const StTesting& /*from*/, const InRqLogin& /*input*/);
    bool is_hia(const StTesting& /*from*/, const InRqLogout& /*input*/);
    bool is_hia(const StTesting& /*from*/, const InTimer& /*input*/);
    bool is_ho(const StTesting& /*from*/, const InRqKey& /*input*/);
    bool is_timeout(const StLogin& /*from*/, const InTimer& /*input*/);
    bool is_timeout(const StWLogin& /*from*/, const InTimer& /*input*/);
    

    } // namespace impl
} // namespace login

