#define GLFW_INCLUDE_GLU
#include <cstdlib>
#include <GLFW/glfw3.h>

#include <mikayuu/game.hpp>
#include <mikayuu/scene.hpp>
#include <mikayuu/keyboard.hpp>

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
    glfwSetKeyCallback(m_window, keyboard_detail::callback_impl);

    glClearColor(0.0, 0.0, 0.0, 1.0);
}


int mkyu::Game::update() {
    on_update();

    if (m_current_scene)
        m_current_scene->update();

    if (m_current_scene != m_next_scene)
        m_current_scene = m_next_scene;

    glfwSwapBuffers(m_window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return !glfwWindowShouldClose(m_window);
}

void mkyu::Game::change_scene(std::shared_ptr<mkyu::Scene> const& scene) {
    m_next_scene = scene;
}

mkyu::Game::~Game()  {
    glfwTerminate();
}



