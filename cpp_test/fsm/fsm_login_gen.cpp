
//  generated automatically  2019-03-29 22:33:10
//  do not modify it manually

#include "fsm_login_gen.h"
#include "fsm_login.h"

namespace login {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

public:
  virtual SState in(const in_heartbeat_t& in) = 0;
  virtual SState in(const in_rq_key_t& in) = 0;
  virtual SState in(const in_rq_login_t& in) = 0;
  virtual SState in(const in_rq_logout_t& in) = 0;
  virtual SState in(const in_timer_t& in) = 0;

};


class init : public BaseState {
public:
    init(const st_init_info_t& i) : info(i) {}
    virtual ~init(){}

private:
    st_init_info_t info;

  SState in(const in_heartbeat_t& in) override;
  SState in(const in_rq_key_t& in) override;
  SState in(const in_rq_login_t& in) override;
  SState in(const in_rq_logout_t& in) override;
  SState in(const in_timer_t& in) override;

};

class w_login : public BaseState {
public:
    w_login(const st_w_login_info_t& i) : info(i) {}
    virtual ~w_login(){}

private:
    st_w_login_info_t info;

  SState in(const in_heartbeat_t& in) override;
  SState in(const in_rq_key_t& in) override;
  SState in(const in_rq_login_t& in) override;
  SState in(const in_rq_logout_t& in) override;
  SState in(const in_timer_t& in) override;

};

class login : public BaseState {
public:
    login(const st_login_info_t& i) : info(i) {}
    virtual ~login(){}

private:
    st_login_info_t info;

  SState in(const in_heartbeat_t& in) override;
  SState in(const in_rq_key_t& in) override;
  SState in(const in_rq_login_t& in) override;
  SState in(const in_rq_logout_t& in) override;
  SState in(const in_timer_t& in) override;

};

class logout : public BaseState {
public:
    logout(const st_logout_info_t& i) : info(i) {}
    virtual ~logout(){}

private:
    st_logout_info_t info;

  SState in(const in_heartbeat_t& in) override;
  SState in(const in_rq_key_t& in) override;
  SState in(const in_rq_login_t& in) override;
  SState in(const in_rq_logout_t& in) override;
  SState in(const in_timer_t& in) override;

};



Fsm::Fsm() : state(std::make_shared<init>(st_init_info_t{})) {}
Fsm::~Fsm() {}

void Fsm::in(const in_heartbeat_t& in) { state = state ->in(in); }
void Fsm::in(const in_rq_key_t& in) { state = state ->in(in); }
void Fsm::in(const in_rq_login_t& in) { state = state ->in(in); }
void Fsm::in(const in_rq_logout_t& in) { state = state ->in(in); }
void Fsm::in(const in_timer_t& in) { state = state ->in(in); }



  SState init::in(const in_heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[init] heartbeat -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const in_rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2w_login(this->info, in);
        log("[init] rq_key -> w_login", in, info, nw_st_info);
        act_send_key(this->info, in, nw_st_info);
        return std::make_shared<w_login>(nw_st_info);

    }              
}
    
  SState init::in(const in_rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[init] rq_login -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const in_rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[init] rq_logout -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const in_timer_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2init(this->info, in);
        log("[init] timer -> init", in, info, nw_st_info);
                return std::make_shared<init>(nw_st_info);

    }              
}
    
  SState w_login::in(const in_heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[w_login] heartbeat -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const in_rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[w_login] rq_key -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const in_rq_login_t& in) {
    if(false) {;
    } else if(valid(in, info)) {
        auto nw_st_info = from_in2login(this->info, in);
        log("[w_login] rq_login(valid) -> login", in, info, nw_st_info);
        act_send_login(this->info, in, nw_st_info);
        return std::make_shared<login>(nw_st_info);
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[w_login] rq_login -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const in_rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[w_login] rq_logout -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const in_timer_t& in) {
    if(false) {;
    } else if(timeout_wl(in, info)) {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[w_login] timer(timeout_wl) -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);
    } else {
        auto nw_st_info = from_in2w_login(this->info, in);
        log("[w_login] timer -> w_login", in, info, nw_st_info);
                return std::make_shared<w_login>(nw_st_info);

    }              
}
    
  SState login::in(const in_heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2login(this->info, in);
        log("[login] heartbeat -> login", in, info, nw_st_info);
        act_update_hb(this->info, in, nw_st_info);
        return std::make_shared<login>(nw_st_info);

    }              
}
    
  SState login::in(const in_rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[login] rq_key -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const in_rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[login] rq_login -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const in_rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[login] rq_logout -> logout", in, info, nw_st_info);
        act_send_logout(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const in_timer_t& in) {
    if(false) {;
    } else if(timeout_l(in, info)) {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[login] timer(timeout_l) -> logout", in, info, nw_st_info);
                return std::make_shared<logout>(nw_st_info);
    } else {
        auto nw_st_info = from_in2login(this->info, in);
        log("[login] timer -> login", in, info, nw_st_info);
                return std::make_shared<login>(nw_st_info);

    }              
}
    
  SState logout::in(const in_heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[logout] heartbeat -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const in_rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[logout] rq_key -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const in_rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[logout] rq_login -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const in_rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[logout] rq_logout -> logout", in, info, nw_st_info);
        act_log_err(this->info, in, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const in_timer_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = from_in2logout(this->info, in);
        log("[logout] timer -> logout", in, info, nw_st_info);
                return std::make_shared<logout>(nw_st_info);

    }              
}
    

} // namespace login

