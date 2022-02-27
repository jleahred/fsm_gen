
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on 2022-02-27 20:40:26

//  This file will be included in gen_fsm_iceberg.cpp
//  (anywhere else)

#pragma once

#include "gen_fsm_iceberg_private_forward.hpp"

//  to make happy some IDEs -----
#include "fsm_iceberg_types.h"
#include "gen_fsm_iceberg.h"
//  to make happy some IDEs -----

#include<variant>
#include<iostream>

namespace {
    using namespace iceberg;

    //  log
    std::ostream& operator<<(std::ostream& os, en_log_level level) {
        switch(level) {
        case en_log_level::critic:
            os << "CRITIC";
            break;
        case en_log_level::error:
            os << "ERROR ";
            break;
        case en_log_level::warning:
            os << "warning";
            break;
        case en_log_level::info:
            os << "info   ";
            break;
        }
        return os;
    }
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(en_log_level level, const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << level << "  " << txt_trans << std::endl;
    }

    //  status change functions
    
    template <typename FROM, typename IN>
    std::variant<st_init_t, st_error_t> fromin2_init(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_init_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_w_cf_nw_t, st_error_t> fromin2_w_cf_nw(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_w_cf_nw_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_modifying_w_nw_t, st_error_t> fromin2_modifying_w_nw(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_modifying_w_nw_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_modifying_w_cc_t, st_error_t> fromin2_modifying_w_cc(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_modifying_w_cc_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_canceling_w_nw_t, st_error_t> fromin2_canceling_w_nw(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_canceling_w_nw_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_market_t, st_error_t> fromin2_market(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_market_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_canceling_w_cc_t, st_error_t> fromin2_canceling_w_cc(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_canceling_w_cc_t{};
    }
    
    
    template <typename FROM, typename IN>
    std::variant<st_end_t, st_error_t> fromin2_end(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_end_t{};
    }
    
    
    
    template <typename FROM, typename IN>
    std::variant<st_error2_t, st_error_t> fromin2_error2(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return st_error2_t{};
    }
    
    

    template <typename FROM, typename IN>
    st_error_t fromin2_error(const FROM &, const IN &) {
      return st_error_t{};
    }
    

    //  guards
    template<typename FROM_ST>
    bool full_mk(const in_cf_ex_t& /*input*/, const FROM_ST&) { return true; }
    template<typename FROM_ST>
    bool timeout(const in_timer_t& /*input*/, const FROM_ST&) { return true; }
    template<typename FROM_ST>
    bool full_cli(const in_cf_ex_t& /*input*/, const FROM_ST&) { return true; }
    template<typename FROM_ST>
    bool partial_mk(const in_cf_ex_t& /*input*/, const FROM_ST&) { return true; }
    

    //  actions
    template<typename FROM_ST, typename TO_ST>
    void act_send_rj_nw(const FROM_ST&, const in_rq_nw_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_cc(const FROM_ST&, const in_cf_ex_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_nw_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_md_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_cc(const FROM_ST&, const in_cf_cc_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_cf_ex_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_timer_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_ex(const FROM_ST&, const in_cf_ex_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_rq_nw_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_cf_cc_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_warning_timer(const FROM_ST&, const in_timer_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_cf_nw_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_cc_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_cf_ex_t& /*input*/, const TO_ST&) {}
    template<typename FROM_ST, typename TO_ST>
    void act_send_rj_md(const FROM_ST&, const in_rq_md_t& /*input*/, const TO_ST&) {}
    

} // namespace anonymous

