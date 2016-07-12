/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_VEC2D_HPP
#define MIKAYUU_VEC2D_HPP

namespace mkyu {

template<typename, int>
struct vec;

template<typename T>
struct vec<T, 2> {
    T x = static_cast<T>(0.0);
    T y = static_cast<T>(0.0);

	explicit vec(T const& x, T const& y) :
		x(x), y(y)
	{}

    struct out_of_range_exception {};
    T const& at(int i) const {
        if (i == 0)
            return x;
        else if (i == 1)
            return y;
        else
            throw out_of_range_exception{};
    }

    T& at(int i) {
        if (i == 0)
            return x;
        else if (i == 1)
            return y;
        else
            throw out_of_range_exception{};
    }

};

template<typename T>
struct vec<T, 3> {
    T x = static_cast<T>(0.0);
    T y = static_cast<T>(0.0);
    T z = static_cast<T>(0.0);

    struct out_of_range_exception {};
    T const& at(int i) const {
        switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw out_of_range_exception{};
        }
    }

    T& at(int i) {
        switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw out_of_range_exception{};
        }
    }

};

template<typename T, int N>
inline static vec<T, N> operator+(vec<T, N> const& lhs, vec<T, N> const& rhs) {
    auto result = vec<T, N>{ 0.0, 0.0 };
    for (int i=0; i<N; i++)
        result.at(i) = lhs.at(i) + rhs.at(i);
    return result;
}

template<int N>
using vecd = vec<double, N>;

template<int N>
using vecf = vec<float, N>;

template<typename T>
using vec2 = vec<T, 2>;

template<typename T>
using vec3 = vec<T, 3>;

using vec2d = vec<double , 2>;
using vec2f = vec<float, 2>;
using vec3d = vec<double, 3>;
using vec3f = vec<float, 3>;

}

#endif

