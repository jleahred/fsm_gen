
// clang-format off

//  generated automatically  2023-06-11 21:20:40
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "types.hpp"

namespace fsm_login {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    void process(const in_heartbeat_t &in);
    void process(const in_rq_login_t &in);
    void process(const in_rq_key_t &in);
    void process(const in_timer_t &in);
    void process(const in_rq_logout_t &in);
    
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace login

// clang-format on
