
// clang-format off

//  generated automatically  2023-06-12 18:54:48
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

    void process(const InHeartbeat &in);
    void process(const InRqKey &in);
    void process(const InRqLogin &in);
    void process(const InRqLogout &in);
    void process(const InTimer &in);
    
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace login

// clang-format on
