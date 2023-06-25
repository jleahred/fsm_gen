pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on {{gen_time}}
        
#pragma once


namespace fsm_{{in_file.stem_name}} {

  //  adapters types  forward decl -----------------------------------------
  namespace adapt {
  
  //  -------------------------------------------------------
  namespace act {
  
  {% for k, vparams in adapters.actions -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace act
  
  //  -------------------------------------------------------
  namespace guard {
  
  {% for k, vparams in adapters.guards -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace guard
  
  //  -------------------------------------------------------
  namespace trans {
  
  {% for k, vparams in adapters.transitions -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace trans
  
  } //  namespace adapt

} // namespace {{in_file.stem_name}}

"#
}
