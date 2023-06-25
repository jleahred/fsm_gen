pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on {{gen_time}}


#pragma once

#include "../types.h"
#include"../types_adapters_forward.h"

namespace fsm_{{in_file.stem_name}} {
    namespace impl {
    struct guard {      //  struct instead of namespace, trick to detect dead code
  
    {% for gi in guard_from_input -%}
    static bool is_{{gi.guard}}(const St{{ gi.from | ToCamel }}& /*from*/, const In{{ gi.input  | ToCamel }}& /*{{gi.input}}*/);
    {% endfor -%}
    {{""}}

    //  with adapters
    {% for gt in guard_adapters -%}
    static bool is_{{gt.guard_name}}(const adapt::guard::{{gt.adapter_name | ToCamel}}& /*{{gt.adapter_name}}*/);
    {% endfor -%}
    {{""}}

    };  //  struct guard
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
