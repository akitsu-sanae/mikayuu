/*============================================================================
Copyright (C) 2016 akitsu sanae
https://github.com/akitsu-sanae/mikayuu
Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_CAMERA_HPP
#define MIKAYUU_CAMERA_HPP

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/vector.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/detail.hpp>

namespace mkyu {

struct camera {
    void apply() const {
        glLoadIdentity();
        glViewport(distination[0], distination[1], distination[2], distination[3]);
        gluPerspective(30.0, (double)distination[2] / (double)distination[3], 0.1, 100.0);
        gluLookAt(
            origin_position.x, origin_position.y, origin_position.z,
            target_position.x, target_position.y, target_position.z,
            up_direction.x, up_direction.y, up_direction.z
        );
    }

    mkyu::rect<int> distination = { 0, 0, detail::size.x, detail::size.y };
    mkyu::vector3d origin_position = mkyu::vector3d{ 5.0, 5.0, 5.0 };
    mkyu::vector3d target_position = mkyu::vector3d{ 0.0, 0.0, 0.0 };
    mkyu::vector3d up_direction = mkyu::vector3d{ 0.0, 1.0, 0.0 };
};

}

#endif
