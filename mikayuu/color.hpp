/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_COLOR_HPP
#define MIKAYUU_COLOR_HPP

namespace mkyu {

struct color final {
    unsigned char r, g, b;

    static color red() {
        return color{ 255, 0, 0 };
    }
    static color green() {
        return color{ 0, 255, 0 };
    }
    static color blue() {
        return color{ 0, 0, 255 };
    }
    static color black() {
        return color{ 0, 0, 0 };
    }
    static color white() {
        return color{ 255, 255, 255 };
    }
    static color yellow() {
        return color{ 255, 255, 0 };
    }
    static color cyan() {
        return color{ 0, 255, 255 };
    }
    static color magenta() {
        return color{ 255, 0, 255 };
    }
};

}

#endif
