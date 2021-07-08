#pragma once

#include <core/limits.hpp>

namespace core {

template <bool, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
    using type = T;
};

template <bool B, class T = void>
using enable_if_t = typename core::enable_if<B, T>::type;

template <class T>
struct is_signed {
    static constexpr bool value = core::numeric_limits<T>::is_signed;
};

template <class T>
inline constexpr bool is_signed_v = core::is_signed<T>::value;

template <class T>
struct is_unsigned {
    static constexpr bool value = core::numeric_limits<T>::is_unsigned;
};

template <class T>
inline constexpr bool is_unsigned_v = core::is_unsigned<T>::value;

template <class T>
struct is_integer {
    static constexpr bool value = core::numeric_limits<T>::is_integer;
};

template <class T>
inline constexpr bool is_integer_v = core::is_integer<T>::value;

} // namespace core
