pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#include "guards.h"

#include "../types.h"

namespace fsm_{{in_file.stem_name}} {
    namespace impl {

        {% for gi in guard_from_input -%}
        static bool is_{{gi.guard}}(const St{{ gi.from | ToCamel }}& /*from*/, const In{{ gi.input  | ToCamel }}& /*{{gi.input}}*/){
            return true;        //  pending!
        }
        {% endfor -%}
        {{""}}
    
        //  with transformers
        {% for gt in guard_transformers -%}
        static bool is_{{gt.guard_name}}(const transf::{{gt.transformer_name | ToCamel}}& /*{{gt.transformer_name}}*/)
        {
            return true;        //  pending!
        }
        {% endfor -%}
        {{""}}
    
    } // namespace impl
} // namespace {{in_file.stem_name}}

"#
}
