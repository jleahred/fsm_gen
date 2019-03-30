
//  generated automatically  2019-03-29 22:33:10
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
struct st_init_info_t;
struct st_w_login_info_t;
struct st_login_info_t;
struct st_logout_info_t;


//  in
struct in_heartbeat_t;
struct in_rq_key_t;
struct in_rq_login_t;
struct in_rq_logout_t;
struct in_timer_t;


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

  void in(const in_heartbeat_t& in);
  void in(const in_rq_key_t& in);
  void in(const in_rq_login_t& in);
  void in(const in_rq_logout_t& in);
  void in(const in_timer_t& in);




private:
  SState state;
};

//      F S M
//  -------------------

  //  ----------------------------------------------------
  //      TO FILL BY HAND
  
    //  implementation in fsm_login.cpp

  //  status change functions
  st_logout_info_t from_in2logout(const st_init_info_t& from, const in_heartbeat_t& in);
  st_w_login_info_t from_in2w_login(const st_init_info_t& from, const in_rq_key_t& in);
  st_logout_info_t from_in2logout(const st_init_info_t& from, const in_rq_login_t& in);
  st_logout_info_t from_in2logout(const st_init_info_t& from, const in_rq_logout_t& in);
  st_init_info_t from_in2init(const st_init_info_t& from, const in_timer_t& in);
  st_login_info_t from_in2login(const st_login_info_t& from, const in_heartbeat_t& in);
  st_logout_info_t from_in2logout(const st_login_info_t& from, const in_rq_key_t& in);
  st_logout_info_t from_in2logout(const st_login_info_t& from, const in_rq_login_t& in);
  st_logout_info_t from_in2logout(const st_login_info_t& from, const in_rq_logout_t& in);
  st_login_info_t from_in2login(const st_login_info_t& from, const in_timer_t& in);
  st_logout_info_t from_in2logout(const st_login_info_t& from, const in_timer_t& in);
  st_logout_info_t from_in2logout(const st_logout_info_t& from, const in_heartbeat_t& in);
  st_logout_info_t from_in2logout(const st_logout_info_t& from, const in_rq_key_t& in);
  st_logout_info_t from_in2logout(const st_logout_info_t& from, const in_rq_login_t& in);
  st_logout_info_t from_in2logout(const st_logout_info_t& from, const in_rq_logout_t& in);
  st_logout_info_t from_in2logout(const st_logout_info_t& from, const in_timer_t& in);
  st_logout_info_t from_in2logout(const st_w_login_info_t& from, const in_heartbeat_t& in);
  st_logout_info_t from_in2logout(const st_w_login_info_t& from, const in_rq_key_t& in);
  st_login_info_t from_in2login(const st_w_login_info_t& from, const in_rq_login_t& in);
  st_logout_info_t from_in2logout(const st_w_login_info_t& from, const in_rq_login_t& in);
  st_logout_info_t from_in2logout(const st_w_login_info_t& from, const in_rq_logout_t& in);
  st_logout_info_t from_in2logout(const st_w_login_info_t& from, const in_timer_t& in);
  st_w_login_info_t from_in2w_login(const st_w_login_info_t& from, const in_timer_t& in);


  //  guards to implement
  bool valid(const in_rq_login_t& in, const  st_w_login_info_t& st_info);
  bool timeout_wl(const in_timer_t& in, const  st_w_login_info_t& st_info);
  bool timeout_l(const in_timer_t& in, const  st_login_info_t& st_info);


  //  actions to implement
  void act_send_key(const st_init_info_t& st_orig, const in_rq_key_t& in, const  st_w_login_info_t& st_dest);
  void act_log_err(const st_init_info_t& st_orig, const in_heartbeat_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_init_info_t& st_orig, const in_rq_login_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_init_info_t& st_orig, const in_rq_logout_t& in, const  st_logout_info_t& st_dest);
  void act_send_login(const st_w_login_info_t& st_orig, const in_rq_login_t& in, const  st_login_info_t& st_dest);
  void act_log_err(const st_w_login_info_t& st_orig, const in_rq_login_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_w_login_info_t& st_orig, const in_timer_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_w_login_info_t& st_orig, const in_heartbeat_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_w_login_info_t& st_orig, const in_rq_key_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_w_login_info_t& st_orig, const in_rq_logout_t& in, const  st_logout_info_t& st_dest);
  void act_send_logout(const st_login_info_t& st_orig, const in_rq_logout_t& in, const  st_logout_info_t& st_dest);
  void act_update_hb(const st_login_info_t& st_orig, const in_heartbeat_t& in, const  st_login_info_t& st_dest);
  void act_log_err(const st_login_info_t& st_orig, const in_rq_key_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_login_info_t& st_orig, const in_rq_login_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_logout_info_t& st_orig, const in_heartbeat_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_logout_info_t& st_orig, const in_rq_key_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_logout_info_t& st_orig, const in_rq_login_t& in, const  st_logout_info_t& st_dest);
  void act_log_err(const st_logout_info_t& st_orig, const in_rq_logout_t& in, const  st_logout_info_t& st_dest);


template <typename IN, typename INIT_ST, typename END_ST>
void log(const std::string &txt_trans, const IN &, const INIT_ST &, const END_ST &);

  //      TO FILL BY HAND
  //  ----------------------------------------------------

} // namespace login

#endif // FSM_LOGIN_GENERATED_H

