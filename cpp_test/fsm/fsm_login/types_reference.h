
//  Code generated automatically as reference file
//  Do not modify manually, it will be generated on each execution
//  This file will  be updated by generator
//
//    generated on 2023-06-18 13:01:00
    
#pragma once


namespace fsm_login {

  //  status info types    -----------------------------------------------

struct StInit{};
struct StWLogin{};
struct StLogin{};
struct StLogout{};
struct StError{};
struct StTesting{};



//  input types   ------------------------------------------------------

  //  provisinal code, delete it when replace the nexts usings
    struct Provisional_InHeartbeat{};
    struct Provisional_InRqKey{};
    struct Provisional_InRqLogin{};
    struct Provisional_InRqLogout{};
    struct Provisional_InTimer{};
    

  
  //  usings
  using InHeartbeat = Provisional_InHeartbeat;
  using InRqKey = Provisional_InRqKey;
  using InRqLogin = Provisional_InRqLogin;
  using InRqLogout = Provisional_InRqLogout;
  using InTimer = Provisional_InTimer;
  


//  adapters types   -----------------------------------------------
namespace adapt {

//  -------------------------------------------------------
namespace act {

} //  namespace act

//  -------------------------------------------------------
namespace guard {

struct Tr{
  Tr(const StWLogin& , const InTimer&) {};
  };
} //  namespace guard

//  -------------------------------------------------------
namespace trans {

} //  namespace trans

} //  namespace adapt

} // namespace login

