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
    {% set input_name = input.name -%}
    {%- if input.name == "_" -%} {% set input_name = "<*>" -%} {% endif -%}
    {{status.name}} -> {{t.new_status.name}} [label="{{input_name}}
    {%- if t.guards -%}
        {{" & "}}
    {%- else -%}
        {%- if input.transitions | length > 1 -%}
            {{"<*>"}}
        {%- endif -%}
    {%- endif -%}
    {%- for g in t.guards -%}
        {{" "}}
        {%- if g.positiv == false -%}{{"!"}}{%- endif -%}
        {{g.name}}
    {%- endfor -%}
    {%- if t.actions -%}{{" "}}\n{%- endif -%}
    {%- for a in t.actions -%}
        {{" "}}{{a}}
    {%- endfor -%}"]
{%- endfor -%}
{%- endfor -%}
{%- endfor %}

}
"#
}
