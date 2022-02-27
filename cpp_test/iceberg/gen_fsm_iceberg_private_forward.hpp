
//  generated automatically  2022-02-27 20:40:26
//  do not modify it manually

//  This file will be included in private_hpp_file.hpp

#pragma once
//  to make happy some IDEs -----
#include "gen_fsm_iceberg_types_forward.hpp"
#include "gen_fsm_iceberg.h"
//  to make happy some IDEs -----

#include<variant>

namespace {
    using namespace iceberg;

    //  log
    enum class en_log_level { critic, error, warning, info };
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(en_log_level, const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &);

    //  status change functions
    //  you can specialize this generic functions
    
    template <typename FROM_ST, typename IN>
    std::variant<st_init_t, st_error_t> fromin2_init(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_w_cf_nw_t, st_error_t> fromin2_w_cf_nw(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_modifying_w_nw_t, st_error_t> fromin2_modifying_w_nw(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_modifying_w_cc_t, st_error_t> fromin2_modifying_w_cc(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_canceling_w_nw_t, st_error_t> fromin2_canceling_w_nw(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_market_t, st_error_t> fromin2_market(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_canceling_w_cc_t, st_error_t> fromin2_canceling_w_cc(const FROM_ST &, const IN &);
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_end_t, st_error_t> fromin2_end(const FROM_ST &, const IN &);
    
    
    
    template <typename FROM_ST, typename IN>
    std::variant<st_error2_t, st_error_t> fromin2_error2(const FROM_ST &, const IN &);
    
    

    template <typename FROM_ST, typename IN>
    st_error_t fromin2_error(const FROM_ST &, const IN &);
    
    //  guards
    template<typename FROM_ST>
    bool full_mk(const in_cf_ex_t& input, const FROM_ST&);
    template<typename FROM_ST>
    bool timeout(const in_timer_t& input, const FROM_ST&);
    template<typename FROM_ST>
    bool full_cli(const in_cf_ex_t& input, const FROM_ST&);
    template<typename FROM_ST>
    bool partial_mk(const in_cf_ex_t& input, const FROM_ST&);
    

    //  actions
    template<typename FROM_ST, typename TO_ST>
    void act_send_rj_nw(const FROM_ST&, const in_rq_nw_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_cc(const FROM_ST&, const in_cf_ex_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_nw_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_md_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_cc(const FROM_ST&, const in_cf_cc_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_cf_ex_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_timer_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_cf_ex(const FROM_ST&, const in_cf_ex_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_rq_nw_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_cf_cc_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_warning_timer(const FROM_ST&, const in_timer_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_cf_nw_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_cc(const FROM_ST&, const in_rq_cc_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rq_nw(const FROM_ST&, const in_cf_ex_t& input, const TO_ST&);
    template<typename FROM_ST, typename TO_ST>
    void act_send_rj_md(const FROM_ST&, const in_rq_md_t& input, const TO_ST&);
    

} // namespace anonymous

