/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_DRAWABLE_HP
#define MIKAYUU_DRAWABLE_HP

#include <mikayuu/vector.hpp>

namespace mkyu {

struct DrawableObject {
    explicit DrawableObject(mkyu::vector2d const& position) :
        position(position)
    {}
    virtual ~DrawableObject() {}
    virtual void draw() const = 0;

    mkyu::vector2d position;
};

}


#endif
