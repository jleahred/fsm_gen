/*
 *
 *  look into login.fsm
 *
 */

#include <iostream>

#include "fsm_iceberg_gen.h"

int main() {
  iceberg::Fsm ice;
  ice.process(iceberg::in_rq_nw_t{});
  return 0;
}
