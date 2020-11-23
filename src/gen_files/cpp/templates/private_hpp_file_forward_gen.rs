pub(crate) fn t() -> &'static str {
    // {{__tera_context}}

    r#"
//  generated automatically  {{ gen_time }}
//  do not modify it manually

//  This file will be included in private_hpp_file.hpp

#pragma once
//  to make happy some IDEs -----
#include "gen_fsm_{{in_file.stem_name}}_types_forward.hpp"
#include "gen_fsm_{{in_file.stem_name}}.h"
//  to make happy some IDEs -----

#include<variant>

namespace {
    using namespace {{in_file.stem_name}};

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &);

    //  status change functions
    //  you can specialize this generic functions
    template <typename FROM_ST, typename IN, typename TO_ST>
    std::variant<TO_ST, st_error_t> fromin2(const FROM_ST &, const IN &);

    template <typename FROM_ST, typename IN>
    st_error_t fromin2error(const FROM_ST &, const IN &);
    
    //  guards
    {% for gi in guard_inputs -%}
    template<typename FROM_ST>
    bool {{gi.guard}}(const in_{{gi.input}}_t& input, const FROM_ST&);
    {% endfor -%}
    {{""}}

    //  actions
    {% for ai in action_inputs -%}
    template<typename FROM_ST, typename TO_ST>
    void act_{{ai.action}}(const FROM_ST&, const in_{{ai.input}}_t& input, const TO_ST&);
    {% endfor -%}
    {{""}}

} // namespace anonymous

"#
}
