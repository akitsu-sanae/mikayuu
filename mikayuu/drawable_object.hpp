/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_DRAWABLE_HP
#define MIKAYUU_DRAWABLE_HP

#include <mikayuu/vec.hpp>

namespace mkyu {

struct DrawableObject {
    explicit DrawableObject(vec2d const& position) :
        position(position)
    {}
    virtual ~DrawableObject() {}
    virtual void draw() const = 0;

    vec2d position;
};

}


#endif
