pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  but a file with same name ended wiht .reference will be created always
//    generated on {{gen_time}}


#pragma once

namespace {{in_file.stem_name}} {

  //  status info types

  {% for st in ast -%}
  struct st_{{st.name}}_t{};
  {% endfor -%}
  {{""}}


  //  input types

    {% for input in inputs -%}
    struct in_{{input}}_t{};
    {% endfor -%}
    {{""}}

} // namespace {{in_file.stem_name}}

"#
}
