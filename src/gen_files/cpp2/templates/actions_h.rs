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
    struct act {        //  struct instead of action, trick to detect dead code  ;-)

    //  actions
    {% for ai in action_to -%}
    static void {{ai.action}}(const St{{ ai.to  | ToCamel }}& to);
    {% endfor -%}
    {{""}}

    };  //  struct act
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
