
//  generated automatically  2019-11-10 12:36:08
//  do not modify it manually

#ifndef FSM_LOGIN_GENERATED_H
#define FSM_LOGIN_GENERATED_H

#include <iostream>
#include <memory>

#include "fsm_login_types.h"

namespace login {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
  Fsm();
  ~Fsm();

  void process(const in_heartbeat_t& in);
  void process(const in_rq_key_t& in);
  void process(const in_rq_login_t& in);
  void process(const in_rq_logout_t& in);
  void process(const in_timer_t& in);




private:
  SState state;
};

//      F S M
//  -------------------

} // namespace login

#endif // FSM_LOGIN_GENERATED_H
