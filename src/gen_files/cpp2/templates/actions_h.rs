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

//  actions     ----------------------------------------------


namespace fsm_{{in_file.stem_name}} {
    namespace impl {
    struct act {        //  struct instead of action, trick to detect dead code  ;-)

    {% for ai in action_init_param_to -%}
    static void {{ai.action.name}}(const St{{ ai.from | ToCamel }}& from, const In{{ai.input | ToCamel }}& {{ai.input}}, const St{{ ai.to  | ToCamel }}& to);
    {% endfor -%}
    {{""}}

    //  with transformers
    {% for at in action_transformers -%}
    static void {{at.action_name}}(const transf::act::{{at.transformer_name | ToCamel}}& /*{{at.action_name}}*/);
    {% endfor -%}
    {{""}}

    };  //  struct act
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
