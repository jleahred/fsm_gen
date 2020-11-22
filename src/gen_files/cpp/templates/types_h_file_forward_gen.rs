pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  
//  forward declaration of types
//
//    generated on {{gen_time}}


#pragma once

namespace {{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct st_{{st.name}}_t;
  {% endfor -%}
  {{""}}


  //  input types

    {% for input in inputs -%}
    struct in_{{input}}_t;
    {% endfor -%}
    {{""}}

} // namespace {{in_file.stem_name}}

"#
}
