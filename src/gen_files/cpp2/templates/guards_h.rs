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
  
    {% for gi in guard_from_input -%}
    bool is_{{gi.guard}}(const st_{{gi.from}}_t& /*from*/, const in_{{gi.input}}_t& /*input*/);
    {% endfor -%}
    {{""}}

    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
