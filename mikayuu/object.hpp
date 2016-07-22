/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_OBJECT_HP
#define MIKAYUU_OBJECT_HP

#include <mikayuu/vector.hpp>

namespace mkyu {

struct Object {
    virtual ~Object() = default;
    virtual void draw() const = 0;
    virtual void update() = 0;

    mkyu::vector3d position;
};

}


#endif
