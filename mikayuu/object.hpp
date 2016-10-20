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

namespace mkyu {

struct Object {
    virtual ~Object() = default;
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual bool is_alive() = 0;

    mkyu::vector3d position;

    enum class BlendMode {
        None,
        Alpha,
        Reverse,
        Add,
        Screen,
        Mult
    };

    BlendMode blend_mode = BlendMode::None;

    void blend() const {
        if (blend_mode == BlendMode::None) {
            glDisable(GL_BLEND);
            return;
        }

        glEnable(GL_BLEND);

        switch (blend_mode) {
        case BlendMode::None:
            break;
        case BlendMode::Alpha:
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case BlendMode::Reverse:
            glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
            break;
        case BlendMode::Add:
            glBlendFunc(GL_ONE, GL_ONE);
            break;
        case BlendMode::Screen:
            glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
            break;
        case BlendMode::Mult:
            glBlendFunc(GL_ZERO, GL_SRC_COLOR);
            break;
        }
    }
};

}


#endif
