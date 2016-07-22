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
    void look_at() const;

    void move_angle(double dx, double dy);
    void move_target(double dx, double dy);

    void set_angle(double theta, double phi);
    void set_target(mkyu::vector3d const&);
private:
    struct origin {
        double theta = 1.0;
        double phi = 1.0;
        double radius = 5.0;
    };

    origin m_origin;
    mkyu::vector3d m_target_position = mkyu::vector3d{0.0, 0.0, 0.0};
    mkyu::vector3d m_up_direction = mkyu::vector3d{0.0, 1.0, 0.0};
};

}

#endif
