#ifndef MIKAYUU_VEC2D_HPP
#define MIKAYUU_VEC2D_HPP

namespace mkyu {

template<typename, int>
struct vec;

template<typename T>
struct vec<T, 2> {
    T x = static_cast<T>(0.0);
    T y = static_cast<T>(0.0);
};

template<typename T>
struct vec<T, 3> {
    T x = static_cast<T>(0.0);
    T y = static_cast<T>(0.0);
    T z = static_cast<T>(0.0);
};

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

