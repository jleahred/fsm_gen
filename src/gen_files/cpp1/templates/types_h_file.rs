pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on {{gen_time}}


#pragma once

#include "gen_fsm_{{in_file.stem_name}}_types_forward.hpp"

namespace {{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct st_{{st.name}}_t{};
  {% endfor -%}
  {{""}}


  //  input types

    //  provisinal code, delete it when replace the nexts usings
      {% for input in inputs -%}
      struct provisinal_in_{{input}}_t{};
      {% endfor -%}
      {{""}}

    //  usings
    {% for input in inputs -%}
    using in_{{input}}_t = provisinal_in_{{input}}_t;
    {% endfor -%}
    {{""}}


} // namespace {{in_file.stem_name}}

"#
}
