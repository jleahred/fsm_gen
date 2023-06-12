
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on 2023-06-12 21:01:03


#pragma once


// #include "types_forward.h"

namespace fsm_login {

  //  status info types

  struct StInit{};
  struct StWLogin{};
  struct StLogin{};
  struct StLogout{};
  struct StError{};
  struct StTesting{};
  


  //  input types

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
    


} // namespace login

