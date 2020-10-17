use crate::gen_files::sup::*;
use crate::gen_files::Context;

pub(super) fn generate_files(context: &Context) -> std::result::Result<(), String> {
    generate_file(context, &get_full_name(context), template())?;
    Ok(())
}

fn get_full_name(context: &Context) -> String {
    format!("{}/{}.dot", context.in_file.dir, context.in_file.stem_name)
}

pub(crate) fn template() -> &'static str {
    r#"
//  generated automatically  {{gen_time}}

digraph finite_state_machine {
    rankdir=LR;
    size="8,5"
    node [shape = circle, width=1];

{% for status in ast -%}
{%- for input in status.inputs -%}
{%- for t in input.transitions %}
    {% if status.name != t.new_status.name  or t.actions %}
    {{status.name}} -> {{t.new_status.name}} [label="{{input.name}}
    {%- if t.actions -%}{{" "}}/ {%- endif -%}
    {%- for a in t.actions -%}
    {{" "}}{{a}}
    {%- endfor -%}"]
    {% endif %}
{%- endfor -%}
{%- endfor -%}
{%- endfor %}

}
"#
}
