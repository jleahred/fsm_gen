pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#include "transitions.h"
#include "../types_transformers.h"

#include<variant>

namespace fsm_{{in_file.stem_name}} {
  namespace impl {


//  status change functions
{% for t in transition_from_input_to -%}
std::variant<St{{ t.to | ToCamel}}, StError> trans::to_{{t.to}}(const St{{ t.from | ToCamel }}& /*from*/, const In{{ t.input | ToCamel }}& /*{{t.input}}*/)
{
  //  pending
  return St{{ t.to | ToCamel }}{};
}
{% endfor -%}
{{""}}

//  status change functions 2 error
{% for t in transition_from_input_to_error -%}
StError trans::to_{{t.to}}(const St{{ t.from | ToCamel }}& /*from*/, const In{{ t.input | ToCamel }}& /*{{t.input}}*/)
{
  //  pending
  return StError{};
}
{% endfor -%}
{{""}}


  } // namespace impl
} // namespace {{in_file.stem_name}}

// clang-format on

    
"#
}
