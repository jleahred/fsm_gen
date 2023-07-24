pub(crate) fn t() -> &'static str {
    r#"
// clang-format off

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#include "{{in_file.stem_name}}.h"

#include "impl/actions.h"
#include "impl/guards.h"
#include "impl/transitions.h"
#include "types_adapters.h"

#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

namespace fsm_{{ in_file.stem_name }} {

class BaseState {
public:
  BaseState()  {}
  virtual ~BaseState() {}

 public:
   {% for input in inputs -%}
   virtual SState input(const In{{ input| ToCamel}}& in) = 0;
   {% endfor -%}
   {{""}}
 };


{% for status in ast %}
class {{status.name}} : public BaseState {
public:
  {{status.name}}(const St{{ status.name | ToCamel}}& i) : info(i) {}
  virtual ~{{status.name}}(){}

private:
  St{{ status.name| ToCamel}} info;

  {% for input in inputs -%}
  SState input(const In{{ input| ToCamel}}& in) override;
  {% endfor -%}
  {{""}}
};
{% endfor %}
{{""}}


Fsm::Fsm() : state(std::make_shared<init>(StInit{})) {}
Fsm::~Fsm() {}

{% for input in inputs -%}
void Fsm::process(const In{{ input| ToCamel}}& in) { state = state ->input(in); }
{% endfor -%}
{{""}}


{% for status in ast %}
{% for input in inputs -%}
SState {{status.name}}::input(const In{{ input| ToCamel}}& in) {
try {
    {%- for sinput in status.inputs -%}
    {% if sinput.name == input %}
    {% for transition in sinput.transitions -%}
    {% if transition.new_status.name != status.name or transition.actions  or true %}
    if(true
      {%- for guard in transition.guards %} 
      {% if not guard.adapter_name -%}
          && {% if not guard.positiv -%}!{% endif -%}impl::guard::is_{{guard.name}}(info, in)
      {% else -%}
          {% if not guard.positiv -%}!{% endif -%}
          && impl::guard::is_{{guard.name}}(adapt::guard::{{guard.adapter_name | ToCamel}}{info, in})
      {% endif -%}
      {%- endfor -%}
           ){
      {% if transition.new_status.name != "error"  %}
      {% if transition.new_status.name != "_"  %}
      {% if not transition.adapter_name -%}
      auto nw_st_info_or_error = impl::trans::to_{{transition.new_status.name}}(this->info, in);
      {% else -%}
      auto nw_st_info_or_error = impl::trans::to_{{transition.new_status.name}}(adapt::trans::{{transition.adapter_name | ToCamel}}{this->info, in});
      {% endif -%}
      {% endif -%}
      {% if transition.new_status.name != "_"  %}
      if(auto nw_st_info = std::get_if<St{{ transition.new_status.name | ToCamel}}>(&nw_st_info_or_error))
      {
      {% endif -%}
        //log(en_log_level::info, "[{{status.name}}] {{sinput.name}} -> {{transition.new_status.name}}", in, info, nw_st_info);
        {% for action in transition.actions -%}
        {% if not action.adapter_name -%}
        impl::act::{{action.name}}(this->info, in 
          {%- if transition.new_status.name != "_"  -%}, *nw_st_info{%- else  %} {%- endif -%}
        );
        {%- else -%}
        impl::act::{{action.name}}(adapt::act::{{action.adapter_name | ToCamel}}{this->info, in,
        {%- if transition.new_status.name != "_"  -%} *nw_st_info{%- else -%} this->info{%- endif -%}
        });
        {% endif -%}
        {% endfor %}
        return std::make_shared<
        {%- if transition.new_status.name != "_"  -%}{{transition.new_status.name}}{%- else -%}{{status.name}}{%- endif -%}                  
        >(
          {%- if transition.new_status.name != "_"  -%}*nw_st_info{%- else -%}this->info{%- endif -%}          
        );
      {% if transition.new_status.name != "_"  %}
      } else if(auto nw_st_info = std::get_if<StError>(&nw_st_info_or_error)){
          //log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
          return std::make_shared<error>(*nw_st_info);
      }
      {% endif -%}
      {% else -%}
      auto nw_st_info = impl::trans::to_error(this->info, in);
      //log(en_log_level::info, "[{{status.name}}] {{sinput.name}} -> {{transition.new_status.name}}", in, info, nw_st_info);
      {% for action in transition.actions -%}
      {% if not action.adapter_name -%}
      impl::act::{{action.name}}(this->info, in, nw_st_info);
      {% else -%}
      impl::act::{{action.name}}(adapt::act::{{action.adapter_name | ToCamel}}{this->info, in, nw_st_info});
      {% endif -%}
      {% endfor %}
      return std::make_shared<{{transition.new_status.name}}>(nw_st_info);
      {% endif %}
    }
    {% endif -%}
    {% endfor -%}
    {% endif -%}
    {% endfor %}
} catch (...) {}

auto nw_st_info = impl::trans::to_error(this->info, in);
//log(en_log_level::critic, "[{{status.name}}] {{input}} error/default -> error", in, info, nw_st_info);
return std::make_shared<error>(nw_st_info);
}
{% endfor -%}
{% endfor %}
{{""}}

}

#pragma GCC diagnostic pop

// clang-format on
"#
}
