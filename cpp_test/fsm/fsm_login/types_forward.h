
//  Code generated automatically
//  
//  forward declaration of types
//
//  do not modify it manually!!!
//    generated on 2023-06-15 00:20:20

#pragma once


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
    


//  transformers types
namespace transf {
  namespace act {

  struct Tr{
    Tr(const StInit& , const InRqKey&, const StWLogin& ) {};
    Tr(const StWLogin& , const InRqLogin&, const StLogin& ) {};
    Tr(const StLogin& , const InRqLogout&, const StLogout& ) {};
    };
  

  }   //  namespace act
} //  namespace transf


} // namespace login

