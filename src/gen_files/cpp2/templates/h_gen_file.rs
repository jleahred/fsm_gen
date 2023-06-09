pub(crate) fn t() -> &'static str {
    r#"
// clang-format off

//  generated automatically  {{ gen_time }}
//  do not modify it manually

#pragma once

#include <iostream>
#include <memory>

#include "fsm/{{ in_file.stem_name }}_types.hpp"

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

// clang-format on
"#
}
