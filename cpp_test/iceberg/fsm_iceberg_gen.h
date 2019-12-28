
//  generated automatically  2019-12-28 21:48:15
//  do not modify it manually

#ifndef FSM_ICEBERG_GENERATED_H
#define FSM_ICEBERG_GENERATED_H

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

  void process(const in_cf_cc_t& in);
  void process(const in_cf_ex_t& in);
  void process(const in_cf_nw_t& in);
  void process(const in_rq_cc_t& in);
  void process(const in_rq_md_t& in);
  void process(const in_rq_nw_t& in);
  void process(const in_timer_t& in);




private:
  SState state;
};

//      F S M
//  -------------------

} // namespace iceberg

#endif // FSM_ICEBERG_GENERATED_H
