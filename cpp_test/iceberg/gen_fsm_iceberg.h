
// clang-format off

//  generated automatically  2022-02-27 20:40:26
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "fsm_iceberg_types.h"

namespace iceberg {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    void process(const in_timer_t &in);
    void process(const in_cf_cc_t &in);
    void process(const in_cf_nw_t &in);
    void process(const in_rq_nw_t &in);
    void process(const in_rq_md_t &in);
    void process(const in_rq_cc_t &in);
    void process(const in_cf_ex_t &in);
    
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace iceberg

// clang-format on
