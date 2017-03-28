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

#include <GL/glew.h>
#include <GL/glext.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/scene.hpp>
#include <mikayuu/keyboard.hpp>

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
        m_window = glfwCreateWindow(
            option.width, option.height,
            option.title,
            nullptr, nullptr);
        m_window_size.x = option.width;
        m_window_size.y = option.height;
        if (!m_window) {
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(m_window);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glEnable(GL_DEPTH_TEST);
        // glEnable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        m_keyboard = std::make_unique<Keyboard>(m_window);
    }
    virtual ~Game() {
        glfwTerminate();
    }

    bool is_alive() const {
        return !glfwWindowShouldClose(m_window);
    }
    void update() {
        on_update();

        if (m_current_scene) {
            m_current_scene->update();
        }

        if (m_next_scene) {
            m_current_scene.swap(m_next_scene);
            m_next_scene.reset();
        }
        glfwPollEvents();
        glewInit();
        m_keyboard->update();
    }
    void draw() const {
        if (m_current_scene)
            m_current_scene->draw();
        glfwSwapBuffers(m_window);
    }

    template<typename Sc>
    void change_scene() {
        std::unique_ptr<mkyu::Scene> tmp = std::make_unique<Sc>(*this, m_window);
        tmp.swap(m_next_scene);
        m_next_scene->on_init();
    }

    GLFWwindow const* window() const {
        return m_window;
    }
    vector<int, 2> const& size() const {
        return m_window_size;
    }
    virtual void on_init() {}
    virtual void on_update() {}
private:
    GLFWwindow* m_window = nullptr;
    vector<int, 2> m_window_size{};
    util::ptr<Keyboard> m_keyboard = nullptr;
    std::unique_ptr<mkyu::Scene> m_current_scene = nullptr;
    std::unique_ptr<mkyu::Scene> m_next_scene = nullptr;
};

} // namespace mkyu

#endif
