/*============================================================================
Copyright (C) 2016 akitsu sanae
https://github.com/akitsu-sanae/mikayuu
Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_CAMERA_HPP
#define MIKAYUU_CAMERA_HPP

#include <mikayuu/vector.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/detail.hpp>

namespace mkyu {

struct camera {
    mkyu::rect<int> distination = { 0, 0, detail::size.x, detail::size.y };
    mkyu::vector3d origin_position = mkyu::vector3d{ 5.0, 5.0, 5.0 };
    mkyu::vector3d target_position = mkyu::vector3d{ 0.0, 0.0, 0.0 };
    mkyu::vector3d up_direction = mkyu::vector3d{ 0.0, 1.0, 0.0 };
};

}

#endif
