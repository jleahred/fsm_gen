pub(crate) fn t() -> &'static str {
    r#"
// clang-format off

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#include "gen_fsm_{{in_file.stem_name}}.h"

#include "fsm_{{in_file.stem_name}}_private.hpp"

#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

namespace {{ in_file.stem_name }} {

  class BaseState {
  public:
    BaseState()  {}
    virtual ~BaseState() {}

   public:
     {% for input in inputs -%}
     virtual SState input(const in_{{input}}_t& in) = 0;
     {% endfor -%}
     {{""}}
   };


  {% for status in ast %}
  class {{status.name}} : public BaseState {
  public:
    {{status.name}}(const st_{{status.name}}_t& i) : info(i) {}
    virtual ~{{status.name}}(){}

  private:
    st_{{status.name}}_t info;

    {% for input in inputs -%}
    SState input(const in_{{input}}_t& in) override;
    {% endfor -%}
    {{""}}
  };
  {% endfor %}
  {{""}}


Fsm::Fsm() : state(std::make_shared<init>(st_init_t{})) {}
Fsm::~Fsm() {}

{% for input in inputs -%}
void Fsm::process(const in_{{input}}_t& in) { state = state ->input(in); }
{% endfor -%}
{{""}}


{% for status in ast %}
{% for input in inputs -%}
SState {{status.name}}::input(const in_{{input}}_t& in) {
  try {
      {%- for sinput in status.inputs -%}
      {% if sinput.name == input %}
      {% for transition in sinput.transitions -%}
      {% if transition.new_status.name != status.name or transition.actions  or true %}
      if(true
        {%- for guard in transition.guards %} && {% if not guard.positiv %}!{%endif%}{{guard.name}}(in, info)
        {%- endfor -%}
             ){
        {% if transition.new_status.name != "error"%}
        auto nw_st_info_or_error = fromin2_{{transition.new_status.name}}<st_{{status.name}}_t, in_{{sinput.name}}_t>(this->info, in);
        if(auto nw_st_info = std::get_if<st_{{transition.new_status.name}}_t>(&nw_st_info_or_error))
        {
          log(en_log_level::info, "[{{status.name}}] {{sinput.name}} -> {{transition.new_status.name}}", in, info, nw_st_info);
          {% for action in transition.actions -%}
          act_{{action}}(this->info, in, nw_st_info);
          {% endfor %}
          return std::make_shared<{{transition.new_status.name}}>(*nw_st_info);
        } else if(auto nw_st_info = std::get_if<st_error_t>(&nw_st_info_or_error)){
            log(en_log_level::info, "[init] rq_key -> error", in, info, nw_st_info);
            return std::make_shared<error>(*nw_st_info);
        }
        {% else %}
        auto nw_st_info = fromin2_error<st_{{status.name}}_t, in_{{sinput.name}}_t>(this->info, in);
        log(en_log_level::info, "[{{status.name}}] {{sinput.name}} -> {{transition.new_status.name}}", in, info, nw_st_info);
        {% for action in transition.actions -%}
        act_{{action}}(this->info, in, nw_st_info);
        {% endfor %}
        return std::make_shared<{{transition.new_status.name}}>(nw_st_info);
        {% endif %}
      }
      {% endif -%}
      {% endfor -%}
      {% endif -%}
      {% endfor %}
  } catch (...) {}

  auto nw_st_info = fromin2_error<st_{{status.name}}_t, in_{{input}}_t>(this->info, in);
  log(en_log_level::critic, "[{{status.name}}] {{input}} error/default -> error", in, info, nw_st_info);
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
