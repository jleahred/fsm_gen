
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  but a file with same name ended wiht .reference will be created always
//    generated on 2020-11-22 23:44:05

//  This file will be included in _gen.cpp
//  (anywhere else)

#pragma once
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
        //  you can specialize this generic function
        return TO{};
    }
    template <typename FROM, typename IN>
    st_error_t fromin2error(const FROM &, const IN &) {
      return st_error_t{};
    }
    

    //  guards
    template<typename FROM_ST>
    bool timeout(const in_timer_t& /*input*/, const FROM_ST&) { return true; }
    

    //  actions
    template<typename FROM_ST, typename TO_ST>
    void act_update_hb(const FROM_ST&, const in_heartbeat_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_logout(const FROM_ST&, const in_rq_logout_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_key(const FROM_ST&, const in_rq_key_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_login(const FROM_ST&, const in_rq_login_t& /*input*/, const TO_ST&) {}
    

} // namespace anonymous

