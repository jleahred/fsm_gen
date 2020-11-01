
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  but a file with same name ended wiht .reference will be created always
//    generated on 2020-11-02 00:10:20

//  This file will be included in _gen.cpp
//  (anywhere else)

//  to make happy some IDEs -----
#include "fsm_login_types.h"
#include "fsm_login_gen.h"
//  to make happy some IDEs -----

#include<variant>

namespace {
    using namespace login;

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << txt_trans << std::endl;
    }

    //  status change functions
    template <typename FROM, typename IN, typename TO>
    std::variant<TO, st_error_t> fromin2(const FROM &, const IN &) {
        return TO{};
    }
    template <typename FROM, typename IN>
    st_error_t fromin2error(const FROM &, const IN &) {
      return st_error_t{};
    }
    

    //  guards
    bool timeout(const in_timer_t& /*in*/, const st_w_login_t& /*st_from*/) { return true; }
    bool timeout(const in_timer_t& /*in*/, const st_login_t& /*st_from*/) { return true; }
    

    //  actions
    void act_send_key(const st_init_t& /*from*/, const in_rq_key_t& /*input*/, const st_w_login_t& /*st_dest*/) {}
    void act_send_login(const st_w_login_t& /*from*/, const in_rq_login_t& /*input*/, const st_login_t& /*st_dest*/) {}
    void act_send_logout(const st_login_t& /*from*/, const in_rq_logout_t& /*input*/, const st_logout_t& /*st_dest*/) {}
    void act_update_hb(const st_login_t& /*from*/, const in_heartbeat_t& /*input*/, const st_login_t& /*st_dest*/) {}
    

} // namespace anonymous

