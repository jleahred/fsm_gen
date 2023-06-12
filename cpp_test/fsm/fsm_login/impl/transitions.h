
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-12 21:01:03


#pragma once

// clang-format off

#include<variant>
#include"../types.hpp"

namespace fsm_login {
  namespace impl {


  //  status change functions
  std::variant<StInit, StError> transition_2init(const StInit& /*from*/, const InTimer& /*timer*/);
  std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  std::variant<StInit, StError> transition_2init(const StTesting& /*from*/, const InTimer& /*timer*/);
  std::variant<StLogin, StError> transition_2login(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  std::variant<StLogin, StError> transition_2login(const StLogin& /*from*/, const InTimer& /*timer*/);
  std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  std::variant<StLogin, StError> transition_2login(const StTesting& /*from*/, const InTimer& /*timer*/);
  std::variant<StLogin, StError> transition_2login(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/);
  std::variant<StLogout, StError> transition_2logout(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  std::variant<StLogout, StError> transition_2logout(const StLogin& /*from*/, const InTimer& /*timer*/);
  std::variant<StLogout, StError> transition_2logout(const StLogout& /*from*/, const InTimer& /*timer*/);
  std::variant<StLogout, StError> transition_2logout(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/);
  std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqLogin& /*rq_login*/);
  std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/);
  std::variant<StTesting, StError> transition_2testing(const StLogout& /*from*/, const InTimer& /*timer*/);
  std::variant<StTesting, StError> transition_2testing(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StWLogin, StError> transition_2w_login(const StInit& /*from*/, const InRqKey& /*rq_key*/);
  std::variant<StWLogin, StError> transition_2w_login(const StWLogin& /*from*/, const InTimer& /*timer*/);
  

  //  status change functions 2 error
  StError transition_2error(const StError& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StError& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StError& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StError& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StError& /*from*/, const InTimer& /*timer*/);
  StError transition_2error(const StInit& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StInit& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StInit& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StInit& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StInit& /*from*/, const InTimer& /*timer*/);
  StError transition_2error(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StLogin& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StLogin& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StLogin& /*from*/, const InTimer& /*timer*/);
  StError transition_2error(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StLogout& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StLogout& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StLogout& /*from*/, const InTimer& /*timer*/);
  StError transition_2error(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StTesting& /*from*/, const InTimer& /*timer*/);
  StError transition_2error(const StWLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  StError transition_2error(const StWLogin& /*from*/, const InRqKey& /*rq_key*/);
  StError transition_2error(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/);
  StError transition_2error(const StWLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  StError transition_2error(const StWLogin& /*from*/, const InTimer& /*timer*/);
  


  } // namespace impl
} // namespace login

// clang-format on

