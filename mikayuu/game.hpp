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
            m_current_scene.swap(m_next_scene);
            m_next_scene.reset();
        }
        glfwPollEvents();
        Keyboard::update();
    }
    void draw() const {
        if (m_current_scene)
            m_current_scene->draw();
        glfwSwapBuffers(detail::window);
    }

    template<typename T, typename ... Args>
    void change_scene(Args&& ... args) {
        std::unique_ptr<mkyu::Scene> tmp = std::make_unique<T>(std::forward<Args>(args) ...);
        tmp.swap(m_next_scene);
    }
protected:
    virtual void on_update() = 0;
private:
    std::unique_ptr<mkyu::Scene> m_current_scene = nullptr;
    std::unique_ptr<mkyu::Scene> m_next_scene = nullptr;
};

} // namespace mkyu

#endif
