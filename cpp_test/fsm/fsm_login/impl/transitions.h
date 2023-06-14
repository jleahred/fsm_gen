
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on 2023-06-15 00:20:20


#pragma once

// clang-format off

#include<variant>
#include"../types.h"

namespace fsm_login {
  namespace impl {
  struct trans {    //  struct insted namespace, trick to dected dead code

  //  status change functions
  static std::variant<StInit, StError> to_init(const StInit& /*from*/, const InTimer& /*timer*/);
  static std::variant<StInit, StError> to_init(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  static std::variant<StInit, StError> to_init(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StInit, StError> to_init(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  static std::variant<StInit, StError> to_init(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  static std::variant<StInit, StError> to_init(const StTesting& /*from*/, const InTimer& /*timer*/);
  static std::variant<StLogin, StError> to_login(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  static std::variant<StLogin, StError> to_login(const StLogin& /*from*/, const InTimer& /*timer*/);
  static std::variant<StLogin, StError> to_login(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  static std::variant<StLogin, StError> to_login(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StLogin, StError> to_login(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  static std::variant<StLogin, StError> to_login(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  static std::variant<StLogin, StError> to_login(const StTesting& /*from*/, const InTimer& /*timer*/);
  static std::variant<StLogin, StError> to_login(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/);
  static std::variant<StLogout, StError> to_logout(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  static std::variant<StLogout, StError> to_logout(const StLogin& /*from*/, const InTimer& /*timer*/);
  static std::variant<StLogout, StError> to_logout(const StLogout& /*from*/, const InTimer& /*timer*/);
  static std::variant<StLogout, StError> to_logout(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StTesting, StError> to_testing(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/);
  static std::variant<StTesting, StError> to_testing(const StLogout& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StTesting, StError> to_testing(const StLogout& /*from*/, const InRqLogin& /*rq_login*/);
  static std::variant<StTesting, StError> to_testing(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/);
  static std::variant<StTesting, StError> to_testing(const StLogout& /*from*/, const InTimer& /*timer*/);
  static std::variant<StTesting, StError> to_testing(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StWLogin, StError> to_w_login(const StInit& /*from*/, const InRqKey& /*rq_key*/);
  static std::variant<StWLogin, StError> to_w_login(const StWLogin& /*from*/, const InTimer& /*timer*/);
  

  //  status change functions 2 error
  static StError to_error(const StError& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StError& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StError& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StError& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StError& /*from*/, const InTimer& /*timer*/);
  static StError to_error(const StInit& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StInit& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StInit& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StInit& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StInit& /*from*/, const InTimer& /*timer*/);
  static StError to_error(const StLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StLogin& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StLogin& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StLogin& /*from*/, const InTimer& /*timer*/);
  static StError to_error(const StLogout& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StLogout& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StLogout& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StLogout& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StLogout& /*from*/, const InTimer& /*timer*/);
  static StError to_error(const StTesting& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StTesting& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StTesting& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StTesting& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StTesting& /*from*/, const InTimer& /*timer*/);
  static StError to_error(const StWLogin& /*from*/, const InHeartbeat& /*heartbeat*/);
  static StError to_error(const StWLogin& /*from*/, const InRqKey& /*rq_key*/);
  static StError to_error(const StWLogin& /*from*/, const InRqLogin& /*rq_login*/);
  static StError to_error(const StWLogin& /*from*/, const InRqLogout& /*rq_logout*/);
  static StError to_error(const StWLogin& /*from*/, const InTimer& /*timer*/);
  

  };  //  struct trans
  } // namespace impl
} // namespace login

// clang-format on

