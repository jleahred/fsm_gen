
//  generated automatically  2019-03-23 23:14:19
//  do not modify it manually

#include "fsm_login_gen.h"
#include "fsm_login.h"

namespace login {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

public:
  virtual SState in(const heartbeat_t& in) = 0;
  virtual SState in(const rq_key_t& in) = 0;
  virtual SState in(const rq_login_t& in) = 0;
  virtual SState in(const rq_logout_t& in) = 0;
  virtual SState in(const timer_t& in) = 0;

};


class init : public BaseState {
public:
    init(const init_info_t& i) : info(i) {}
    virtual ~init(){}

private:
    init_info_t info;

  SState in(const heartbeat_t& in) override;
  SState in(const rq_key_t& in) override;
  SState in(const rq_login_t& in) override;
  SState in(const rq_logout_t& in) override;
  SState in(const timer_t& in) override;

};

class w_login : public BaseState {
public:
    w_login(const w_login_info_t& i) : info(i) {}
    virtual ~w_login(){}

private:
    w_login_info_t info;

  SState in(const heartbeat_t& in) override;
  SState in(const rq_key_t& in) override;
  SState in(const rq_login_t& in) override;
  SState in(const rq_logout_t& in) override;
  SState in(const timer_t& in) override;

};

class login : public BaseState {
public:
    login(const login_info_t& i) : info(i) {}
    virtual ~login(){}

private:
    login_info_t info;

  SState in(const heartbeat_t& in) override;
  SState in(const rq_key_t& in) override;
  SState in(const rq_login_t& in) override;
  SState in(const rq_logout_t& in) override;
  SState in(const timer_t& in) override;

};

class logout : public BaseState {
public:
    logout(const logout_info_t& i) : info(i) {}
    virtual ~logout(){}

private:
    logout_info_t info;

  SState in(const heartbeat_t& in) override;
  SState in(const rq_key_t& in) override;
  SState in(const rq_login_t& in) override;
  SState in(const rq_logout_t& in) override;
  SState in(const timer_t& in) override;

};



Fsm::Fsm() : state(std::make_shared<init>(init_info_t{})) {}
Fsm::~Fsm() {}

void Fsm::in(const heartbeat_t& in) { state = state ->in(in); }
void Fsm::in(const rq_key_t& in) { state = state ->in(in); }
void Fsm::in(const rq_login_t& in) { state = state ->in(in); }
void Fsm::in(const rq_logout_t& in) { state = state ->in(in); }
void Fsm::in(const timer_t& in) { state = state ->in(in); }



  SState init::in(const heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[init] heartbeat -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2w_login(in);
        log("[init] rq_key -> w_login", in, info, nw_st_info);
        return std::make_shared<w_login>(nw_st_info);

    }              
}
    
  SState init::in(const rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[init] rq_login -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[init] rq_logout -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState init::in(const timer_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2init(in);
        log("[init] timer -> init", in, info, nw_st_info);
        return std::make_shared<init>(nw_st_info);

    }              
}
    
  SState w_login::in(const heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[w_login] heartbeat -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[w_login] rq_key -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const rq_login_t& in) {
    if(false) {;
    } else if(valid(in, info)) {
        auto nw_st_info = in2login(in);
        log("[w_login] rq_login(valid) -> login", in, info, nw_st_info);
        return std::make_shared<login>(nw_st_info);
    } else {
        auto nw_st_info = in2logout(in);
        log("[w_login] rq_login -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[w_login] rq_logout -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState w_login::in(const timer_t& in) {
    if(false) {;
    } else if(timeout_wl(in, info)) {
        auto nw_st_info = in2logout(in);
        log("[w_login] timer(timeout_wl) -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);
    } else {
        auto nw_st_info = in2w_login(in);
        log("[w_login] timer -> w_login", in, info, nw_st_info);
        return std::make_shared<w_login>(nw_st_info);

    }              
}
    
  SState login::in(const heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2login(in);
        log("[login] heartbeat -> login", in, info, nw_st_info);
        return std::make_shared<login>(nw_st_info);

    }              
}
    
  SState login::in(const rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[login] rq_key -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[login] rq_login -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[login] rq_logout -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState login::in(const timer_t& in) {
    if(false) {;
    } else if(timeout_l(in, info)) {
        auto nw_st_info = in2logout(in);
        log("[login] timer(timeout_l) -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);
    } else {
        auto nw_st_info = in2login(in);
        log("[login] timer -> login", in, info, nw_st_info);
        return std::make_shared<login>(nw_st_info);

    }              
}
    
  SState logout::in(const heartbeat_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[logout] heartbeat -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const rq_key_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[logout] rq_key -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const rq_login_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[logout] rq_login -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const rq_logout_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[logout] rq_logout -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    
  SState logout::in(const timer_t& in) {
    if(false) {;
    } else {
        auto nw_st_info = in2logout(in);
        log("[logout] timer -> logout", in, info, nw_st_info);
        return std::make_shared<logout>(nw_st_info);

    }              
}
    

} // namespace login

