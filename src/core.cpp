#define GLFW_INCLUDE_GLU
#include <cstdlib>
#include <GLFW/glfw3.h>

#include <mikayuu/core.hpp>
#include <mikayuu/blend.hpp>
#include <mikayuu/keyboard.hpp>

using namespace mkyu;

static GLFWwindow* window = nullptr;

void mkyu::initialize(Option const& option) {

    mkyu::detail::Keyboard::initialize();

    glfwInit();
    window = glfwCreateWindow(
            option.width, option.height,
            option.title,
            nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, detail::keyboard_callback);

    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int mkyu::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mkyu::detail::do_blend();
    return !glfwWindowShouldClose(window);
}

void mkyu::terminate()  {
    glfwTerminate();

    mkyu::detail::Keyboard::terminate();
}

