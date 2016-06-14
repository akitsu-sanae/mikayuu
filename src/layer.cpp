/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/layer.hpp>
#include <mikayuu/drawable_object.hpp>

void mkyu::Layer::update() {
    on_update();

    for (auto&& o : m_drawable_objects)
        o->draw();
}

void mkyu::Layer::add_object(std::shared_ptr<mkyu::DrawableObject> const& obj) {
    m_drawable_objects.push_back(obj);
}


