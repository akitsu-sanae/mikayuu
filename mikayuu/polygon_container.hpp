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

struct Container : public mkyu::Object {

    void add(mkyu::ptr<Object> const& obj) {
        m_objects.push_back(obj);
    }
    void update() {
        for (auto&& obj: m_objects)
            obj->update();
    }
    void draw() const {
        for (auto const& e : m_objects)
            e->draw();
    }
    template<typename F>
    void for_each(F const& f) const {
        for (auto&& e : m_objects)
            f(e);
    }
private:
    mkyu::container<mkyu::Object> m_objects;
};

}

#endif
