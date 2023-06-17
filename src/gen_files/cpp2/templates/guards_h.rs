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
    struct guard {      //  struct instead of namespace, trick to detect dead code
  
    {% for gi in guard_from_input -%}
    static bool is_{{gi.guard}}(const St{{ gi.from | ToCamel }}& /*from*/, const In{{ gi.input  | ToCamel }}& /*{{gi.input}}*/);
    {% endfor -%}
    {{""}}

    //  with transformers
    {% for gt in guard_transformers -%}
    static bool is_{{gt.guard_name}}(const transf::guard::{{gt.transformer_name | ToCamel}}& /*{{gt.transformer_name}}*/);
    {% endfor -%}
    {{""}}

    };  //  struct guard
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
