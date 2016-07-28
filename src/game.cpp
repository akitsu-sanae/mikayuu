/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#define GLFW_INCLUDE_GLU
#include <cstdlib>
#include <GLFW/glfw3.h>

#include <mikayuu/game.hpp>
#include <mikayuu/scene.hpp>
#include <mikayuu/keyboard.hpp>

static void init_gl() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

mkyu::Game::Game(mkyu::Game::Option const& option) {

    glfwInit();
    m_window =  glfwCreateWindow(
            option.width, option.height,
            option.title,
            nullptr, nullptr
            );
    if (!m_window) {
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(m_window);
    Keyboard::set_window(m_window);

    init_gl();
}


bool mkyu::Game::is_alive() const {
    return !glfwWindowShouldClose(m_window);
}

void mkyu::Game::update() {
    on_update();

    if (m_current_scene)
        m_current_scene->update();

    if (m_current_scene != m_next_scene)
        m_current_scene = m_next_scene;
    glfwPollEvents();
    Keyboard::update();
}

void mkyu::Game::draw() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(m_window, &width, &height);
    glViewport(0, 0, width, height);

    gluPerspective(30.0, (double)width/ (double)height, 1.0, 100.0);
    m_camera.look_at();
    static const GLfloat light_position[] = {0.0, 3.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   if (m_current_scene)
        m_current_scene->draw();

    glfwSwapBuffers(m_window);
}

void mkyu::Game::change_scene(mkyu::ptr<mkyu::Scene> const& scene) {
    m_next_scene = scene;
}

mkyu::Game::~Game()  {
    glfwTerminate();
}



