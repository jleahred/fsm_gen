pub(crate) fn t() -> &'static str {
    r#"
// clang-format off

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#include "fsm_{{in_file.stem_name}}_gen.h"

#include "fsm_{{in_file.stem_name}}_private.hpp"

namespace {{ in_file.stem_name }} {

  class BaseState {
  public:
    BaseState()  {}
    ~BaseState() {}

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
      {% if transition.new_status.name != status.name or transition.actions %}
      if(true
        {%- for guard in transition.guards %} && {{guard.name}}(in, info)
        {%- endfor -%}
             ){
        auto nw_st_info = from_in2{{transition.new_status.name}}<st_{{status.name}}_t, in_{{sinput.name}}_t>(this->info, in);
        log("[{{status.name}}] {{sinput.name}} -> {{transition.new_status.name}}", in, info, nw_st_info);
        {% for action in transition.actions -%}
        act_{{action}}(this->info, in, nw_st_info);
        {% endfor %}
        return std::make_shared<{{transition.new_status.name}}>(nw_st_info);
      }
      {% endif -%}
      {% endfor -%}
      {% endif -%}
      {% endfor %}
  } catch (...) {}

  auto nw_st_info = from_in2error<st_{{status.name}}_t, in_{{input}}_t>(this->info, in);
  log("[{{status.name}}] {{input}} error/default -> error", in, info, nw_st_info);
  return std::make_shared<error>(nw_st_info);
}
{% endfor -%}
{% endfor %}
{{""}}

}

// clang-format on
"#
}
