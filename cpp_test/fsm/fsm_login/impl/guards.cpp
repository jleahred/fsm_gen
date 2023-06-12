
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 18:54:48


#include "guards.h"

#include "../types.hpp"

namespace fsm_login {
    namespace impl {

    bool is_hia(const StTesting& /*from*/, const InHeartbeat& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqKey& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqLogin& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqLogout& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InTimer& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_ho(const StTesting& /*from*/, const InRqKey& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_timeout(const StLogin& /*from*/, const InTimer& /*input*/)
    {
        //  pending
        return true;
    }
    bool is_timeout(const StWLogin& /*from*/, const InTimer& /*input*/)
    {
        //  pending
        return true;
    }
    

    } // namespace impl
} // namespace login

