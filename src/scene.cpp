/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/scene.hpp>
#include <mikayuu/game.hpp>
#include <mikayuu/layer.hpp>

void mkyu::Scene::update() {
    on_update();

    for (auto&& l : m_layers)
        l->update();
}

void mkyu::Scene::add_layer(mkyu::ptr<mkyu::Layer> const& layer) {
    m_layers.push_back(layer);
}

