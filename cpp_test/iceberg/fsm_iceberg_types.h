
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on 2022-02-27 20:40:26


#pragma once

#include "gen_fsm_iceberg_types_forward.hpp"

namespace iceberg {

  //  status info types

  struct st_init_t{};
  struct st_w_cf_nw_t{};
  struct st_modifying_w_nw_t{};
  struct st_modifying_w_cc_t{};
  struct st_canceling_w_nw_t{};
  struct st_market_t{};
  struct st_canceling_w_cc_t{};
  struct st_end_t{};
  struct st_error_t{};
  struct st_error2_t{};
  


  //  input types

    //  provisinal code, delete it when replace the nexts usings
      struct provisinal_in_timer_t{};
      struct provisinal_in_cf_cc_t{};
      struct provisinal_in_cf_nw_t{};
      struct provisinal_in_rq_nw_t{};
      struct provisinal_in_rq_md_t{};
      struct provisinal_in_rq_cc_t{};
      struct provisinal_in_cf_ex_t{};
      

    //  usings
    using in_timer_t = provisinal_in_timer_t;
    using in_cf_cc_t = provisinal_in_cf_cc_t;
    using in_cf_nw_t = provisinal_in_cf_nw_t;
    using in_rq_nw_t = provisinal_in_rq_nw_t;
    using in_rq_md_t = provisinal_in_rq_md_t;
    using in_rq_cc_t = provisinal_in_rq_cc_t;
    using in_cf_ex_t = provisinal_in_cf_ex_t;
    


} // namespace iceberg

