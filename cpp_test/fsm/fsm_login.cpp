
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_login.h"
#include "fsm_login_gen.h"

namespace login {

    //  status change functions
    login_info_t in2login(const heartbeat_t& i){ return login_info_t{};}
    logout_info_t in2logout(const heartbeat_t& i){ return logout_info_t{};}
    logout_info_t in2logout(const rq_key_t& i){ return logout_info_t{};}
    w_login_info_t in2w_login(const rq_key_t& i){ return w_login_info_t{};}
    login_info_t in2login(const rq_login_t& i){ return login_info_t{};}
    logout_info_t in2logout(const rq_login_t& i){ return logout_info_t{};}
    logout_info_t in2logout(const rq_logout_t& i){ return logout_info_t{};}
    init_info_t in2init(const timer_t& i){ return init_info_t{};}
    login_info_t in2login(const timer_t& i){ return login_info_t{};}
    logout_info_t in2logout(const timer_t& i){ return logout_info_t{};}
    w_login_info_t in2w_login(const timer_t& i){ return w_login_info_t{};}


    //  guards
    bool valid(const rq_login_t& in, const  w_login_info_t& st_info) { return true; }
    bool timeout_wl(const timer_t& in, const  w_login_info_t& st_info) { return true; }
    bool timeout_l(const timer_t& in, const  login_info_t& st_info) { return true; }


} // namespace login
