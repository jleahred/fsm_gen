pub(crate) fn t() -> &'static str {
    r#"
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
//  but a file with same name ended wiht .reference will be created always
//    generated on {{gen_time}}

//  This file will be included in _gen.cpp
//  (anywhere else)

//  to make happy some IDEs -----
#include "fsm_{{in_file.stem_name}}_types.h"
#include "fsm_{{in_file.stem_name}}_gen.h"
//  to make happy some IDEs -----

namespace {
    using namespace {{in_file.stem_name}};

    //  log
    template <typename IN, typename INIT_ST, typename END_ST>
    void log(const std::string &txt_trans, const IN &, const INIT_ST &,
            const END_ST &) {
        std::cout << txt_trans << std::endl;
    }

    //  status change functions
    {% for st in ast -%}
    template <typename FROM, typename IN> st_{{st.name}}_t from_in2{{st.name}}(const FROM&, const IN&) { return st_{{st.name}}_t{}; }
    {% endfor -%}
    {{""}}

    //  guards
    {% for st in ast -%}
    {% for i in st.inputs -%}
    {% for t in i.transitions -%}
    {% for g in t.guards -%}
    bool {{g.name}}(const in_{{i.name}}_t& /*in*/, const st_{{st.name}}_t& /*st_from*/) { return true; }
    {% endfor -%}
    {% endfor -%}
    {% endfor -%}
    {% endfor -%}
    {{""}}

    //  actions
    {% for st in ast -%}
    {% for i in st.inputs -%}
    {% for t in i.transitions -%}
    {% for action in t.actions -%}
    void act_{{action}}(const st_{{st.name}}_t& /*from*/, const in_{{i.name}}_t& /*input*/, const st_{{t.new_status.name}}_t& /*st_dest*/) {}
    {% endfor -%}
    {% endfor -%}
    {% endfor -%}
    {% endfor %}

} // namespace anonymous

"#
}
