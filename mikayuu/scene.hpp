/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_SCENE_HPP
#define MIKAYUU_SCENE_HPP

#include <unordered_map>
#include <iterator>

#include <mikayuu/layer.hpp>

namespace mkyu {

struct Game;

struct Scene {
    explicit Scene(Game const& p) :
        m_game(p)
    {}
    virtual ~Scene() = default;

    void draw() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (auto const& layer : m_layers)
            layer.second->draw();
    }
    void update() {
        on_update();
        for (auto&& layer : m_layers)
            layer.second->update();
    }

    template<typename F>
    void foreach(F const& f) const {
        for (auto&& e : m_layers)
            f(e.second);
    }
    template<typename F>
    void foreach_with_name(F const& f) const {
        for (auto&& e : m_layers)
            f(e.first, e.second);
    }

    template<typename T = mkyu::Layer>
    T const& layer(std::string const& name) const {
        return dynamic_cast<T const&>(m_layers.find(name)->second);
    }
    template<typename T = mkyu::Layer>
    T& layer(std::string const& name) {
        return dynamic_cast<T&>(m_layers.find(name)->second);
    }
    std::vector<std::string> layer_names() const {
        std::vector<std::string> names = {};
        names.reserve(m_layers.size());
        for (auto const& e : m_layers)
            names.push_back(e.first);
        return names;
    }

    Game const& game() const {
        return m_game;
    }
protected:
    virtual void on_update() = 0;
    void add_layer(std::string const& name, std::shared_ptr<Layer> const& layer) {
        m_layers.insert(std::make_pair(name, layer));
    }
private:
    std::unordered_map<std::string, std::shared_ptr<Layer> > m_layers;
    Game const& m_game;
};

}

#endif
