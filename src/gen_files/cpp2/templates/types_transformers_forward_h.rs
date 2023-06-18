pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically
//  DO NOT modif. It will be rewritten on each generation
//
//    generated on {{gen_time}}
        
#pragma once


namespace fsm_{{in_file.stem_name}} {

  //  transformers types  forward decl -----------------------------------------
  namespace transf {
  
  //  -------------------------------------------------------
  namespace act {
  
  {% for k, vparams in transformers.actions -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace act
  
  //  -------------------------------------------------------
  namespace guard {
  
  {% for k, vparams in transformers.guards -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace guard
  
  //  -------------------------------------------------------
  namespace trans {
  
  {% for k, vparams in transformers.transitions -%}
  struct {{k | ToCamel -}};
  {% endfor -%}
  } //  namespace trans
  
  } //  namespace transf

} // namespace {{in_file.stem_name}}

"#
}
