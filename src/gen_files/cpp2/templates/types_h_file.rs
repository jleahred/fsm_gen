pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//
//    generated on {{gen_time}}


#pragma once


// #include "types_forward.h"

namespace fsm_{{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct St{{st.name | ToCamel}}{};
  {% endfor -%}
  {{""}}


  //  input types

    //  provisinal code, delete it when replace the nexts usings
      {% for input in inputs -%}
      struct Provisional_In{{input | ToCamel }}{};
      {% endfor -%}
      {{""}}

    //  usings
    {% for input in inputs -%}
    using In{{input  | ToCamel }} = Provisional_In{{input  | ToCamel }};
    {% endfor -%}
    {{""}}


} // namespace {{in_file.stem_name}}

"#
}
