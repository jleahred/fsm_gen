pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  
//  forward declaration of types
//
//  do not modify it manually!!!
//    generated on {{gen_time}}

#pragma once


namespace fsm_{{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct {{st.name | ToCamel}};
  {% endfor -%}
  {{""}}


  //  transformers types

  {% for t in transformers -%}
  struct {{t | ToCamel }};
  {% endfor -%}
  {{""}}

} // namespace {{in_file.stem_name}}

"#
}
