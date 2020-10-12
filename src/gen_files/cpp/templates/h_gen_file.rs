pub(crate) fn t() -> &'static str {
    r#"
/*
{{ __tera_context }}
*/

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "fsm_{{ in_file.stem_name }}_types.h"

namespace {{ in_file.stem_name }} {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    {% for input in inputs -%}
    void process(const in_{{ input }}_t &in);
    {% endfor -%}
    {{""}}
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace {{ in_file.stem_name }}
"#
}
