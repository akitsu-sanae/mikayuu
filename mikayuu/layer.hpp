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
#include <mikayuu/utility.hpp>

namespace mkyu {

struct Scene;

struct Layer {
    explicit Layer(Scene const& scene, GLFWwindow const* window) :
        m_scene{scene},
        m_window{window}
    {
        on_init();
    }
    virtual ~Layer() = default;

    void draw() const {
        apply_camera();
        apply_light();
        for (auto const& obj : m_objects) {
            apply_object_setting(*obj);
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
            f(*e);
    }

    size_t object_size() const {
        return m_objects.size();
    }

    virtual void on_init() {}
    virtual void on_update() {}
protected:
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
    Scene const& scene() const {
        return m_scene;
    }
private:
    mkyu::camera m_camera;
    mkyu::light m_light;
    util::container<Object> m_objects;
    Scene const& m_scene;
    GLFWwindow const* m_window;

    void apply_camera() const {
        glLoadIdentity();
        vector<int, 2> size;
        // fuck glfw
        glfwGetWindowSize(const_cast<GLFWwindow*>(m_window), &size.x, &size.y);
        glViewport(0.0, 0.0, size.x, size.y);
        gluPerspective(30.0, (double)size.x/size.y, 0.1, 100.0);
        gluLookAt(
                m_camera.origin_position.x,
                m_camera.origin_position.y,
                m_camera.origin_position.z,
                m_camera.target_position.x,
                m_camera.target_position.y,
                m_camera.target_position.z,
                m_camera.up_direction.x,
                m_camera.up_direction.y,
                m_camera.up_direction.z);
    }

    void apply_light() const {
        const GLfloat pos_param[] = {
            (GLfloat)m_light.position.x, (GLfloat)m_light.position.y, (GLfloat)m_light.position.z,
            1.0
        };
        glLightfv(GL_LIGHT0, GL_POSITION, pos_param);
        const GLfloat light_color_param[] = {
            m_light.light_color.r / 255.0f,
            m_light.light_color.g / 255.0f,
            m_light.light_color.b / 255.0f
        };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color_param);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_color_param);

        const GLfloat env_color_param[] = {
            m_light.env_color.r / 255.0f,
            m_light.env_color.g / 255.0f,
            m_light.env_color.b / 255.0f
        };
        glLightfv(GL_LIGHT0, GL_AMBIENT, env_color_param);
    }

    void apply_object_setting(mkyu::Object const& obj) const {
        std::array<GLfloat, 3> v = {{
            static_cast<GLfloat>(obj.color.r) / 255.f,
                static_cast<GLfloat>(obj.color.g) / 255.f,
                static_cast<GLfloat>(obj.color.b) / 255.f,
        }};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, v.data());
            if (obj.blend_mode == Object::BlendMode::None) {
                glDisable(GL_BLEND);
                    return;
            }

            glEnable(GL_BLEND);

            switch (obj.blend_mode) {
            case Object::BlendMode::None:
                break;
            case Object::BlendMode::Alpha:
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                break;
            case Object::BlendMode::Reverse:
                glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
                break;
            case Object::BlendMode::Add:
                glBlendFunc(GL_ONE, GL_ONE);
                break;
            case Object::BlendMode::Screen:
                glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
                break;
            case Object::BlendMode::Mult:
                glBlendFunc(GL_ZERO, GL_SRC_COLOR);
                break;
            }
    }
};

}

#endif
