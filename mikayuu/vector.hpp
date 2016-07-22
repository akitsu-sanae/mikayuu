/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_VECTOR_HPP
#define MIKAYUU_VECTOR_HPP

namespace mkyu {

template<typename, int>
struct vector;


template<typename T>
struct vector<T, 2> final {
    using value_type = T;
    value_type x = static_cast<value_type>(0);
    value_type y = static_cast<value_type>(0);

    explicit vector() = default;
	explicit vector(value_type const& x, value_type const& y) :
		x(x), y(y)
	{}

    struct out_of_range_exception {};
    value_type const& at(int i) const {
        if (i == 0)
            return x;
        else if (i == 1)
            return y;
        else
            throw out_of_range_exception{};
    }

    value_type& at(int i) {
        if (i == 0)
            return x;
        else if (i == 1)
            return y;
        else
            throw out_of_range_exception{};
    }

};

template<typename T>
struct vector<T, 3> final {
    using value_type = T;
    value_type x = static_cast<value_type>(0);
    value_type y = static_cast<value_type>(0);
    value_type z = static_cast<value_type>(0);
    explicit vector() = default;
    explicit vector(value_type const& x, value_type const& y, value_type const& z) :
        x(x), y(y), z(z)
    {}

    struct out_of_range_exception {};
    value_type const& at(int i) const {
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

    value_type& at(int i) {
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
inline static vector<T, N> operator+(vector<T, N> const& lhs, vector<T, N> const& rhs) {
    auto result = vector<T, N>{};
    for (int i=0; i<N; i++)
        result.at(i) = lhs.at(i) + rhs.at(i);
    return result;
}


using vector2d = vector<double , 2>;
using vector3d = vector<double, 3>;

}

#endif

