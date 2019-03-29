
//  generated automatically  2019-03-29 19:38:10
//  do not modify it manually

#ifndef FSM_LOGIN_GENERATED_H
#define FSM_LOGIN_GENERATED_H

#include <iostream>
#include <memory>

namespace login {

//  ----------------------------------------------------
//      TO FILL BY HAND
//          They have to be copiable
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


//      TO FILL BY HAND
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




private:
  SState state;
};

//      F S M
//  -------------------

  //  ----------------------------------------------------
  //      TO FILL BY HAND
  
    //  implementation in fsm_login.cpp

  //  status change functions
  logout_info_t from_in2logout(const init_info_t& from, const heartbeat_t& in);
  w_login_info_t from_in2w_login(const init_info_t& from, const rq_key_t& in);
  logout_info_t from_in2logout(const init_info_t& from, const rq_login_t& in);
  logout_info_t from_in2logout(const init_info_t& from, const rq_logout_t& in);
  init_info_t from_in2init(const init_info_t& from, const timer_t& in);
  login_info_t from_in2login(const login_info_t& from, const heartbeat_t& in);
  logout_info_t from_in2logout(const login_info_t& from, const rq_key_t& in);
  logout_info_t from_in2logout(const login_info_t& from, const rq_login_t& in);
  logout_info_t from_in2logout(const login_info_t& from, const rq_logout_t& in);
  login_info_t from_in2login(const login_info_t& from, const timer_t& in);
  logout_info_t from_in2logout(const login_info_t& from, const timer_t& in);
  logout_info_t from_in2logout(const logout_info_t& from, const heartbeat_t& in);
  logout_info_t from_in2logout(const logout_info_t& from, const rq_key_t& in);
  logout_info_t from_in2logout(const logout_info_t& from, const rq_login_t& in);
  logout_info_t from_in2logout(const logout_info_t& from, const rq_logout_t& in);
  logout_info_t from_in2logout(const logout_info_t& from, const timer_t& in);
  logout_info_t from_in2logout(const w_login_info_t& from, const heartbeat_t& in);
  logout_info_t from_in2logout(const w_login_info_t& from, const rq_key_t& in);
  login_info_t from_in2login(const w_login_info_t& from, const rq_login_t& in);
  logout_info_t from_in2logout(const w_login_info_t& from, const rq_login_t& in);
  logout_info_t from_in2logout(const w_login_info_t& from, const rq_logout_t& in);
  logout_info_t from_in2logout(const w_login_info_t& from, const timer_t& in);
  w_login_info_t from_in2w_login(const w_login_info_t& from, const timer_t& in);


  //  guards to implement
  bool valid(const rq_login_t& in, const  w_login_info_t& st_info);
  bool timeout_wl(const timer_t& in, const  w_login_info_t& st_info);
  bool timeout_l(const timer_t& in, const  login_info_t& st_info);


template <typename IN, typename INIT_ST, typename END_ST>
void log(const std::string &txt_trans, const IN &, const INIT_ST &, const END_ST &);

  //      TO FILL BY HAND
  //  ----------------------------------------------------

} // namespace login

#endif // FSM_LOGIN_GENERATED_H

