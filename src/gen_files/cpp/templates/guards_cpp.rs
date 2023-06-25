pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#include "guards.h"
#include "../types_adapters.h"

namespace fsm_{{in_file.stem_name}} {
    namespace impl {

        {% for gi in guard_from_input -%}
        bool guard::is_{{gi.guard}}(const St{{ gi.from | ToCamel }}& /*from*/, const In{{ gi.input  | ToCamel }}& /*{{gi.input}}*/){
            return true;        //  pending!
        }
        {% endfor -%}
        {{""}}
    
        //  with adapters
        {% for gt in guard_adapters -%}
        bool guard::is_{{gt.guard_name}}(const adapt::guard::{{gt.adapter_name | ToCamel}}& /*{{gt.adapter_name}}*/)
        {
            return true;        //  pending!
        }
        {% endfor -%}
        {{""}}
    
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
