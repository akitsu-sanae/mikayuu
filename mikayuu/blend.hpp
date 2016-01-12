#ifndef MIKAYUU_BLEND_HPP
#define MIKAYUU_BLEND_HPP

namespace mkyu {

enum class BlendMode {
    None,
    Alpha,
    Reverse,
    Add,
    Screen,
    Mult
};

void blend(BlendMode);
BlendMode blend();

namespace detail {
void do_blend();
}

}


#endif
