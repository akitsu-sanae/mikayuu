/*============================================================================
  Copyright (C) 2017 akitsu sanae
  https://github.com/akitsu-sanae/mikayuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef MIKAYUU_UTILITY_HPP
#define MIKAYUU_UTILITY_HPP

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <memory>

namespace mkyu {
namespace util {

std::vector<std::string> split(std::string const& str) {
    std::vector<std::string> res;
    std::stringstream ss{str};
    std::string buf;
    while (std::getline(ss, buf, ' '))
        res.push_back(buf);
    return res;
}

template<typename T>
struct range {
    std::vector<T> data;
    size_t first;
    size_t last;

    template<typename F>
    auto map(F const& f) const {
        using result_t = decltype(f(std::declval<T>()));
        std::vector<result_t> result;
        for (size_t i=first; i<last; i++)
            result.push_back(f(data[i]));
        return range<result_t>{result, 0, result.size()};
    }

    template<size_t N>
    std::array<T, N> to_array() const {
        std::array<T, N> result;
        for (size_t i=0; i<N; i++)
            result[i] = data[i];
        return result;
    }
};

template<typename T>
using ptr = std::unique_ptr<T>;

template<typename T>
using container = std::vector<ptr<T>>;

} // end of util
} // end of mkyu

#endif

