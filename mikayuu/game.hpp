/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_GAME_HPP
#define MIKAYUU_GAME_HPP

#include <memory>
#include <iostream>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/scene.hpp>
#include <mikayuu/keyboard.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/detail.hpp>

namespace mkyu {

struct Game {
    struct Option {
        int width = 640;
        int height = 480;
        const char* title = "";
        bool is_fullscreen = false;
    };

    explicit Game(mkyu::Game::Option const& option) {
        glfwInit();
        detail::window = glfwCreateWindow(
            option.width, option.height,
            option.title,
            nullptr, nullptr);
        detail::size.x = option.width;
        detail::size.y = option.height;
        if (!detail::window) {
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(detail::window);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glEnable(GL_DEPTH_TEST);
        // glEnable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    virtual ~Game() {
        glfwTerminate();
    }

    bool is_alive() const {
        return !glfwWindowShouldClose(detail::window);
    }
    void update() {
        on_update();

        if (m_current_scene)
            m_current_scene->update();

        if (m_next_scene) {
            m_current_scene = std::move(m_next_scene);
            m_next_scene = nullptr;
        }
        glfwPollEvents();
        Keyboard::update();
    }
    void draw() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        int width, height;
        glfwGetFramebufferSize(detail::window, &width, &height);
        glViewport(0, 0, width, height);
        gluPerspective(30.0, (double)width / (double)height, 1.0, 100.0);
        m_camera.look_at();
        static const GLfloat light_position[] = { 0.0, 3.0, 5.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        if (m_current_scene)
            m_current_scene->draw();
        glfwSwapBuffers(detail::window);
    }

    template<typename T>
    void change_scene(T&& scene) {
        m_next_scene = std::make_unique<T>(std::move(scene));
    }
protected:
    virtual void on_update() = 0;
private:
    mkyu::camera m_camera;

    std::unique_ptr<Scene> m_current_scene = nullptr;
    std::unique_ptr<Scene> m_next_scene = nullptr;
};

} // namespace mkyu

#endif
