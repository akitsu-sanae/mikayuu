/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_POLYGON_CONTAINER_HPP
#define MIKAYUU_POLYGON_CONTAINER_HPP

#include <vector>
#include <mikayuu/object.hpp>
#include <mikayuu/polygon.hpp>

namespace mkyu {

template<int N>
struct PolygonContainer : public mkyu::Object {

    void add(mkyu::Polygon<N> const& poly) {
        m_objects.push_back(poly);
    }
    void draw() const {
        for (auto&& e : m_objects)
            e.draw();
    }
    template<typename F>
    void for_each(F const& f) const {
        for (auto&& e : m_objects)
            f(e);
    }
private:
    std::vector<Polygon<N>> m_objects;
};

}

#endif
