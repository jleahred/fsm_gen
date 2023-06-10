//    {{ast | json_encode(pretty=true)}}
//    {{inputs | json_encode(pretty=true)}}
//    {{guard_inputs | json_encode(pretty=true)}}

pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on {{gen_time}}


#pragma once


#include "../types.hpp"


namespace fsm_{{in_file.stem_name}} {
    namespace impl {

    //  actions
    {% for ai in action_init_param_to -%}
    void act_{{ai.action}}(const st_{{ai.from}}_t& /*from*/, const in_{{ai.input}}_t& /*input*/, const st_{{ai.to}}_t& /*to*/);
    {% endfor -%}
    {{""}}

    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
