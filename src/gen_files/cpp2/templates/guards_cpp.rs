pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


//#include "gen_fsm_{{in_file.stem_name}}_private_forward.hpp"

#include<variant>
#include<iostream>

namespace {{in_file.stem_name}} {

    {% for gi in guard_inputs -%}
    template<typename FROM_ST>
    bool {{gi.guard}}(const in_{{gi.input}}_t& /*input*/, const FROM_ST&) { return true; }
    {% endfor -%}
    {{""}}

} // namespace anonymous

"#
}
