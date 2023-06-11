
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2023-06-11 21:20:40


#include "transitions.h"


#include<variant>
#include"../types.hpp"

namespace fsm_login {
  namespace impl {


//  status change functions
std::variant<st_init_t, st_error_t> transition_2init(const st_init_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_init_t{};
}
std::variant<st_login_t, st_error_t> transition_2login(const st_login_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_login_t{};
}
std::variant<st_login_t, st_error_t> transition_2login(const st_login_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_login_t{};
}
std::variant<st_login_t, st_error_t> transition_2login(const st_w_login_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_login_t{};
}
std::variant<st_logout_t, st_error_t> transition_2logout(const st_login_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_logout_t{};
}
std::variant<st_logout_t, st_error_t> transition_2logout(const st_login_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_logout_t{};
}
std::variant<st_logout_t, st_error_t> transition_2logout(const st_logout_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_logout_t{};
}
std::variant<st_w_login_t, st_error_t> transition_2w_login(const st_init_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_w_login_t{};
}
std::variant<st_w_login_t, st_error_t> transition_2w_login(const st_w_login_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_w_login_t{};
}


//  status change functions 2 error
st_error_t transition_2error(const st_error_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_error_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_error_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_error_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_error_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_init_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_init_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_init_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_init_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_init_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_login_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_login_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_login_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_login_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_login_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_logout_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_logout_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_logout_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_logout_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_logout_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_w_login_t& /*from*/, const in_heartbeat_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_w_login_t& /*from*/, const in_rq_key_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_w_login_t& /*from*/, const in_rq_login_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_w_login_t& /*from*/, const in_rq_logout_t& /*input*/)
{
  //  pending
  return st_error_t{};
}
st_error_t transition_2error(const st_w_login_t& /*from*/, const in_timer_t& /*input*/)
{
  //  pending
  return st_error_t{};
}



  } // namespace impl
} // namespace login

// clang-format on

    
