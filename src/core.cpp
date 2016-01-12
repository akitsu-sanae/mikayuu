#define GLFW_INCLUDE_GLU
#include <cstdlib>
#include <GLFW/glfw3.h>

#include <mikayuu/core.hpp>
#include <mikayuu/blend.hpp>

using namespace mkyu;

static GLFWwindow* window = nullptr;

void mkyu::initialize(Option const& option) {
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
}

