#define GLFW_INCLUDE_GLU
#include <cstdlib>
#include <GLFW/glfw3.h>

#include <mikayuu/core.hpp>
#include <mikayuu/keyboard.hpp>

mkyu::Game::Game(mkyu::Game::Option const& option) {

    mkyu::detail::Keyboard::initialize();

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
    glfwSetKeyCallback(m_window, detail::keyboard_callback);

    glClearColor(0.0, 0.0, 0.0, 1.0);
}


int mkyu::Game::update() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return !glfwWindowShouldClose(m_window);
}

mkyu::Game::~Game()  {
    glfwTerminate();

    mkyu::detail::Keyboard::terminate();
}

