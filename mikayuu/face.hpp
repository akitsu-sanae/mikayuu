/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_FACE_HPP
#define MIKAYUU_FACE_HPP

#include <array>

namespace mkyu {

struct Face {
    std::array<unsigned int, 3> node_ids;
};

}

#endif

