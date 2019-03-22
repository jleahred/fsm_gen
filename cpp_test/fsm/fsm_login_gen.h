
//  generated automatically  2019-03-22 11:03:43
//  do not modify it manually

#ifndef FSM_FSM_LOGIN_GENERATED_H
#define FSM_FSM_LOGIN_GENERATED_H

#include <iostream>
#include <memory>

namespace login {

//  ----------------------------------------------------
//      M A N U A L

//  declaration on fsm_login.h
//  forward_status_info
struct init_info_t;
struct w_login_info_t;
struct login_info_t;
struct logout_info_t;


//  in
struct heartbeat_t;
struct rq_key_t;
struct rq_login_t;
struct rq_logout_t;
struct timer_t;


//      M A N U A L
//  ----------------------------------------------------

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
  Fsm();
  ~Fsm();

  void in(const heartbeat_t& in);
  void in(const rq_key_t& in);
  void in(const rq_login_t& in);
  void in(const rq_logout_t& in);
  void in(const timer_t& in);



  //  ----------------------------------------------------
  //      M A N U A L
  
  //  implementation in fsm_login.cpp

  //  status change functions
    logout_info_t in2logout(const heartbeat_t& i);
  logout_info_t in2logout(const rq_key_t& i);
  w_login_info_t in2w_login(const rq_key_t& i);
  login_info_t in2login(const rq_login_t& i);
  logout_info_t in2logout(const rq_login_t& i);
  logout_info_t in2logout(const rq_logout_t& i);
  login_info_t in2login(const timer_t& i);
  logout_info_t in2logout(const timer_t& i);


  //  guards to implement
    bool valid(const rq_login_t& in, const  w_login_info_t& st_info);
  bool on_time(const timer_t& in, const  login_info_t& st_info);


  //      M A N U A L
  //  ----------------------------------------------------

private:
  SState state;
};

} // namespace login

#endif // FSM_LOGIN_GENERATED_H

