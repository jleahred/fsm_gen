
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_login.h"
#include "fsm_login_gen.h"

namespace login {

    //  status change functions
    st_logout_info_t from_in2logout(const st_init_info_t& /*from*/, const in_heartbeat_t& /*in*/){ return st_logout_info_t{};}
    st_w_login_info_t from_in2w_login(const st_init_info_t& /*from*/, const in_rq_key_t& /*in*/){ return st_w_login_info_t{};}
    st_logout_info_t from_in2logout(const st_init_info_t& /*from*/, const in_rq_login_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_init_info_t& /*from*/, const in_rq_logout_t& /*in*/){ return st_logout_info_t{};}
    st_init_info_t from_in2init(const st_init_info_t& /*from*/, const in_timer_t& /*in*/){ return st_init_info_t{};}
    st_login_info_t from_in2login(const st_login_info_t& /*from*/, const in_heartbeat_t& /*in*/){ return st_login_info_t{};}
    st_logout_info_t from_in2logout(const st_login_info_t& /*from*/, const in_rq_key_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_login_info_t& /*from*/, const in_rq_login_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_login_info_t& /*from*/, const in_rq_logout_t& /*in*/){ return st_logout_info_t{};}
    st_login_info_t from_in2login(const st_login_info_t& /*from*/, const in_timer_t& /*in*/){ return st_login_info_t{};}
    st_logout_info_t from_in2logout(const st_login_info_t& /*from*/, const in_timer_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_logout_info_t& /*from*/, const in_heartbeat_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_logout_info_t& /*from*/, const in_rq_key_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_logout_info_t& /*from*/, const in_rq_login_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_logout_info_t& /*from*/, const in_rq_logout_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_logout_info_t& /*from*/, const in_timer_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_w_login_info_t& /*from*/, const in_heartbeat_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_w_login_info_t& /*from*/, const in_rq_key_t& /*in*/){ return st_logout_info_t{};}
    st_login_info_t from_in2login(const st_w_login_info_t& /*from*/, const in_rq_login_t& /*in*/){ return st_login_info_t{};}
    st_logout_info_t from_in2logout(const st_w_login_info_t& /*from*/, const in_rq_login_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_w_login_info_t& /*from*/, const in_rq_logout_t& /*in*/){ return st_logout_info_t{};}
    st_logout_info_t from_in2logout(const st_w_login_info_t& /*from*/, const in_timer_t& /*in*/){ return st_logout_info_t{};}
    st_w_login_info_t from_in2w_login(const st_w_login_info_t& /*from*/, const in_timer_t& /*in*/){ return st_w_login_info_t{};}


    //  guards
    bool valid(const in_rq_login_t& /*in*/, const  st_w_login_info_t& /*st_info*/) { return true; }
    bool timeout_wl(const in_timer_t& /*in*/, const  st_w_login_info_t& /*st_info*/) { return true; }
    bool timeout_l(const in_timer_t& /*in*/, const  st_login_info_t& /*st_info*/) { return true; }


    //  actions
    void act_send_key(const st_init_info_t& /*st_orig*/, const in_rq_key_t& /*in*/, const  st_w_login_info_t& /*st_dest*/) {}
    void act_log_err(const st_init_info_t& /*st_orig*/, const in_heartbeat_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_init_info_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_init_info_t& /*st_orig*/, const in_rq_logout_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_send_login(const st_w_login_info_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_login_info_t& /*st_dest*/) {}
    void act_log_err(const st_w_login_info_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_w_login_info_t& /*st_orig*/, const in_timer_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_w_login_info_t& /*st_orig*/, const in_heartbeat_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_w_login_info_t& /*st_orig*/, const in_rq_key_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_w_login_info_t& /*st_orig*/, const in_rq_logout_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_send_logout(const st_login_info_t& /*st_orig*/, const in_rq_logout_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_update_hb(const st_login_info_t& /*st_orig*/, const in_heartbeat_t& /*in*/, const  st_login_info_t& /*st_dest*/) {}
    void act_log_err(const st_login_info_t& /*st_orig*/, const in_rq_key_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_login_info_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_logout_info_t& /*st_orig*/, const in_heartbeat_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_logout_info_t& /*st_orig*/, const in_rq_key_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_logout_info_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}
    void act_log_err(const st_logout_info_t& /*st_orig*/, const in_rq_logout_t& /*in*/, const  st_logout_info_t& /*st_dest*/) {}


} // namespace login
