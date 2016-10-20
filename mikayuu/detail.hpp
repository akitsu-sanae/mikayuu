#ifndef MIKAYUU_DETAIL_HPP
#define MIKAYUU_DETAIL_HPP

struct GLFWwindow;

#include <mikayuu/vector.hpp>

namespace mkyu {

struct detail {
    static GLFWwindow* window;
    static mkyu::vector<int, 2> size;
};

}

#endif
