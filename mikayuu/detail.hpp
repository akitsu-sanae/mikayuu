#ifndef MIKAYUU_DETAIL_HPP
#define MIKAYUU_DETAIL_HPP

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/vector.hpp>

namespace mkyu {

struct camera;
struct light;

struct detail {
    static GLFWwindow* window;
    static mkyu::vector<int, 2> size;

    static void apply_camera(mkyu::camera const&);
    static void apply_light(mkyu::light const&);
};

}

#endif
