pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#include "actions.h"

#include "../types.hpp"


namespace fsm_{{in_file.stem_name}} {
    namespace impl {

    //  actions
    {% for ai in action_init_param_to -%}
    void act_{{ai.action}}(const st_{{ai.from}}_t& /*from*/, const in_{{ai.input}}_t& /*input*/, const st_{{ai.to}}_t& /*to*/)
    {
    }
    {% endfor -%}
    {{""}}

    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
