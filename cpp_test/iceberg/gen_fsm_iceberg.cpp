
// clang-format off

//  generated automatically  2022-02-27 20:40:26
//  do not modify it manually

#include "gen_fsm_iceberg.h"

#include "fsm_iceberg_private.hpp"

#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

namespace iceberg {

  class BaseState {
  public:
    BaseState()  {}
    virtual ~BaseState() {}

   public:
     virtual SState input(const in_timer_t& in) = 0;
     virtual SState input(const in_cf_cc_t& in) = 0;
     virtual SState input(const in_cf_nw_t& in) = 0;
     virtual SState input(const in_rq_nw_t& in) = 0;
     virtual SState input(const in_rq_md_t& in) = 0;
     virtual SState input(const in_rq_cc_t& in) = 0;
     virtual SState input(const in_cf_ex_t& in) = 0;
     
   };


  
  class init : public BaseState {
  public:
    init(const st_init_t& i) : info(i) {}
    virtual ~init(){}

  private:
    st_init_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class w_cf_nw : public BaseState {
  public:
    w_cf_nw(const st_w_cf_nw_t& i) : info(i) {}
    virtual ~w_cf_nw(){}

  private:
    st_w_cf_nw_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class modifying_w_nw : public BaseState {
  public:
    modifying_w_nw(const st_modifying_w_nw_t& i) : info(i) {}
    virtual ~modifying_w_nw(){}

  private:
    st_modifying_w_nw_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class modifying_w_cc : public BaseState {
  public:
    modifying_w_cc(const st_modifying_w_cc_t& i) : info(i) {}
    virtual ~modifying_w_cc(){}

  private:
    st_modifying_w_cc_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class canceling_w_nw : public BaseState {
  public:
    canceling_w_nw(const st_canceling_w_nw_t& i) : info(i) {}
    virtual ~canceling_w_nw(){}

  private:
    st_canceling_w_nw_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class market : public BaseState {
  public:
    market(const st_market_t& i) : info(i) {}
    virtual ~market(){}

  private:
    st_market_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class canceling_w_cc : public BaseState {
  public:
    canceling_w_cc(const st_canceling_w_cc_t& i) : info(i) {}
    virtual ~canceling_w_cc(){}

  private:
    st_canceling_w_cc_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class end : public BaseState {
  public:
    end(const st_end_t& i) : info(i) {}
    virtual ~end(){}

  private:
    st_end_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class error : public BaseState {
  public:
    error(const st_error_t& i) : info(i) {}
    virtual ~error(){}

  private:
    st_error_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  class error2 : public BaseState {
  public:
    error2(const st_error2_t& i) : info(i) {}
    virtual ~error2(){}

  private:
    st_error2_t info;

    SState input(const in_timer_t& in) override;
    SState input(const in_cf_cc_t& in) override;
    SState input(const in_cf_nw_t& in) override;
    SState input(const in_rq_nw_t& in) override;
    SState input(const in_rq_md_t& in) override;
    SState input(const in_rq_cc_t& in) override;
    SState input(const in_cf_ex_t& in) override;
    
  };
  
  


Fsm::Fsm() : state(std::make_shared<init>(st_init_t{})) {}
Fsm::~Fsm() {}

void Fsm::process(const in_timer_t& in) { state = state ->input(in); }
void Fsm::process(const in_cf_cc_t& in) { state = state ->input(in); }
void Fsm::process(const in_cf_nw_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_nw_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_md_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_cc_t& in) { state = state ->input(in); }
void Fsm::process(const in_cf_ex_t& in) { state = state ->input(in); }




SState init::input(const in_timer_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[init] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_cf_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[init] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_cf_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[init] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_w_cf_nw<st_init_t, in_rq_nw_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_w_cf_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[init] rq_nw -> w_cf_nw", in, info, nw_st_info);
          act_send_rq_nw(this->info, in, nw_st_info);
          
          return std::make_shared<w_cf_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[init] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_md_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[init] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_rq_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[init] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState init::input(const in_cf_ex_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_init_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[init] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState w_cf_nw::input(const in_timer_t& in) {
  try {
      
      if(true && timeout(in, info)){
        
        auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_timer_t>(this->info, in);
        log(en_log_level::info, "[w_cf_nw] timer -> error", in, info, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_w_cf_nw<st_w_cf_nw_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_w_cf_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[w_cf_nw] timer -> w_cf_nw", in, info, nw_st_info);
          
          return std::make_shared<w_cf_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_cf_cc_t>(this->info, in);
        log(en_log_level::info, "[w_cf_nw] cf_cc -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_market<st_w_cf_nw_t, in_cf_nw_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_market_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[w_cf_nw] cf_nw -> market", in, info, nw_st_info);
          
          return std::make_shared<market>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[w_cf_nw] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_nw<st_w_cf_nw_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[w_cf_nw] rq_md -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_w_cf_nw_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[w_cf_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState w_cf_nw::input(const in_cf_ex_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_cf_ex_t>(this->info, in);
        log(en_log_level::info, "[w_cf_nw] cf_ex -> error", in, info, nw_st_info);
        act_send_cf_ex(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_w_cf_nw_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[w_cf_nw] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState modifying_w_nw::input(const in_timer_t& in) {
  try {
      
      if(true && timeout(in, info)){
        
        auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_timer_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_nw] timer -> error", in, info, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_nw<st_modifying_w_nw_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_nw] timer -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_cf_cc_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_nw] cf_cc -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_modifying_w_nw_t, in_cf_nw_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_nw] cf_nw -> modifying_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_nw] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_nw<st_modifying_w_nw_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_nw] rq_md -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_modifying_w_nw_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_nw::input(const in_cf_ex_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_cf_ex_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_nw] cf_ex -> error", in, info, nw_st_info);
        act_send_cf_ex(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_nw_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_nw] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState modifying_w_cc::input(const in_timer_t& in) {
  try {
      
      if(true && timeout(in, info)){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_modifying_w_cc_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] timer -> modifying_w_cc", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_modifying_w_cc_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] timer -> modifying_w_cc", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_nw<st_modifying_w_cc_t, in_cf_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] cf_cc -> modifying_w_nw", in, info, nw_st_info);
          act_send_rq_nw(this->info, in, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_cf_nw_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_cc] cf_nw -> error", in, info, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[modifying_w_cc] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_modifying_w_cc_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] rq_md -> modifying_w_cc", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_modifying_w_cc_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState modifying_w_cc::input(const in_cf_ex_t& in) {
  try {
      
      if(true && full_cli(in, info)){
        
        auto nw_st_info_or_error = fromin2_end<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] cf_ex -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && full_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_end<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] cf_ex -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          act_send_cf_cc(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && partial_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[modifying_w_cc] cf_ex -> modifying_w_cc", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[modifying_w_cc] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState canceling_w_nw::input(const in_timer_t& in) {
  try {
      
      if(true && timeout(in, info)){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_nw_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_nw] timer -> canceling_w_nw", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_nw_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_nw] timer -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_cf_cc_t>(this->info, in);
        log(en_log_level::info, "[canceling_w_nw] cf_cc -> error", in, info, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_canceling_w_nw_t, in_cf_nw_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_nw] cf_nw -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[canceling_w_nw] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_nw_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_nw] rq_md -> canceling_w_nw", in, info, nw_st_info);
          act_send_rj_md(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_nw_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_nw::input(const in_cf_ex_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_cf_ex_t>(this->info, in);
        log(en_log_level::info, "[canceling_w_nw] cf_ex -> error", in, info, nw_st_info);
        act_send_cf_ex(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_nw_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_nw] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState market::input(const in_timer_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_market<st_market_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_market_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] timer -> market", in, info, nw_st_info);
          
          return std::make_shared<market>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[market] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_market_t, in_cf_cc_t>(this->info, in);
        log(en_log_level::info, "[market] cf_cc -> error", in, info, nw_st_info);
        act_send_cf_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[market] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_market_t, in_cf_nw_t>(this->info, in);
        log(en_log_level::info, "[market] cf_nw -> error", in, info, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[market] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_market_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[market] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[market] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_modifying_w_cc<st_market_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_modifying_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] rq_md -> modifying_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[market] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_market_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[market] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState market::input(const in_cf_ex_t& in) {
  try {
      
      if(true && full_cli(in, info)){
        
        auto nw_st_info_or_error = fromin2_end<st_market_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] cf_ex -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && full_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_w_cf_nw<st_market_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_w_cf_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] cf_ex -> w_cf_nw", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          act_send_rq_nw(this->info, in, nw_st_info);
          
          return std::make_shared<w_cf_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && partial_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_market<st_market_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_market_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[market] cf_ex -> market", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<market>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_market_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[market] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState canceling_w_cc::input(const in_timer_t& in) {
  try {
      
      if(true && timeout(in, info)){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_cc_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] timer -> canceling_w_nw", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_nw<st_canceling_w_cc_t, in_timer_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_nw_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] timer -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_cf_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_end<st_canceling_w_cc_t, in_cf_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] cf_cc -> end", in, info, nw_st_info);
          act_send_cf_cc(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_cf_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_cf_nw_t>(this->info, in);
        log(en_log_level::info, "[canceling_w_cc] cf_nw -> error", in, info, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_rq_nw_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_rq_nw_t>(this->info, in);
        log(en_log_level::info, "[canceling_w_cc] rq_nw -> error", in, info, nw_st_info);
        act_send_rj_nw(this->info, in, nw_st_info);
        act_send_rq_cc(this->info, in, nw_st_info);
        
        return std::make_shared<error>(nw_st_info);
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_rq_md_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_canceling_w_cc_t, in_rq_md_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] rq_md -> canceling_w_cc", in, info, nw_st_info);
          act_send_rj_md(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_rq_cc_t& in) {
  try {
      
      if(true){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_canceling_w_cc_t, in_rq_cc_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState canceling_w_cc::input(const in_cf_ex_t& in) {
  try {
      
      if(true && full_cli(in, info)){
        
        auto nw_st_info_or_error = fromin2_end<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] cf_ex -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && full_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_end<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_end_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] cf_ex -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          act_send_cf_cc(this->info, in, nw_st_info);
          
          return std::make_shared<end>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
      if(true && partial_mk(in, info)){
        
        auto nw_st_info_or_error = fromin2_canceling_w_cc<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_canceling_w_cc_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[canceling_w_cc] cf_ex -> canceling_w_cc", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        
      }
      
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[canceling_w_cc] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState end::input(const in_timer_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[end] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_cf_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[end] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_cf_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[end] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_rq_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[end] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_rq_md_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[end] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_rq_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[end] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState end::input(const in_cf_ex_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_end_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[end] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState error::input(const in_timer_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[error] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_cf_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[error] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_cf_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[error] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[error] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_md_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[error] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_rq_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[error] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error::input(const in_cf_ex_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[error] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}

SState error2::input(const in_timer_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_timer_t>(this->info, in);
  log(en_log_level::critic, "[error2] timer error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_cf_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_cf_cc_t>(this->info, in);
  log(en_log_level::critic, "[error2] cf_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_cf_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_cf_nw_t>(this->info, in);
  log(en_log_level::critic, "[error2] cf_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_rq_nw_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_rq_nw_t>(this->info, in);
  log(en_log_level::critic, "[error2] rq_nw error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_rq_md_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_rq_md_t>(this->info, in);
  log(en_log_level::critic, "[error2] rq_md error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_rq_cc_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_rq_cc_t>(this->info, in);
  log(en_log_level::critic, "[error2] rq_cc error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
SState error2::input(const in_cf_ex_t& in) {
  try {
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_error2_t, in_cf_ex_t>(this->info, in);
  log(en_log_level::critic, "[error2] cf_ex error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}



}

#pragma GCC diagnostic pop

// clang-format on
