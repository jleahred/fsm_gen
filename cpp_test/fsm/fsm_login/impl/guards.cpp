
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 21:01:03


#include "guards.h"

#include "../types.hpp"

namespace fsm_login {
    namespace impl {

    bool is_hia(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqLogin& /*rq_login*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/)
    {
        //  pending
        return true;
    }
    bool is_hia(const StTesting& /*from*/, const InTimer& /*timer*/)
    {
        //  pending
        return true;
    }
    bool is_ho(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
    {
        //  pending
        return true;
    }
    bool is_timeout(const StLogin& /*from*/, const InTimer& /*timer*/)
    {
        //  pending
        return true;
    }
    bool is_timeout(const StWLogin& /*from*/, const InTimer& /*timer*/)
    {
        //  pending
        return true;
    }
    

    } // namespace impl
} // namespace login

