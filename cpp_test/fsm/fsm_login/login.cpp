
// clang-format off

//  generated automatically  2023-06-11 23:28:39
//  do not modify it manually

#include "login.h"

#include "impl/actions.h"
#include "impl/guards.h"
#include "impl/transitions.h"

#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

namespace fsm_login {

  class BaseState {
  public:
    BaseState()  {}
    virtual ~BaseState() {}

   public:
     virtual SState input(const in_heartbeat_t& in) = 0;
     virtual SState input(const in_rq_key_t& in) = 0;
     virtual SState input(const in_rq_login_t& in) = 0;
     virtual SState input(const in_rq_logout_t& in) = 0;
     virtual SState input(const in_timer_t& in) = 0;
     
   };


  
  class init : public BaseState {
  public:
    init(const st_init_t& i) : info(i) {}
    virtual ~init(){}

  private:
    st_init_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  class w_login : public BaseState {
  public:
    w_login(const st_w_login_t& i) : info(i) {}
    virtual ~w_login(){}

  private:
    st_w_login_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  class login : public BaseState {
  public:
    login(const st_login_t& i) : info(i) {}
    virtual ~login(){}

  private:
    st_login_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  class logout : public BaseState {
  public:
    logout(const st_logout_t& i) : info(i) {}
    virtual ~logout(){}

  private:
    st_logout_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  class error : public BaseState {
  public:
    error(const st_error_t& i) : info(i) {}
    virtual ~error(){}

  private:
    st_error_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  class testing : public BaseState {
  public:
    testing(const st_testing_t& i) : info(i) {}
    virtual ~testing(){}

  private:
    st_testing_t info;

    SState input(const in_heartbeat_t& in) override;
    SState input(const in_rq_key_t& in) override;
    SState input(const in_rq_login_t& in) override;
    SState input(const in_rq_logout_t& in) override;
    SState input(const in_timer_t& in) override;
    
  };
  
  


Fsm::Fsm() : state(std::make_shared<init>(st_init_t{})) {}
Fsm::~Fsm() {}

void Fsm::process(const in_heartbeat_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_key_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_login_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_logout_t& in) { state = state ->input(in); }
void Fsm::process(const in_timer_t& in) { state = state ->input(in); }




SState init::input(const in_heartbeat_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[init] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_key_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2w_login(this->info, in);
        if(auto nw_st_info = std::get_if<st_w_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[init] rq_key -> w_login", in, info, nw_st_info);
          impl::act_send_key(this->info, in, *nw_st_info);
          
          return std::make_shared<w_login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[init] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_login_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[init] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_logout_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[init] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_timer_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[init] timer -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[init] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState w_login::input(const in_heartbeat_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[w_login] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const in_rq_key_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[w_login] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const in_rq_login_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[w_login] rq_login -> login", in, info, nw_st_info);
          impl::act_send_login(this->info, in, *nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[w_login] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const in_rq_logout_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[w_login] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const in_timer_t& in) {
  try {
      
      if(true && impl::is_timeout(info, in)){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[w_login] timer -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2w_login(this->info, in);
        if(auto nw_st_info = std::get_if<st_w_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[w_login] timer -> w_login", in, info, nw_st_info);
          
          return std::make_shared<w_login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[w_login] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState login::input(const in_heartbeat_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[login] heartbeat -> login", in, info, nw_st_info);
          impl::act_update_hb(this->info, in, *nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[login] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState login::input(const in_rq_key_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[login] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState login::input(const in_rq_login_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[login] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState login::input(const in_rq_logout_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2logout(this->info, in);
        if(auto nw_st_info = std::get_if<st_logout_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[login] rq_logout -> logout", in, info, nw_st_info);
          impl::act_send_logout(this->info, in, *nw_st_info);
          
          return std::make_shared<logout>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[login] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState login::input(const in_timer_t& in) {
  try {
      
      if(true && impl::is_timeout(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2logout(this->info, in);
        if(auto nw_st_info = std::get_if<st_logout_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[login] timer -> logout", in, info, nw_st_info);
          
          return std::make_shared<logout>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[login] timer -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[login] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState logout::input(const in_heartbeat_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] heartbeat -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[logout] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState logout::input(const in_rq_key_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] rq_key -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[logout] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState logout::input(const in_rq_login_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] rq_login -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[logout] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState logout::input(const in_rq_logout_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] rq_logout -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[logout] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState logout::input(const in_timer_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2logout(this->info, in);
        if(auto nw_st_info = std::get_if<st_logout_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] timer -> logout", in, info, nw_st_info);
          
          return std::make_shared<logout>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[logout] timer -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[logout] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState error::input(const in_heartbeat_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[error] heartbeat -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[error] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_key_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[error] rq_key -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[error] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_login_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[error] rq_login -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[error] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_logout_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[error] rq_logout -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[error] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_timer_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = impl::transition_2error(this->info, in);
        //log(en_log_level::info, "[error] timer -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[error] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState testing::input(const in_heartbeat_t& in) {
  try {
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] heartbeat -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] heartbeat -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] heartbeat -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] heartbeat -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[testing] heartbeat error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState testing::input(const in_rq_key_t& in) {
  try {
      
      if(true && impl::is_ho(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2logout(this->info, in);
        if(auto nw_st_info = std::get_if<st_logout_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> logout", in, info, nw_st_info);
          
          return std::make_shared<logout>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2testing(this->info, in);
        if(auto nw_st_info = std::get_if<st_testing_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> testing", in, info, nw_st_info);
          
          return std::make_shared<testing>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_key -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[testing] rq_key error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState testing::input(const in_rq_login_t& in) {
  try {
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_login -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_login -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_login -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_login -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[testing] rq_login error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState testing::input(const in_rq_logout_t& in) {
  try {
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_logout -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_logout -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_logout -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] rq_logout -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[testing] rq_logout error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState testing::input(const in_timer_t& in) {
  try {
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] timer -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] timer -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      
      if(true && impl::is_hia(info, in)){
        
        auto nw_st_info_or_error = impl::transition_2login(this->info, in);
        if(auto nw_st_info = std::get_if<st_login_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] timer -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = impl::transition_2init(this->info, in);
        if(auto nw_st_info = std::get_if<st_init_t>(&nw_st_info_or_error))
        {
          //log(en_log_level::info, "[testing] timer -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = impl::transition_2error(this->info, in);
  //log(en_log_level::critic, "[testing] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}



}

#pragma GCC diagnostic pop

// clang-format on
