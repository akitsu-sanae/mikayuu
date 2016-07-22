/*============================================================================
Copyright (C) 2016 akitsu sanae
https://github.com/akitsu-sanae/mikayuu
Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <cmath>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/camera.hpp>

void mkyu::camera::look_at() const {
    using std::sin;
    using std::cos;
    double origin_x = m_origin.radius * sin(m_origin.theta) * cos(m_origin.phi);
    double origin_y = m_origin.radius * sin(m_origin.theta) * sin(m_origin.phi);
    double origin_z = m_origin.radius * cos(m_origin.theta);
    gluLookAt(
        origin_x, origin_y, origin_z,
        m_target_position[0], m_target_position[1], m_target_position[2],
        m_up_direction[0], m_up_direction[1], m_up_direction[2]
    );
}

