pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//
//    generated on {{gen_time}}
    
#pragma once

#include "types.h"

namespace fsm_{{in_file.stem_name}} {

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
