pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on {{gen_time}}


#pragma once

// clang-format off

#include<variant>

#include"../types.h"
#include"../types_adapters_forward.h"

namespace fsm_{{in_file.stem_name}} {
  namespace impl {
  struct trans {    //  struct instead namespace, trick to dected dead code

  //  status change functions
  {% for t in transition_from_input_to -%}
  {%- if t.to != "_" -%}
  static std::variant<St{{ t.to | ToCamel }}, StError> to_{{t.to}}(const St{{ t.from | ToCamel }}& /*from*/, const In{{ t.input | ToCamel }}& /*{{t.input}}*/);
  {% endif -%}
  {% endfor -%}
  {{""}}


  //  with adapters
  {% for t in transition_adapters -%}
  static std::variant<St{{ t.to | ToCamel }}, StError> to_{{t.to}}(const adapt::trans::{{t.adapter_name | ToCamel}}& /*{{t.adapter_name}}*/);
  {% endfor -%}
  {{""}}


  //  status change functions 2 error
  {% for t in transition_from_input_to_error -%}
    static StError to_{{t.to}}(const St{{ t.from | ToCamel }}& /*from*/, const In{{ t.input | ToCamel }}& /*{{t.input}}*/);
  {% endfor -%}
  {{""}}

  };  //  struct trans
  } // namespace impl
} // namespace {{in_file.stem_name}}

// clang-format on

"#
}
