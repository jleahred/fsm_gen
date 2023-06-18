
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-18 13:27:21


#include "transitions.h"
#include "../types_adapters.h"

#include<variant>

namespace fsm_login {
  namespace impl {


//  status change functions
std::variant<StInit, StError> trans::to_init(const StInit& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> trans::to_init(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> trans::to_init(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> trans::to_init(const StTesting& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> trans::to_init(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> trans::to_init(const StTesting& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StInit{};
}
std::variant<StLogin, StError> trans::to_login(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StLogin& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StTesting& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StTesting& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> trans::to_login(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogout, StError> trans::to_logout(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> trans::to_logout(const StLogin& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> trans::to_logout(const StLogout& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> trans::to_logout(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StLogout{};
}
std::variant<StTesting, StError> trans::to_testing(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> trans::to_testing(const StLogout& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> trans::to_testing(const StLogout& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> trans::to_testing(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> trans::to_testing(const StLogout& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> trans::to_testing(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StTesting{};
}
std::variant<StWLogin, StError> trans::to_w_login(const StInit& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StWLogin{};
}
std::variant<StWLogin, StError> trans::to_w_login(const StWLogin& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StWLogin{};
}


//  status change functions 2 error
StError trans::to_error(const StError& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StError& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StError& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StError& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StError& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StInit& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StInit& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StInit& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StInit& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StInit& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogin& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogin& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogin& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogout& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogout& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StLogout& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StTesting& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StTesting& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StTesting& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StWLogin& /*from*/, const InHeartbeat& /*heartbeat*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StWLogin& /*from*/, const InRqKey& /*rq_key*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StWLogin& /*from*/, const InRqLogout& /*rq_logout*/)
{
  //  pending
  return StError{};
}
StError trans::to_error(const StWLogin& /*from*/, const InTimer& /*timer*/)
{
  //  pending
  return StError{};
}



  } // namespace impl
} // namespace login

// clang-format on

    
