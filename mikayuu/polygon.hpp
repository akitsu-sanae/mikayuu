/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_POLYGON_HPP
#define MIKAYUU_POLYGON_HPP

#include <array>
#include <mikayuu/object.hpp>
#include <mikayuu/color.hpp>
#include <mikayuu/vector.hpp>
#include <mikayuu/blend_mode.hpp>

namespace mkyu {

template<int N>
struct Polygon final : public mkyu::Object {

    explicit Polygon(vector2d const& position, std::array<vector2d, N> const& nodes, Color const& c) :
        Object(position),
        nodes(nodes),
        color(c)
    {}
    std::array<vector2d, N> nodes = {};
    Color color = {};
    BlendMode blend_mode = BlendMode::None;

    BlendMode blend() const { return blend_mode; }
    void blend(BlendMode mode) { blend_mode = mode; }
    void update() override {}
    void draw() const override;

    void do_blend() const;

};

using Triangle = Polygon<3>;
using Rectangle = Polygon<4>;

}

#endif
