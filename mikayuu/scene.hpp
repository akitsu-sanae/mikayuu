/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_SCENE_HPP
#define MIKAYUU_SCENE_HPP

#include <algorithm>
#include <vector>
#include <memory>

#include <mikayuu/layer.hpp>
#include <mikayuu/utility.hpp>

namespace mkyu {

struct Game;

struct Scene {
    explicit Scene(Game const& game, GLFWwindow const* window) :
        m_game{game},
        m_window{window}
    {}
    virtual ~Scene() = default;

    void draw() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (auto const& layer : m_layers)
            layer->draw();
    }
    void update() {
        on_update();
        for (auto&& layer : m_layers)
            layer->update();

        // retain
        auto it = std::remove_if(
            std::begin(m_layers), std::end(m_layers),
            [](std::unique_ptr<Layer> const& layer) {
            return !layer->is_alive();
        });
        m_layers.erase(it, std::end(m_layers));
    }

    template<typename F>
    void foreach(F const& f) const {
        for (auto&& e : m_layers)
            f(*e);
    }

    size_t layer_size() const {
        return m_layers.size();
    }

    Game const& game() const {
        return m_game;
    }

    virtual void on_init() {}
    virtual void on_update() {}
protected:
        template<typename T>
    T& add_layer() {
        util::ptr<Layer> layer = std::make_unique<T>(*this, m_window);
        layer->on_init();
        m_layers.push_back(std::move(layer));
        return dynamic_cast<T&>(*m_layers.back());
    }
private:
    util::container<mkyu::Layer> m_layers;
    Game const& m_game;
    GLFWwindow const* m_window;
};

}

#endif
