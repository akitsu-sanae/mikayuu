/*============================================================================
Copyright (C) 2016 akitsu sanae
https://github.com/akitsu-sanae/mikayuu
Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_CAMERA_HPP
#define MIKAYUU_CAMERA_HPP

#include <mikayuu/vector.hpp>

namespace mkyu {

struct camera {
    vector3 origin_position{ 5.0, 5.0, 5.0 };
    vector3 target_position{ 0.0, 0.0, 0.0 };
    vector3 up_direction{ 0.0, 1.0, 0.0 };
};

}

#endif
