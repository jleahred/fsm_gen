pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}


#pragma once

#include<variant>
#include<iostream>

namespace {{in_file.stem_name}} {

  //  status change functions
  {% for st in ast -%}
  {% if st.name != "error" %}
  template <typename FROM, typename IN>
  std::variant<st_{{st.name}}_t, st_error_t> fromin2_{{st.name}}(const FROM &, const IN &) {
      //  you can specialize or overload this generic function (not both)
      return st_{{st.name}}_t{};
  }
  {% endif %}
  {% endfor -%}
  {{""}}

  template <typename FROM, typename IN>
  st_error_t fromin2_error(const FROM &, const IN &) {
    return st_error_t{};
  }

} // namespace {{in_file.stem_name}}

"#
}
