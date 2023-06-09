pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#pragma once


#include<variant>
#include<iostream>

namespace {{in_file.stem_name}} {

    //  actions
    {% for ai in action_inputs -%}
    template<typename FROM_ST, typename TO_ST>
    void act_{{ai.action}}(const FROM_ST&, const in_{{ai.input}}_t& /*input*/, const TO_ST&) {}
    {% endfor -%}
    {{""}}

} // namespace {{in_file.stem_name}}

"#
}
