#pragma once

namespace core {

template <class T>
struct numeric_limits {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = false;
};

} // namespace core

template <>
struct core::numeric_limits<bool> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};

template <>
struct core::numeric_limits<char> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<signed char> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<unsigned char> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = true;
    static constexpr bool is_integer  = true;
};

template <>
struct core::numeric_limits<short> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<int> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<long> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<long long> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<unsigned short> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = true;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<unsigned int> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = true;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<unsigned long> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = true;
    static constexpr bool is_integer  = true;
};
template <>
struct core::numeric_limits<unsigned long long> {
    static constexpr bool is_signed   = false;
    static constexpr bool is_unsigned = true;
    static constexpr bool is_integer  = true;
};

template <>
struct core::numeric_limits<float> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = false;
};
template <>
struct core::numeric_limits<double> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = false;
};
template <>
struct core::numeric_limits<long double> {
    static constexpr bool is_signed   = true;
    static constexpr bool is_unsigned = false;
    static constexpr bool is_integer  = false;
};
