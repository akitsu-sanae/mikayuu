#ifndef MIKAYUU_POLYGON_HPP
#define MIKAYUU_POLYGON_HPP

#include <array>
#include <mikayuu/color.hpp>
#include <mikayuu/vec2d.hpp>

namespace mkyu {

template<int N>
struct Polygon {
    std::array<vec2d, N> position = {};
    Color color = {};
    void draw() const;
};

}

#endif
