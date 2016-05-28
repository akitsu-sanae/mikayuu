#ifndef MIKAYUU_POLYGON_HPP
#define MIKAYUU_POLYGON_HPP

#include <array>
#include <mikayuu/drawable_object.hpp>
#include <mikayuu/color.hpp>
#include <mikayuu/vec.hpp>

namespace mkyu {

template<int N>
struct Polygon : public mkyu::DrawableObject {
    enum class BlendMode {
        None,
        Alpha,
        Reverse,
        Add,
        Screen,
        Mult
    };

    explicit Polygon(std::array<vec2d, N> const& position, Color const& c) :
        position(position),
        color(c)
    {}
    std::array<vecd<2>, N> position = {};
    Color color = {};
    BlendMode blend_mode = BlendMode::None;

    BlendMode blend() const { return blend_mode; }
    void blend(BlendMode mode) { blend_mode = mode; }
    void draw() const;

    void do_blend() const;

};

using Triangle = Polygon<3>;
using Rectangle = Polygon<4>;

}

#endif
