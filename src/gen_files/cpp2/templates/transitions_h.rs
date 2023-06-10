pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#pragma once

// clang-format off

#include<variant>
#include"../types.hpp"

namespace fsm_{{in_file.stem_name}} {
  namespace impl {


  //  status change functions
  {% for t in transition_from_input_to -%}
    std::variant<st_{{t.to}}_t, st_error_t> transition_2{{t.to}}(const st_{{t.from}}_t& /*from*/, const in_{{t.input}}_t& /*input*/);
  {% endfor -%}
  {{""}}

  //  status change functions 2 error
  {% for t in transition_from_input_to_error -%}
    st_error_t transition_2{{t.to}}(const st_{{t.from}}_t& /*from*/, const in_{{t.input}}_t& /*input*/);
  {% endfor -%}
  {{""}}


  } // namespace impl
} // namespace {{in_file.stem_name}}

// clang-format on

"#
}
