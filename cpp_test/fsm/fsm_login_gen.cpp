
//  generated automatically  2020-10-12 15:13:42
//  do not modify it manually

#include "fsm_login_gen.h"

#include "fsm_login_private.hpp"

namespace login {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

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
    
    auto nw_st_info = from_in2error<st_init_t, in_heartbeat_t>(this->info, in);
    log("[init] heartbeat error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_key_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2w_login<st_init_t, in_rq_key_t>(this->info, in);
          log("[init] rq_key -> w_login", in, info, nw_st_info);
          act_send_key(this->info, in, nw_st_info);
          return std::make_shared<w_login>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_key_t>(this->info, in);
    log("[init] rq_key error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_login_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_login_t>(this->info, in);
    log("[init] rq_login error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_logout_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_logout_t>(this->info, in);
    log("[init] rq_logout error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2init<st_init_t, in_timer_t>(this->info, in);
          log("[init] timer -> init", in, info, nw_st_info);
          
          return std::make_shared<init>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_timer_t>(this->info, in);
    log("[init] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_login::input(const in_heartbeat_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_login_t, in_heartbeat_t>(this->info, in);
    log("[w_login] heartbeat error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_login::input(const in_rq_key_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_login_t, in_rq_key_t>(this->info, in);
    log("[w_login] rq_key error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_login::input(const in_rq_login_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2login<st_w_login_t, in_rq_login_t>(this->info, in);
          log("[w_login] rq_login -> login", in, info, nw_st_info);
          act_send_login(this->info, in, nw_st_info);
          return std::make_shared<login>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_login_t, in_rq_login_t>(this->info, in);
    log("[w_login] rq_login error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_login::input(const in_rq_logout_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_login_t, in_rq_logout_t>(this->info, in);
    log("[w_login] rq_logout error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_login::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2error<st_w_login_t, in_timer_t>(this->info, in);
          log("[w_login] timer(timeout) -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2w_login<st_w_login_t, in_timer_t>(this->info, in);
          log("[w_login] timer -> w_login", in, info, nw_st_info);
          
          return std::make_shared<w_login>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_login_t, in_timer_t>(this->info, in);
    log("[w_login] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState login::input(const in_heartbeat_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2login<st_login_t, in_heartbeat_t>(this->info, in);
          log("[login] heartbeat -> login", in, info, nw_st_info);
          act_update_hb(this->info, in, nw_st_info);
          return std::make_shared<login>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_login_t, in_heartbeat_t>(this->info, in);
    log("[login] heartbeat error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState login::input(const in_rq_key_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_login_t, in_rq_key_t>(this->info, in);
    log("[login] rq_key error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState login::input(const in_rq_login_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_login_t, in_rq_login_t>(this->info, in);
    log("[login] rq_login error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState login::input(const in_rq_logout_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2logout<st_login_t, in_rq_logout_t>(this->info, in);
          log("[login] rq_logout -> logout", in, info, nw_st_info);
          act_send_logout(this->info, in, nw_st_info);
          return std::make_shared<logout>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_login_t, in_rq_logout_t>(this->info, in);
    log("[login] rq_logout error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState login::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2logout<st_login_t, in_timer_t>(this->info, in);
          log("[login] timer(timeout) -> logout", in, info, nw_st_info);
          
          return std::make_shared<logout>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2login<st_login_t, in_timer_t>(this->info, in);
          log("[login] timer -> login", in, info, nw_st_info);
          
          return std::make_shared<login>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_login_t, in_timer_t>(this->info, in);
    log("[login] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState logout::input(const in_heartbeat_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_logout_t, in_heartbeat_t>(this->info, in);
    log("[logout] heartbeat error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState logout::input(const in_rq_key_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_logout_t, in_rq_key_t>(this->info, in);
    log("[logout] rq_key error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState logout::input(const in_rq_login_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_logout_t, in_rq_login_t>(this->info, in);
    log("[logout] rq_login error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState logout::input(const in_rq_logout_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_logout_t, in_rq_logout_t>(this->info, in);
    log("[logout] rq_logout error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState logout::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2logout<st_logout_t, in_timer_t>(this->info, in);
          log("[logout] timer -> logout", in, info, nw_st_info);
          
          return std::make_shared<logout>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_logout_t, in_timer_t>(this->info, in);
    log("[logout] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_heartbeat_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_error_t, in_heartbeat_t>(this->info, in);
          log("[error] heartbeat -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_heartbeat_t>(this->info, in);
    log("[error] heartbeat error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_key_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_error_t, in_rq_key_t>(this->info, in);
          log("[error] rq_key -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_key_t>(this->info, in);
    log("[error] rq_key error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_login_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_error_t, in_rq_login_t>(this->info, in);
          log("[error] rq_login -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_login_t>(this->info, in);
    log("[error] rq_login error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_logout_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_error_t, in_rq_logout_t>(this->info, in);
          log("[error] rq_logout -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_logout_t>(this->info, in);
    log("[error] rq_logout error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_error_t, in_timer_t>(this->info, in);
          log("[error] timer -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_timer_t>(this->info, in);
    log("[error] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }

} // namespace login

