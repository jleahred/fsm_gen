
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_login.h"
#include "fsm_login_gen.h"

namespace login {

    //  status change functions
    logout_info_t from_in2logout(const init_info_t& /*from*/, const heartbeat_t& /*in*/){ return logout_info_t{};}
    w_login_info_t from_in2w_login(const init_info_t& /*from*/, const rq_key_t& /*in*/){ return w_login_info_t{};}
    logout_info_t from_in2logout(const init_info_t& /*from*/, const rq_login_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const init_info_t& /*from*/, const rq_logout_t& /*in*/){ return logout_info_t{};}
    init_info_t from_in2init(const init_info_t& /*from*/, const timer_t& /*in*/){ return init_info_t{};}
    login_info_t from_in2login(const login_info_t& /*from*/, const heartbeat_t& /*in*/){ return login_info_t{};}
    logout_info_t from_in2logout(const login_info_t& /*from*/, const rq_key_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const login_info_t& /*from*/, const rq_login_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const login_info_t& /*from*/, const rq_logout_t& /*in*/){ return logout_info_t{};}
    login_info_t from_in2login(const login_info_t& /*from*/, const timer_t& /*in*/){ return login_info_t{};}
    logout_info_t from_in2logout(const login_info_t& /*from*/, const timer_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const logout_info_t& /*from*/, const heartbeat_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const logout_info_t& /*from*/, const rq_key_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const logout_info_t& /*from*/, const rq_login_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const logout_info_t& /*from*/, const rq_logout_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const logout_info_t& /*from*/, const timer_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const w_login_info_t& /*from*/, const heartbeat_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const w_login_info_t& /*from*/, const rq_key_t& /*in*/){ return logout_info_t{};}
    login_info_t from_in2login(const w_login_info_t& /*from*/, const rq_login_t& /*in*/){ return login_info_t{};}
    logout_info_t from_in2logout(const w_login_info_t& /*from*/, const rq_login_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const w_login_info_t& /*from*/, const rq_logout_t& /*in*/){ return logout_info_t{};}
    logout_info_t from_in2logout(const w_login_info_t& /*from*/, const timer_t& /*in*/){ return logout_info_t{};}
    w_login_info_t from_in2w_login(const w_login_info_t& /*from*/, const timer_t& /*in*/){ return w_login_info_t{};}


    //  guards
    bool valid(const rq_login_t& /*in*/, const  w_login_info_t& /*st_info*/) { return true; }
    bool timeout_wl(const timer_t& /*in*/, const  w_login_info_t& /*st_info*/) { return true; }
    bool timeout_l(const timer_t& /*in*/, const  login_info_t& /*st_info*/) { return true; }


} // namespace login
