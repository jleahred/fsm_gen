
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 18:54:48


#include "transitions.h"


#include<variant>
#include"../types.hpp"

namespace fsm_login {
  namespace impl {


//  status change functions
std::variant<StInit, StError> transition_2init(const StInit& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StInit{};
}
std::variant<StLogin, StError> transition_2login(const StLogin& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StLogin& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogin, StError> transition_2login(const StWLogin& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StLogin{};
}
std::variant<StLogout, StError> transition_2logout(const StLogin& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> transition_2logout(const StLogin& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> transition_2logout(const StLogout& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StLogout{};
}
std::variant<StLogout, StError> transition_2logout(const StTesting& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StLogout{};
}
std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StTesting, StError> transition_2testing(const StTesting& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StTesting{};
}
std::variant<StWLogin, StError> transition_2w_login(const StInit& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StWLogin{};
}
std::variant<StWLogin, StError> transition_2w_login(const StWLogin& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StWLogin{};
}


//  status change functions 2 error
StError transition_2error(const StError& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StError& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StError& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StError& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StError& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StInit& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StInit& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StInit& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StInit& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StInit& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogin& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogin& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogin& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogin& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogin& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogout& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogout& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogout& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogout& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StLogout& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StTesting& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StTesting& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StTesting& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StTesting& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StTesting& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StWLogin& /*from*/, const InHeartbeat& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StWLogin& /*from*/, const InRqKey& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StWLogin& /*from*/, const InRqLogin& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StWLogin& /*from*/, const InRqLogout& /*input*/)
{
  //  pending
  return StError{};
}
StError transition_2error(const StWLogin& /*from*/, const InTimer& /*input*/)
{
  //  pending
  return StError{};
}



  } // namespace impl
} // namespace login

// clang-format on

    
