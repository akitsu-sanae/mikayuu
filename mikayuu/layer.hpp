/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_LAYER_HPP
#define MIKAYUU_LAYER_HPP

#include <algorithm>
#include <vector>
#include <memory>

#include <mikayuu/object.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/light.hpp>

namespace mkyu {

struct Scene;

struct Layer {
    explicit Layer(Scene const& scene) :
        m_scene(scene)
    {}
    virtual ~Layer() = default;

    void draw() const {
        detail::apply_camera(m_camera);
        detail::apply_light(m_light);
        for (auto const& obj : m_objects) {
            detail::apply_object_setting(*obj);
            obj->draw();
        }
    }
    void update() {
        on_update();
        for (auto&& obj : m_objects)
            obj->update();

        // retain
        auto it = std::remove_if(
            std::begin(m_objects), std::end(m_objects),
            [](std::unique_ptr<Object> const& obj) {
            return !obj->is_alive();
        });
        m_objects.erase(it, std::end(m_objects));
    }

    virtual bool is_alive() { return true; }

    template<typename F>
    void foreach(F const& f) const {
        for (auto&& e : m_objects)
            f(e.second);
    }

    size_t object_size() const {
        return m_objects.size();
    }
protected:
    virtual void on_update() {}

    template<typename T, typename ... Args>
    T& add_object(Args&& ... args) {
        auto obj = std::make_unique<T>(std::forward<Args>(args) ...);
        auto& ret = *obj;
        m_objects.push_back(std::move(obj));
        return ret;
    }

    mkyu::camera const& camera() const {
        return m_camera;
    }
    mkyu::camera& camera() {
        return m_camera;
    }
    mkyu::light const& light() const {
        return m_light;
    }
    mkyu::light& light() {
        return m_light;
    }
private:
    mkyu::camera m_camera;
    mkyu::light m_light;
    std::vector<std::unique_ptr<Object>> m_objects;
    Scene const& m_scene;
};

}

#endif
