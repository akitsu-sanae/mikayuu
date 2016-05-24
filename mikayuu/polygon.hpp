#ifndef MIKAYUU_POLYGON_HPP
#define MIKAYUU_POLYGON_HPP

#include <array>
#include <mikayuu/color.hpp>
#include <mikayuu/vec.hpp>

namespace mkyu {

template<int N>
struct Polygon {
    enum class BlendMode {
        None,
        Alpha,
        Reverse,
        Add,
        Screen,
        Mult
    };

    std::array<vecd<2>, N> position = {};
    Color color = {};
    BlendMode blend_mode = BlendMode::None;

    BlendMode blend() const { return blend_mode; }
    void blend(BlendMode mode) { blend_mode = mode; }
    void draw() const;

    void do_blend() const;

};

}

#endif
