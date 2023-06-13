pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#pragma once

#include "../types.hpp"


namespace fsm_{{in_file.stem_name}} {
    namespace impl {
    struct guard {      //  struct instead of namespace, trick to detect dead code
  
    {% for gi in guard_from_input -%}
    static bool is_{{gi.guard}}(const St{{ gi.from | ToCamel }}& /*from*/, const In{{ gi.input  | ToCamel }}& /*{{gi.input}}*/);
    {% endfor -%}
    {{""}}

    };  //  struct guard
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
