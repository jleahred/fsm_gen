pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#include "actions.h"

#include "../types.h"


namespace fsm_{{in_file.stem_name}} {
    namespace impl {
    
        //  actions

        {% for ai in action_init_param_to -%}
        static void act::{{ai.action.name}}(const St{{ ai.from | ToCamel }}& from, const In{{ai.input | ToCamel }}& {{ai.input}}, const St{{ ai.to  | ToCamel }}& to)
        {
        }
        {% endfor -%}
        {{""}}
    
        //  with transformers
        {% for at in action_transformers -%}
        static void act::{{at.action_name}}(const transf::act::{{at.transformer_name | ToCamel}}& /*{{at.transformer_name}}*/)
        {
        }
        {% endfor -%}
        {{""}}
    
        } // namespace impl
    } // namespace {{in_file.stem_name}}
    
"#
}
