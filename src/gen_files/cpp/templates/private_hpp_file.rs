pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}

//  This file will be included in gen_fsm_{{in_file.stem_name}}.cpp
//  (anywhere else)

#pragma once

#include "gen_fsm_{{in_file.stem_name}}_private_forward.hpp"

//  to make happy some IDEs -----
#include "fsm_{{in_file.stem_name}}_types.h"
#include "gen_fsm_{{in_file.stem_name}}.h"
//  to make happy some IDEs -----

#include<variant>

namespace {
    using namespace {{in_file.stem_name}};

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << txt_trans << std::endl;
    }

    //  status change functions
    template <typename FROM, typename IN, typename TO>
    std::variant<TO, st_error_t> fromin2(const FROM &, const IN &) {
        //  you can specialize or overload this generic function (not both)
        return TO{};
    }
    template <typename FROM, typename IN>
    st_error_t fromin2error(const FROM &, const IN &) {
      return st_error_t{};
    }
    

    //  guards
    {% for gi in guard_inputs -%}
    template<typename FROM_ST>
    bool {{gi.guard}}(const in_{{gi.input}}_t& /*input*/, const FROM_ST&) { return true; }
    {% endfor -%}
    {{""}}

    //  actions
    {% for ai in action_inputs -%}
    template<typename FROM_ST, typename TO_ST>
    void act_{{ai.action}}(const FROM_ST&, const in_{{ai.input}}_t& /*input*/, const TO_ST&) {}
    {% endfor -%}
    {{""}}

} // namespace anonymous

"#
}
