/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_COLOR_HPP
#define MIKAYUU_COLOR_HPP

namespace mkyu {

template<typename T>
struct Color final {
    T r, g, b;

    static Color red();
    static Color green();
    static Color blue();
};

template<>
static inline Color<double> Color<double>::red() {
    return Color<double>{ 1.0, 0.0, 0.0 };
}
template<>
static inline Color<double> Color<double>::green() {
    return Color<double>{ 0.0, 1.0, 0.0 };
}
template<>
static inline Color<double> Color<double>::blue() {
    return Color<double>{ 0.0, 0.0, 1.0 };
}
template<>
static inline Color<unsigned char> Color<unsigned char>::red() {
    return Color<unsigned char>{ 255, 0, 0};
}
template<>
static inline Color<unsigned char> Color<unsigned char>::green() {
    return Color<unsigned char>{ 0, 255, 0 };
}
template<>
static inline Color<unsigned char> Color<unsigned char>::blue() {
    return Color<unsigned char>{ 0, 0, 255 };
}

using Colord = Color<double>;
using Colori = Color<unsigned char>;


}

#endif
