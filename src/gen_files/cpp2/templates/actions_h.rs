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


#include "../types.h"


namespace fsm_{{in_file.stem_name}} {
    namespace impl {
    struct act {        //  struct instead of action, trick to detect dead code  ;-)

    //  actions
    {% for ai in action_init_param_to -%}
    {% if not ai.action.transformer_name -%}
    static void {{ai.action.name}}(const St{{ ai.from | ToCamel }}& from, const In{{ai.input | ToCamel }}& {{ai.input}}, const St{{ ai.to  | ToCamel }}& to);
    {% else -%}
    static void {{ai.action.name}}(const transf::act::{{ai.action.transformer_name | ToCamel}}& /*p*/);
    {% endif -%}
    {% endfor -%}
    {{""}}

    };  //  struct act
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
