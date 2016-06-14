/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

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

    explicit Polygon(vec2d const& position, std::array<vec2d, N> const& nodes, Color const& c) :
        DrawableObject(position),
        nodes(nodes),
        color(c)
    {}
    std::array<vecd<2>, N> nodes = {};
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
