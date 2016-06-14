/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_COLOR_HPP
#define MIKAYUU_COLOR_HPP

namespace mkyu {

struct Color {
    double r, g, b, a;
    static Color red() {
        return Color{1.0, 0.0, 0.0, 1.0};
    }
    static Color green() {
        return Color{0.0, 1.0, 0.0, 1.0};
    }
    static Color blue() {
        return Color{0.0, 0.0, 1.0, 1.0};
    }
};

}

#endif
