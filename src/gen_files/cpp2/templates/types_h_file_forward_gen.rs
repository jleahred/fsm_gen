pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  
//  forward declaration of types
//
//  do not modify it manually!!!
//    generated on {{gen_time}}

#pragma once



namespace {{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct st_{{st.name}}_t;
  {% endfor -%}
  {{""}}

} // namespace {{in_file.stem_name}}

"#
}
