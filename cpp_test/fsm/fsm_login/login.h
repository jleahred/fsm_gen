
// clang-format off

//  generated automatically  2023-06-18 13:27:21
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "types.h"


namespace fsm_login {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    void process(const InHeartbeat &heartbeat);
    void process(const InRqKey &rq_key);
    void process(const InRqLogin &rq_login);
    void process(const InRqLogout &rq_logout);
    void process(const InTimer &timer);
    
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace login

// clang-format on
