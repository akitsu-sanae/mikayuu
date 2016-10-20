/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_LAYER_HPP
#define MIKAYUU_LAYER_HPP

#include <unordered_map>
#include <memory>

#include <mikayuu/object.hpp>

namespace mkyu {

struct Scene;

struct Layer {
    Layer(Scene const& p) :
        m_scene(p)
    {}
    virtual ~Layer() = default;

    void draw() const {
        for (auto const& obj : m_objects) {
            obj.second->blend();
            obj.second->draw();
        }
    }
    void update() {
        on_update();
        for (auto&& obj : m_objects)
            obj.second->update();
    }

    template<typename F>
    void foreach(F const& f) const {
        for (auto&& e : m_objects)
            f(e.second);
    }
    template<typename F>
    void foreach_with_name(F const& f) const {
        for (auto&& e : m_objects)
            f(e.first, e.second);
    }

    template<typename T = mkyu::Object>
    T const& object(std::string const& name) const {
        return dynamic_cast<T const&>(m_objects.find(name)->second);
    }
    template<typename T = mkyu::Object>
    T& object(std::string const& name) {
        return dynamic_cast<T&>(m_objects.find(name)->second);
    }
    std::vector<std::string> object_names() const {
        std::vector<std::string> names = {};
        names.reserve(m_objects.size());
        for (auto const& e : m_objects)
            names.push_back(e.first);
        return names;
    }
protected:
    virtual void on_update() {}
    void add_object(std::string const& name, std::shared_ptr<Object> const& obj) {
        m_objects.insert(std::make_pair(name, obj));
    }
private:
    std::unordered_map<std::string, std::shared_ptr<Object>> m_objects;
    Scene const& m_scene;
};

}

#endif
