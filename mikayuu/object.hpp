/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_OBJECT_HPP
#define MIKAYUU_OBJECT_HPP

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <mikayuu/vector.hpp>
#include <mikayuu/color.hpp>

namespace mkyu {

struct Object {
    virtual ~Object() = default;
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual bool is_alive() = 0;

    mkyu::vector3 position;
    mkyu::color color = color::white();

    enum class BlendMode {
        None,
        Alpha,
        Reverse,
        Add,
        Screen,
        Mult
    };

    BlendMode blend_mode = BlendMode::None;
};

}


#endif
