
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

//  This file will be included in _gen.cpp
//  (anywhere else)

//  to make happy some IDEs
#include "fsm_login_types.h"
#include "fsm_login_gen.h"

namespace {
    using namespace login;

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << txt_trans << std::endl;
    }

    //  status change functions
    template <typename FROM, typename IN> st_init_t from_in2init(const FROM&, const IN&) { return st_init_t{}; }
    template <typename FROM, typename IN> st_w_login_t from_in2w_login(const FROM&, const IN&) { return st_w_login_t{}; }
    template <typename FROM, typename IN> st_login_t from_in2login(const FROM&, const IN&) { return st_login_t{}; }
    template <typename FROM, typename IN> st_logout_t from_in2logout(const FROM&, const IN&) { return st_logout_t{}; }
    template <typename FROM, typename IN> st_error_t from_in2error(const FROM&, const IN&) { return st_error_t{}; }


    //  guards
    bool valid(const in_rq_login_t& /*in*/, const  st_w_login_t& /*st_info*/) { return true; }
    bool timeout(const in_timer_t& /*in*/, const  st_w_login_t& /*st_info*/) { return true; }
    bool timeout(const in_timer_t& /*in*/, const  st_login_t& /*st_info*/) { return true; }


    //  actions
    void act_send_key(const st_init_t& /*st_orig*/, const in_rq_key_t& /*in*/, const  st_w_login_t& /*st_dest*/) {}
    void act_send_login(const st_w_login_t& /*st_orig*/, const in_rq_login_t& /*in*/, const  st_login_t& /*st_dest*/) {}
    void act_send_logout(const st_login_t& /*st_orig*/, const in_rq_logout_t& /*in*/, const  st_logout_t& /*st_dest*/) {}
    void act_update_hb(const st_login_t& /*st_orig*/, const in_heartbeat_t& /*in*/, const  st_login_t& /*st_dest*/) {}


} // namespace anonymous
