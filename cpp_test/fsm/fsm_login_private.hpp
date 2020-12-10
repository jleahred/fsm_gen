
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2020-12-10 10:55:01

//  This file will be included in gen_fsm_login.cpp
//  (anywhere else)

#pragma once

#include "gen_fsm_login_private_forward.hpp"

//  to make happy some IDEs -----
#include "fsm_login_types.h"
#include "gen_fsm_login.h"
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
    
    template <typename FROM, typename IN>
    std::variant<st_init_t, st_error_t> fromin2_init(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_init_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_w_login_t, st_error_t> fromin2_w_login(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_w_login_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_login_t, st_error_t> fromin2_login(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_login_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_logout_t, st_error_t> fromin2_logout(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_logout_t{};
    }
    
    
    

    template <typename FROM, typename IN>
    st_error_t fromin2_error(const FROM &, const IN &) {
      return st_error_t{};
    }
    

    //  guards
    template<typename FROM_ST>
    bool timeout(const in_timer_t& /*input*/, const FROM_ST&) { return true; }
    

    //  actions
    template<typename FROM_ST, typename TO_ST>
    void act_send_login(const FROM_ST&, const in_rq_login_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_logout(const FROM_ST&, const in_rq_logout_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_key(const FROM_ST&, const in_rq_key_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_update_hb(const FROM_ST&, const in_heartbeat_t& /*input*/, const TO_ST&) {}
    

} // namespace anonymous

