
//  generated automatically  2019-11-10 22:16:29
//  do not modify it manually

#include "fsm_iceberg_gen.h"

#include "fsm_iceberg_private.hpp"

namespace iceberg {

class BaseState {
public:
  BaseState()  {}
  ~BaseState() {}

public:
  virtual SState input(const in_cf_cc_t& in) = 0;
  virtual SState input(const in_cf_ex_t& in) = 0;
  virtual SState input(const in_cf_nw_t& in) = 0;
  virtual SState input(const in_rq_cc_t& in) = 0;
  virtual SState input(const in_rq_md_t& in) = 0;
  virtual SState input(const in_rq_nw_t& in) = 0;
  virtual SState input(const in_timer_t& in) = 0;

};


class init : public BaseState {
    public:
        init(const st_init_t& i) : info(i) {}
        virtual ~init(){}

    private:
        st_init_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class w_cf_nw : public BaseState {
    public:
        w_cf_nw(const st_w_cf_nw_t& i) : info(i) {}
        virtual ~w_cf_nw(){}

    private:
        st_w_cf_nw_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class modifying_w_nw : public BaseState {
    public:
        modifying_w_nw(const st_modifying_w_nw_t& i) : info(i) {}
        virtual ~modifying_w_nw(){}

    private:
        st_modifying_w_nw_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class modifying_w_cc : public BaseState {
    public:
        modifying_w_cc(const st_modifying_w_cc_t& i) : info(i) {}
        virtual ~modifying_w_cc(){}

    private:
        st_modifying_w_cc_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class canceling_w_nw : public BaseState {
    public:
        canceling_w_nw(const st_canceling_w_nw_t& i) : info(i) {}
        virtual ~canceling_w_nw(){}

    private:
        st_canceling_w_nw_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class market : public BaseState {
    public:
        market(const st_market_t& i) : info(i) {}
        virtual ~market(){}

    private:
        st_market_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class canceling_w_cc : public BaseState {
    public:
        canceling_w_cc(const st_canceling_w_cc_t& i) : info(i) {}
        virtual ~canceling_w_cc(){}

    private:
        st_canceling_w_cc_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class end : public BaseState {
    public:
        end(const st_end_t& i) : info(i) {}
        virtual ~end(){}

    private:
        st_end_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class error : public BaseState {
    public:
        error(const st_error_t& i) : info(i) {}
        virtual ~error(){}

    private:
        st_error_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    class error2 : public BaseState {
    public:
        error2(const st_error2_t& i) : info(i) {}
        virtual ~error2(){}

    private:
        st_error2_t info;
    
        SState input(const in_cf_cc_t& in) override;
        SState input(const in_cf_ex_t& in) override;
        SState input(const in_cf_nw_t& in) override;
        SState input(const in_rq_cc_t& in) override;
        SState input(const in_rq_md_t& in) override;
        SState input(const in_rq_nw_t& in) override;
        SState input(const in_timer_t& in) override;
    };

    

Fsm::Fsm() : state(std::make_shared<init>(st_init_t{})) {}
Fsm::~Fsm() {}

void Fsm::process(const in_cf_cc_t& in) { state = state ->input(in); }
void Fsm::process(const in_cf_ex_t& in) { state = state ->input(in); }
void Fsm::process(const in_cf_nw_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_cc_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_md_t& in) { state = state ->input(in); }
void Fsm::process(const in_rq_nw_t& in) { state = state ->input(in); }
void Fsm::process(const in_timer_t& in) { state = state ->input(in); }



  SState init::input(const in_cf_cc_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_cf_cc_t>(this->info, in);
    log("[init] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_cf_ex_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_cf_ex_t>(this->info, in);
    log("[init] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_cf_nw_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_cf_nw_t>(this->info, in);
    log("[init] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_cc_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_cc_t>(this->info, in);
    log("[init] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_md_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_md_t>(this->info, in);
    log("[init] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2w_cf_nw<st_init_t, in_rq_nw_t>(this->info, in);
          log("[init] rq_nw -> w_cf_nw", in, info, nw_st_info);
          act_send_rq_nw(this->info, in, nw_st_info);
          return std::make_shared<w_cf_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_rq_nw_t>(this->info, in);
    log("[init] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState init::input(const in_timer_t& in) {
    try {
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_init_t, in_timer_t>(this->info, in);
    log("[init] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_w_cf_nw_t, in_cf_cc_t>(this->info, in);
          log("[w_cf_nw] cf_cc -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_cf_cc_t>(this->info, in);
    log("[w_cf_nw] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_w_cf_nw_t, in_cf_ex_t>(this->info, in);
          log("[w_cf_nw] cf_ex -> error", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_cf_ex_t>(this->info, in);
    log("[w_cf_nw] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2market<st_w_cf_nw_t, in_cf_nw_t>(this->info, in);
          log("[w_cf_nw] cf_nw -> market", in, info, nw_st_info);
          
          return std::make_shared<market>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_cf_nw_t>(this->info, in);
    log("[w_cf_nw] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_w_cf_nw_t, in_rq_cc_t>(this->info, in);
          log("[w_cf_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_rq_cc_t>(this->info, in);
    log("[w_cf_nw] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_nw<st_w_cf_nw_t, in_rq_md_t>(this->info, in);
          log("[w_cf_nw] rq_md -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_rq_md_t>(this->info, in);
    log("[w_cf_nw] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_w_cf_nw_t, in_rq_nw_t>(this->info, in);
          log("[w_cf_nw] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_rq_nw_t>(this->info, in);
    log("[w_cf_nw] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState w_cf_nw::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2error<st_w_cf_nw_t, in_timer_t>(this->info, in);
          log("[w_cf_nw] timer(timeout) -> error", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2w_cf_nw<st_w_cf_nw_t, in_timer_t>(this->info, in);
          log("[w_cf_nw] timer -> w_cf_nw", in, info, nw_st_info);
          
          return std::make_shared<w_cf_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_w_cf_nw_t, in_timer_t>(this->info, in);
    log("[w_cf_nw] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_cf_cc_t>(this->info, in);
          log("[modifying_w_nw] cf_cc -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_cf_cc_t>(this->info, in);
    log("[modifying_w_nw] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_cf_ex_t>(this->info, in);
          log("[modifying_w_nw] cf_ex -> error", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_cf_ex_t>(this->info, in);
    log("[modifying_w_nw] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_cc<st_modifying_w_nw_t, in_cf_nw_t>(this->info, in);
          log("[modifying_w_nw] cf_nw -> modifying_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_cf_nw_t>(this->info, in);
    log("[modifying_w_nw] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_modifying_w_nw_t, in_rq_cc_t>(this->info, in);
          log("[modifying_w_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_rq_cc_t>(this->info, in);
    log("[modifying_w_nw] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_nw<st_modifying_w_nw_t, in_rq_md_t>(this->info, in);
          log("[modifying_w_nw] rq_md -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_rq_md_t>(this->info, in);
    log("[modifying_w_nw] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_rq_nw_t>(this->info, in);
          log("[modifying_w_nw] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_rq_nw_t>(this->info, in);
    log("[modifying_w_nw] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_nw::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_timer_t>(this->info, in);
          log("[modifying_w_nw] timer(timeout) -> error", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2modifying_w_nw<st_modifying_w_nw_t, in_timer_t>(this->info, in);
          log("[modifying_w_nw] timer -> modifying_w_nw", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_nw_t, in_timer_t>(this->info, in);
    log("[modifying_w_nw] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_nw<st_modifying_w_cc_t, in_cf_cc_t>(this->info, in);
          log("[modifying_w_cc] cf_cc -> modifying_w_nw", in, info, nw_st_info);
          act_send_rq_nw(this->info, in, nw_st_info);
          return std::make_shared<modifying_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_cf_cc_t>(this->info, in);
    log("[modifying_w_cc] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_cf_ex_t& in) {
    try {
       if(true  && full_cli(in, info)) {
          auto nw_st_info = from_in2end<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[modifying_w_cc] cf_ex(full_cli) -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
       if(true  && full_mk(in, info)) {
          auto nw_st_info = from_in2end<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[modifying_w_cc] cf_ex(full_mk) -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);act_send_cf_cc(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
       if(true  && partial_mk(in, info)) {
          auto nw_st_info = from_in2modifying_w_cc<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[modifying_w_cc] cf_ex(partial_mk) -> modifying_w_cc", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_cf_ex_t>(this->info, in);
    log("[modifying_w_cc] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_cf_nw_t>(this->info, in);
          log("[modifying_w_cc] cf_nw -> error", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_cf_nw_t>(this->info, in);
    log("[modifying_w_cc] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_cc<st_modifying_w_cc_t, in_rq_cc_t>(this->info, in);
          log("[modifying_w_cc] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_rq_cc_t>(this->info, in);
    log("[modifying_w_cc] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_cc<st_modifying_w_cc_t, in_rq_md_t>(this->info, in);
          log("[modifying_w_cc] rq_md -> modifying_w_cc", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_rq_md_t>(this->info, in);
    log("[modifying_w_cc] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_rq_nw_t>(this->info, in);
          log("[modifying_w_cc] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_rq_nw_t>(this->info, in);
    log("[modifying_w_cc] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState modifying_w_cc::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2modifying_w_cc<st_modifying_w_cc_t, in_timer_t>(this->info, in);
          log("[modifying_w_cc] timer(timeout) -> modifying_w_cc", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2modifying_w_cc<st_modifying_w_cc_t, in_timer_t>(this->info, in);
          log("[modifying_w_cc] timer -> modifying_w_cc", in, info, nw_st_info);
          
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_modifying_w_cc_t, in_timer_t>(this->info, in);
    log("[modifying_w_cc] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_cf_cc_t>(this->info, in);
          log("[canceling_w_nw] cf_cc -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_cf_cc_t>(this->info, in);
    log("[canceling_w_nw] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_cf_ex_t>(this->info, in);
          log("[canceling_w_nw] cf_ex -> error", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_cf_ex_t>(this->info, in);
    log("[canceling_w_nw] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_cc<st_canceling_w_nw_t, in_cf_nw_t>(this->info, in);
          log("[canceling_w_nw] cf_nw -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_cf_nw_t>(this->info, in);
    log("[canceling_w_nw] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_nw_t, in_rq_cc_t>(this->info, in);
          log("[canceling_w_nw] rq_cc -> canceling_w_nw", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_rq_cc_t>(this->info, in);
    log("[canceling_w_nw] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_nw_t, in_rq_md_t>(this->info, in);
          log("[canceling_w_nw] rq_md -> canceling_w_nw", in, info, nw_st_info);
          act_send_rj_md(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_rq_md_t>(this->info, in);
    log("[canceling_w_nw] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_rq_nw_t>(this->info, in);
          log("[canceling_w_nw] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_rq_nw_t>(this->info, in);
    log("[canceling_w_nw] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_nw::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_nw_t, in_timer_t>(this->info, in);
          log("[canceling_w_nw] timer(timeout) -> canceling_w_nw", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_nw_t, in_timer_t>(this->info, in);
          log("[canceling_w_nw] timer -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_nw_t, in_timer_t>(this->info, in);
    log("[canceling_w_nw] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_market_t, in_cf_cc_t>(this->info, in);
          log("[market] cf_cc -> error", in, info, nw_st_info);
          act_send_cf_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_cf_cc_t>(this->info, in);
    log("[market] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_cf_ex_t& in) {
    try {
       if(true  && full_cli(in, info)) {
          auto nw_st_info = from_in2end<st_market_t, in_cf_ex_t>(this->info, in);
          log("[market] cf_ex(full_cli) -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
       if(true  && full_mk(in, info)) {
          auto nw_st_info = from_in2w_cf_nw<st_market_t, in_cf_ex_t>(this->info, in);
          log("[market] cf_ex(full_mk) -> w_cf_nw", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);act_send_rq_nw(this->info, in, nw_st_info);
          return std::make_shared<w_cf_nw>(nw_st_info);
       }
       if(true  && partial_mk(in, info)) {
          auto nw_st_info = from_in2market<st_market_t, in_cf_ex_t>(this->info, in);
          log("[market] cf_ex(partial_mk) -> market", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<market>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_cf_ex_t>(this->info, in);
    log("[market] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_market_t, in_cf_nw_t>(this->info, in);
          log("[market] cf_nw -> error", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_cf_nw_t>(this->info, in);
    log("[market] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_cc<st_market_t, in_rq_cc_t>(this->info, in);
          log("[market] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_rq_cc_t>(this->info, in);
    log("[market] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2modifying_w_cc<st_market_t, in_rq_md_t>(this->info, in);
          log("[market] rq_md -> modifying_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<modifying_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_rq_md_t>(this->info, in);
    log("[market] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_market_t, in_rq_nw_t>(this->info, in);
          log("[market] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_rq_nw_t>(this->info, in);
    log("[market] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState market::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2market<st_market_t, in_timer_t>(this->info, in);
          log("[market] timer -> market", in, info, nw_st_info);
          
          return std::make_shared<market>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_market_t, in_timer_t>(this->info, in);
    log("[market] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2end<st_canceling_w_cc_t, in_cf_cc_t>(this->info, in);
          log("[canceling_w_cc] cf_cc -> end", in, info, nw_st_info);
          act_send_cf_cc(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_cf_cc_t>(this->info, in);
    log("[canceling_w_cc] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_cf_ex_t& in) {
    try {
       if(true  && full_cli(in, info)) {
          auto nw_st_info = from_in2end<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[canceling_w_cc] cf_ex(full_cli) -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
       if(true  && full_mk(in, info)) {
          auto nw_st_info = from_in2end<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[canceling_w_cc] cf_ex(full_mk) -> end", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);act_send_cf_cc(this->info, in, nw_st_info);
          return std::make_shared<end>(nw_st_info);
       }
       if(true  && partial_mk(in, info)) {
          auto nw_st_info = from_in2canceling_w_cc<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
          log("[canceling_w_cc] cf_ex(partial_mk) -> canceling_w_cc", in, info, nw_st_info);
          act_send_cf_ex(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_cf_ex_t>(this->info, in);
    log("[canceling_w_cc] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_cf_nw_t>(this->info, in);
          log("[canceling_w_cc] cf_nw -> error", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_cf_nw_t>(this->info, in);
    log("[canceling_w_cc] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_cc<st_canceling_w_cc_t, in_rq_cc_t>(this->info, in);
          log("[canceling_w_cc] rq_cc -> canceling_w_cc", in, info, nw_st_info);
          act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_rq_cc_t>(this->info, in);
    log("[canceling_w_cc] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2canceling_w_cc<st_canceling_w_cc_t, in_rq_md_t>(this->info, in);
          log("[canceling_w_cc] rq_md -> canceling_w_cc", in, info, nw_st_info);
          act_send_rj_md(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_cc>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_rq_md_t>(this->info, in);
    log("[canceling_w_cc] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_rq_nw_t>(this->info, in);
          log("[canceling_w_cc] rq_nw -> error", in, info, nw_st_info);
          act_send_rj_nw(this->info, in, nw_st_info);act_send_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_rq_nw_t>(this->info, in);
    log("[canceling_w_cc] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState canceling_w_cc::input(const in_timer_t& in) {
    try {
       if(true  && timeout(in, info)) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_cc_t, in_timer_t>(this->info, in);
          log("[canceling_w_cc] timer(timeout) -> canceling_w_nw", in, info, nw_st_info);
          act_warning_timer(this->info, in, nw_st_info);
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
       if(true ) {
          auto nw_st_info = from_in2canceling_w_nw<st_canceling_w_cc_t, in_timer_t>(this->info, in);
          log("[canceling_w_cc] timer -> canceling_w_nw", in, info, nw_st_info);
          
          return std::make_shared<canceling_w_nw>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_canceling_w_cc_t, in_timer_t>(this->info, in);
    log("[canceling_w_cc] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_cf_cc_t>(this->info, in);
          log("[end] cf_cc -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_cf_cc_t>(this->info, in);
    log("[end] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_cf_ex_t>(this->info, in);
          log("[end] cf_ex -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_cf_ex_t>(this->info, in);
    log("[end] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_cf_nw_t>(this->info, in);
          log("[end] cf_nw -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_cf_nw_t>(this->info, in);
    log("[end] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_rq_cc_t>(this->info, in);
          log("[end] rq_cc -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_rq_cc_t>(this->info, in);
    log("[end] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_rq_md_t>(this->info, in);
          log("[end] rq_md -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_rq_md_t>(this->info, in);
    log("[end] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_rq_nw_t>(this->info, in);
          log("[end] rq_nw -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_rq_nw_t>(this->info, in);
    log("[end] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState end::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error<st_end_t, in_timer_t>(this->info, in);
          log("[end] timer -> error", in, info, nw_st_info);
          
          return std::make_shared<error>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_end_t, in_timer_t>(this->info, in);
    log("[end] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_cf_cc_t>(this->info, in);
          log("[error] cf_cc -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_cf_cc_t>(this->info, in);
    log("[error] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_cf_ex_t>(this->info, in);
          log("[error] cf_ex -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_cf_ex_t>(this->info, in);
    log("[error] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_cf_nw_t>(this->info, in);
          log("[error] cf_nw -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_cf_nw_t>(this->info, in);
    log("[error] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_rq_cc_t>(this->info, in);
          log("[error] rq_cc -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_cc_t>(this->info, in);
    log("[error] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_rq_md_t>(this->info, in);
          log("[error] rq_md -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_md_t>(this->info, in);
    log("[error] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_rq_nw_t>(this->info, in);
          log("[error] rq_nw -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_rq_nw_t>(this->info, in);
    log("[error] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error_t, in_timer_t>(this->info, in);
          log("[error] timer -> error2", in, info, nw_st_info);
          act_rq_cc(this->info, in, nw_st_info);
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error_t, in_timer_t>(this->info, in);
    log("[error] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_cf_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_cf_cc_t>(this->info, in);
          log("[error2] cf_cc -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_cf_cc_t>(this->info, in);
    log("[error2] cf_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_cf_ex_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_cf_ex_t>(this->info, in);
          log("[error2] cf_ex -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_cf_ex_t>(this->info, in);
    log("[error2] cf_ex error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_cf_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_cf_nw_t>(this->info, in);
          log("[error2] cf_nw -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_cf_nw_t>(this->info, in);
    log("[error2] cf_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_rq_cc_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_rq_cc_t>(this->info, in);
          log("[error2] rq_cc -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_rq_cc_t>(this->info, in);
    log("[error2] rq_cc error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_rq_md_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_rq_md_t>(this->info, in);
          log("[error2] rq_md -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_rq_md_t>(this->info, in);
    log("[error2] rq_md error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_rq_nw_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_rq_nw_t>(this->info, in);
          log("[error2] rq_nw -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_rq_nw_t>(this->info, in);
    log("[error2] rq_nw error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }
  SState error2::input(const in_timer_t& in) {
    try {
       if(true ) {
          auto nw_st_info = from_in2error2<st_error2_t, in_timer_t>(this->info, in);
          log("[error2] timer -> error2", in, info, nw_st_info);
          
          return std::make_shared<error2>(nw_st_info);
       }
    } catch (...) {}
    
    auto nw_st_info = from_in2error<st_error2_t, in_timer_t>(this->info, in);
    log("[error2] timer error/default -> error", in, info, nw_st_info);
    return std::make_shared<error>(nw_st_info);
    
  }

} // namespace iceberg

