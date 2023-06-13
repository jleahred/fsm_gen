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
    void act::{{ai.action}}(const St{{ ai.from  | ToCamel }}& /*from*/, const In{{ ai.input  | ToCamel }}& /*{{ai.input}}*/, const St{{ ai.to  | ToCamel }}& /*to*/)
    {
    }
    {% endfor -%}
    {{""}}

    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
