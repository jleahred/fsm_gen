
/*
{
  "ast": [
    {
      "inputs": [
        {
          "name": "rq_key",
          "transitions": [
            {
              "actions": [
                "send_key"
              ],
              "guards": [],
              "new_status": {
                "name": "w_login",
                "pos": 93
              }
            }
          ]
        },
        {
          "name": "timer",
          "transitions": [
            {
              "actions": [],
              "guards": [],
              "new_status": {
                "name": "init",
                "pos": 139
              }
            }
          ]
        }
      ],
      "name": "init"
    },
    {
      "inputs": [
        {
          "name": "rq_login",
          "transitions": [
            {
              "actions": [
                "send_login"
              ],
              "guards": [],
              "new_status": {
                "name": "login",
                "pos": 179
              }
            }
          ]
        },
        {
          "name": "timer",
          "transitions": [
            {
              "actions": [],
              "guards": [
                {
                  "name": "timeout",
                  "positiv": true
                }
              ],
              "new_status": {
                "name": "error",
                "pos": 240
              }
            },
            {
              "actions": [],
              "guards": [],
              "new_status": {
                "name": "w_login",
                "pos": 272
              }
            }
          ]
        }
      ],
      "name": "w_login"
    },
    {
      "inputs": [
        {
          "name": "rq_logout",
          "transitions": [
            {
              "actions": [
                "send_logout"
              ],
              "guards": [],
              "new_status": {
                "name": "logout",
                "pos": 311
              }
            }
          ]
        },
        {
          "name": "heartbeat",
          "transitions": [
            {
              "actions": [
                "update_hb"
              ],
              "guards": [],
              "new_status": {
                "name": "login",
                "pos": 362
              }
            }
          ]
        },
        {
          "name": "timer",
          "transitions": [
            {
              "actions": [],
              "guards": [
                {
                  "name": "timeout",
                  "positiv": true
                }
              ],
              "new_status": {
                "name": "logout",
                "pos": 423
              }
            },
            {
              "actions": [],
              "guards": [],
              "new_status": {
                "name": "login",
                "pos": 453
              }
            }
          ]
        }
      ],
      "name": "login"
    },
    {
      "inputs": [
        {
          "name": "timer",
          "transitions": [
            {
              "actions": [],
              "guards": [],
              "new_status": {
                "name": "logout",
                "pos": 494
              }
            }
          ]
        }
      ],
      "name": "logout"
    },
    {
      "inputs": [
        {
          "name": "_",
          "transitions": [
            {
              "actions": [],
              "guards": [],
              "new_status": {
                "name": "error",
                "pos": 533
              }
            }
          ]
        }
      ],
      "name": "error"
    }
  ],
  "gen_time": "2020-10-13 00:04:28",
  "in_file": {
    "dir": "./cpp_test/fsm",
    "stem_name": "login"
  },
  "inputs": [
    "rq_key",
    "timer",
    "rq_login",
    "rq_logout",
    "heartbeat"
  ]
}
*/

//  generated automatically  2020-10-13 00:04:28
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "fsm_login_types.h"

namespace login {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    void process(const in_rq_key_t &in);
    void process(const in_timer_t &in);
    void process(const in_rq_login_t &in);
    void process(const in_rq_logout_t &in);
    void process(const in_heartbeat_t &in);
    
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace login
