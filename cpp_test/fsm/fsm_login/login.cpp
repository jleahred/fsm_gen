
// clang-format off

//  generated automatically  2023-06-18 13:01:00
//  do not modify it manually

#include "login.h"

#include "impl/actions.h"
#include "impl/guards.h"
#include "impl/transitions.h"
#include "types_adapters.h"

#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

namespace fsm_login {

class BaseState {
public:
  BaseState()  {}
  virtual ~BaseState() {}

 public:
   virtual SState input(const InHeartbeat& in) = 0;
   virtual SState input(const InRqKey& in) = 0;
   virtual SState input(const InRqLogin& in) = 0;
   virtual SState input(const InRqLogout& in) = 0;
   virtual SState input(const InTimer& in) = 0;
   
 };



class init : public BaseState {
public:
  init(const StInit& i) : info(i) {}
  virtual ~init(){}

private:
  StInit info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};

class w_login : public BaseState {
public:
  w_login(const StWLogin& i) : info(i) {}
  virtual ~w_login(){}

private:
  StWLogin info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};

class login : public BaseState {
public:
  login(const StLogin& i) : info(i) {}
  virtual ~login(){}

private:
  StLogin info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};

class logout : public BaseState {
public:
  logout(const StLogout& i) : info(i) {}
  virtual ~logout(){}

private:
  StLogout info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};

class error : public BaseState {
public:
  error(const StError& i) : info(i) {}
  virtual ~error(){}

private:
  StError info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};

class testing : public BaseState {
public:
  testing(const StTesting& i) : info(i) {}
  virtual ~testing(){}

private:
  StTesting info;

  SState input(const InHeartbeat& in) override;
  SState input(const InRqKey& in) override;
  SState input(const InRqLogin& in) override;
  SState input(const InRqLogout& in) override;
  SState input(const InTimer& in) override;
  
};




Fsm::Fsm() : state(std::make_shared<init>(StInit{})) {}
Fsm::~Fsm() {}

void Fsm::process(const InHeartbeat& in) { state = state ->input(in); }
void Fsm::process(const InRqKey& in) { state = state ->input(in); }
void Fsm::process(const InRqLogin& in) { state = state ->input(in); }
void Fsm::process(const InRqLogout& in) { state = state ->input(in); }
void Fsm::process(const InTimer& in) { state = state ->input(in); }




SState init::input(const InHeartbeat& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[init] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState init::input(const InRqKey& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_w_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StWLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[init] rq_key -> w_login", in, info, nw_st_info);
        impl::act::send_key(this->info, in, *nw_st_info);
        return std::make_shared<w_login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[init] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState init::input(const InRqLogin& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[init] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState init::input(const InRqLogout& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[init] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState init::input(const InTimer& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[init] timer -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[init] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}

SState w_login::input(const InHeartbeat& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[w_login] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const InRqKey& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[w_login] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const InRqLogin& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[w_login] rq_login -> login", in, info, nw_st_info);
        impl::act::send_login(this->info, in, *nw_st_info);
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[w_login] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const InRqLogout& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[w_login] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState w_login::input(const InTimer& in) {
try {
    
    if(true 
      && impl::guard::is_timeout(adapt::guard::Tr{info, in})
      ){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[w_login] timer -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_w_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StWLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[w_login] timer -> w_login", in, info, nw_st_info);
        
        return std::make_shared<w_login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[w_login] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}

SState login::input(const InHeartbeat& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[login] heartbeat -> login", in, info, nw_st_info);
        impl::act::update_hbr(this->info, in, *nw_st_info);
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[login] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState login::input(const InRqKey& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[login] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState login::input(const InRqLogin& in) {
try {
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[login] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState login::input(const InRqLogout& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_logout(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogout>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[login] rq_logout -> logout", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<logout>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[login] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState login::input(const InTimer& in) {
try {
    
    if(true 
      && impl::guard::is_timeout(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_logout(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogout>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[login] timer -> logout", in, info, nw_st_info);
        
        return std::make_shared<logout>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[login] timer -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[login] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}

SState logout::input(const InHeartbeat& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] heartbeat -> testing", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[logout] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState logout::input(const InRqKey& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] rq_key -> testing", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[logout] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState logout::input(const InRqLogin& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] rq_login -> testing", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[logout] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState logout::input(const InRqLogout& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] rq_logout -> testing", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[logout] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState logout::input(const InTimer& in) {
try {
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_logout(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogout>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] timer -> logout", in, info, nw_st_info);
        
        return std::make_shared<logout>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[logout] timer -> testing", in, info, nw_st_info);
        impl::act::send_logout(this->info, in, *nw_st_info);
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[logout] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}

SState error::input(const InHeartbeat& in) {
try {
    
    if(true){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[error] heartbeat -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[error] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState error::input(const InRqKey& in) {
try {
    
    if(true){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[error] rq_key -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[error] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState error::input(const InRqLogin& in) {
try {
    
    if(true){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[error] rq_login -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[error] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState error::input(const InRqLogout& in) {
try {
    
    if(true){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[error] rq_logout -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[error] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState error::input(const InTimer& in) {
try {
    
    if(true){
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[error] timer -> error", in, info, nw_st_info);
      
      return std::make_shared<error>(nw_st_info);
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[error] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}

SState testing::input(const InHeartbeat& in) {
try {
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] heartbeat -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] heartbeat -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] heartbeat -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] heartbeat -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[testing] heartbeat error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState testing::input(const InRqKey& in) {
try {
    
    if(true 
      && impl::guard::is_ho(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_logout(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogout>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> logout", in, info, nw_st_info);
        
        return std::make_shared<logout>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_testing(this->info, in);
      
      if(auto nw_st_info = std::get_if<StTesting>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> testing", in, info, nw_st_info);
        
        return std::make_shared<testing>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_key -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[testing] rq_key error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState testing::input(const InRqLogin& in) {
try {
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_login -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_login -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_login -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_login -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[testing] rq_login error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState testing::input(const InRqLogout& in) {
try {
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_logout -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_logout -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_logout -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] rq_logout -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[testing] rq_logout error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
SState testing::input(const InTimer& in) {
try {
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] timer -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] timer -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    
    if(true 
      && impl::guard::is_hia(info, in)
      ){
      
      
      auto nw_st_info_or_error = impl::trans::to_login(this->info, in);
      
      if(auto nw_st_info = std::get_if<StLogin>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] timer -> login", in, info, nw_st_info);
        
        return std::make_shared<login>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
    if(true){
      
      
      auto nw_st_info_or_error = impl::trans::to_init(this->info, in);
      
      if(auto nw_st_info = std::get_if<StInit>(&nw_st_info_or_error))
      {
      //log(en_log_level::info, "[testing] timer -> init", in, info, nw_st_info);
        
        return std::make_shared<init>(*nw_st_info);
      
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      
    }
    
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[testing] timer error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}



}

#pragma GCC diagnostic pop

// clang-format on
