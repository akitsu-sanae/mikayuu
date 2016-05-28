#ifndef MIKAYUU_HPP
#define MIKAYUU_HPP

#include <memory>

namespace mkyu {

struct shared_tag {};
struct unique_tag {};

namespace detail {

template<typename, typename>
using ptr_impl = void;

template<typename T>
using ptr_impl<T, mkyu::shared_tag> = std::shared_ptr<T>;
template<typename T>
using ptr_impl<T, mkyu::unique_tag> = std::unique_ptr<T>;

}

template<typename T, typename U = mkyu::unique_tag>
using ptr = mkyu::detail::ptr_impl<T, U>;

template<typename T, typename U = mkyu::unique_tag>
using container = std::vector<ptr<T, U>>;

}

#endif
