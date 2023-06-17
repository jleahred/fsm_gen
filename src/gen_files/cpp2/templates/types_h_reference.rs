pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
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


  //  transformers types   -----------------------------------------------
namespace transf {

//  -------------------------------------------------------
namespace act {

{% for k, vparams in transformers.actions -%}
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
} //  namespace act

//  -------------------------------------------------------
namespace guard {

{% for k, vparams in transformers.guards -%}
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

{% for k, vparams in transformers.transitions -%}
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

} //  namespace transf

} // namespace {{in_file.stem_name}}

"#
}
