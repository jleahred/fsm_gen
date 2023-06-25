pub(crate) fn t() -> &'static str {
    r#"
// clang-format off

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "types.h"


namespace fsm_{{ in_file.stem_name }} {

class BaseState;
typedef std::shared_ptr<BaseState> SState;

//  -------------------
//      F S M
class Fsm {
public:
    Fsm();
    ~Fsm();

    {% for input in inputs -%}
    void process(const In{{ input | ToCamel }} &{{input}});
    {% endfor -%}
    {{""}}
private:
    SState state;
};

//      F S M
//  -------------------

} // namespace {{ in_file.stem_name }}

// clang-format on
"#
}
