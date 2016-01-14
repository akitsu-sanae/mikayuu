#ifndef MIKAYUU_POLYGON_HPP
#define MIKAYUU_POLYGON_HPP

#include <array>
#include <mikayuu/color.hpp>
#include <mikayuu/vec.hpp>

namespace mkyu {

template<int N>
struct Polygon {
    std::array<vecd<2>, N> position = {};
    Color color = {};
    void draw() const;
};

}

#endif
