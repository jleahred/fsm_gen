pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically as reference file
//  Do not modify manually, it will be generated on each execution
//  This file will  be updated by generator
//
//    generated on {{gen_time}}
    
#pragma once


namespace fsm_{{in_file.stem_name}} {

  //  status info types    -----------------------------------------------

{% for st in ast -%}
struct St{{st.name | ToCamel}}{};
{% endfor -%}
{{""}}


//  input types   ------------------------------------------------------

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


//  adapters types   -----------------------------------------------
namespace adapt {

//  -------------------------------------------------------
namespace act {

{% for k, vparams in adapters.actions -%}
struct {{k | ToCamel -}} {
  {% for vp in vparams -%} 
    {{k | ToCamel -}}({% for p in vp -%} 
    const {% if p.kind == "Status" -%}
    St{{p.name | ToCamel -}}& 
    {%- else -%}
    In{{p.name | ToCamel -}}&{% endif -%}{% if not loop.last%}, {% endif -%}{% endfor -%}
  ) {};
  {% endfor -%}
};
{% endfor -%}
} //  namespace act

//  -------------------------------------------------------
namespace guard {

{% for k, vparams in adapters.guards -%}
struct {{k | ToCamel -}} {
  {% for vp in vparams -%} 
    {{k | ToCamel -}}({% for p in vp -%} 
    const {% if p.kind == "Status" -%}
    St{{p.name | ToCamel -}}& {% else -%}
    In{{p.name | ToCamel -}}&{% endif -%}{% if not loop.last%}, {% endif -%}{% endfor -%}
  ) {};
  {% endfor -%}
};
{% endfor -%}
} //  namespace guard

//  -------------------------------------------------------
namespace trans {

{% for k, vparams in adapters.transitions -%}
struct {{k | ToCamel -}} {
  {% for vp in vparams -%} 
    {{k | ToCamel -}}({% for p in vp -%} 
    const {% if p.kind == "Status" -%}
    St{{p.name | ToCamel -}}& {% else -%}
    In{{p.name | ToCamel -}}&{% endif -%}{% if not loop.last%}, {% endif -%}{% endfor -%}
  ) {};
  {% endfor -%}
};
{% endfor -%}
} //  namespace trans

} //  namespace adapt

} // namespace {{in_file.stem_name}}

"#
}
