/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_VECTOR_HPP
#define MIKAYUU_VECTOR_HPP

namespace mkyu {

template<typename T, int N>
struct vector {
    using value_type = T;
    static constexpr int Size = N;
    value_type elems[N];

    struct out_of_range_exception {};
    value_type const& at(int i) const {
        if (i < 0 || i >= Size)
            throw out_of_range_exception{};
        return elems[i];
    }

    value_type& at(int i) {
        if (i < 0 || i >= Size)
            throw out_of_range_exception{};
        return elems[i];
    }
    value_type const& operator[](int i) const { return at(i); }
    value_type& operator[](int i) { return at(i); }
};



template<typename T>
struct vector<T, 2> {
    using value_type = T;
    value_type x = static_cast<value_type>(0);
    value_type y = static_cast<value_type>(0);

    explicit vector() = default;
	explicit vector(value_type const& x, value_type const& y) :
		x(x), y(y)
	{}

    explicit vector(std::array<value_type, 2> const& arr) :
        x{arr[0]}, y{arr[1]}
    {}
    explicit vector(value_type (&arr)[2]) :
        x{arr[0]}, y{arr[1]}
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
    value_type const& operator[](int i) const { return at(i); }
    value_type& operator[](int i) { return at(i); }
};

template<typename T>
struct vector<T, 3> {
    using value_type = T;
    value_type x = static_cast<value_type>(0);
    value_type y = static_cast<value_type>(0);
    value_type z = static_cast<value_type>(0);
    explicit vector() = default;
    explicit vector(value_type const& x, value_type const& y, value_type const& z) :
        x(x), y(y), z(z)
    {}
    explicit vector(std::array<value_type, 3> const& arr) :
        x{arr[0]}, y{arr[1]}, z{arr[2]}
    {}
    explicit vector(value_type (&arr)[3]) :
        x{arr[0]}, y{arr[1]}, z{arr[2]}
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

    value_type const& operator[](int i) const { return at(i); }
    value_type& operator[](int i) { return at(i); }
};

template<typename T, int N>
inline static vector<T, N>
operator+(
    vector<T, N> const& lhs,
    vector<T, N> const& rhs) {
    auto result = vector<T, N>{};
    for (int i=0; i<N; i++)
        result.at(i) = lhs.at(i) + rhs.at(i);
    return result;
}


using vector2 = vector<float , 2>;
using vector3 = vector<float, 3>;

template<typename T>
using rect = vector<T, 4>;

}

#endif

