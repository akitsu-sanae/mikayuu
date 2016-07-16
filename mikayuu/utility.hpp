/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef MIKAYUU_UTILITY_HPP
#define MIKAYUU_UTILITY_HPP

#include <memory>
#include <vector>

namespace mkyu {

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T>
using container = std::vector<ptr<T>>;

}

#endif

