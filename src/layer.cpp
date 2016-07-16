/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/layer.hpp>
#include <mikayuu/object.hpp>

void mkyu::Layer::draw() const {
    for (auto const& obj: m_objects)
        obj->draw();
}

void mkyu::Layer::update() {
    on_update();

    for (auto&& o : m_objects)
        o->update();
}

void mkyu::Layer::add_object(mkyu::ptr<mkyu::Object> const& obj) {
    m_objects.push_back(obj);
}


