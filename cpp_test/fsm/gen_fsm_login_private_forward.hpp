
//  generated automatically  2020-12-10 10:55:01
//  do not modify it manually

//  This file will be included in private_hpp_file.hpp

#pragma once
//  to make happy some IDEs -----
#include "gen_fsm_login_types_forward.hpp"
#include "gen_fsm_login.h"
//  to make happy some IDEs -----

#include<variant>

namespace {
    using namespace login;

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &);

    //  status change functions
    //  you can specialize this generic functions
    
    template <typename FROM_ST, typename IN>
    std::variant<st_init_t, st_error_t> fromin2_init(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_w_login_t, st_error_t> fromin2_w_login(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_login_t, st_error_t> fromin2_login(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_logout_t, st_error_t> fromin2_logout(const FROM_ST &, const IN &);
    
    
    

    template <typename FROM_ST, typename IN>
    st_error_t fromin2_error(const FROM_ST &, const IN &);
    
    //  guards
    template<typename FROM_ST>
    bool timeout(const in_timer_t& input, const FROM_ST&);
    

    //  actions
    template<typename FROM_ST, typename TO_ST>
    void act_send_login(const FROM_ST&, const in_rq_login_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_logout(const FROM_ST&, const in_rq_logout_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_key(const FROM_ST&, const in_rq_key_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_update_hb(const FROM_ST&, const in_heartbeat_t& input, const TO_ST&);
    

} // namespace anonymous

