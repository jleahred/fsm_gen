/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "gen_fsm_iceberg.h"

int main() {
  iceberg::Fsm ice;
  ice.process(iceberg::in_rq_nw_t{});
  return 0;
}
