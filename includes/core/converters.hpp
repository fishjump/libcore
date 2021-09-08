#pragma once

#include <core/stdint.hpp>
#include <core/type_traits.hpp>

namespace core {

template <class T,
          core::enable_if_t<core::is_integer_v<T> && core::is_signed_v<T>>
              * = nullptr>
char *itoa(const T &t, char *buffer, core::size_t size);

template <class T,
          core::enable_if_t<
              core::is_integer_v<T> && core::is_unsigned_v<T>> * = nullptr>
char *itoa(const T &t, char *buffer, core::size_t size);

template <class T,
          core::enable_if_t<
              core::is_integer_v<T> && core::is_unsigned_v<T>> * = nullptr>
char *to_hex(const T &t, char *buffer, core::size_t size);

} // namespace core

template <class T,
          core::enable_if_t<core::is_integer_v<T> && core::is_signed_v<T>>
              * = nullptr>
char *core::itoa(const T &t, char *buffer, core::size_t size) {
    // TODO
    return buffer;
}

template <class T,
          core::enable_if_t<
              core::is_integer_v<T> && core::is_unsigned_v<T>> * = nullptr>
char *core::itoa(const T &t, char *buffer, core::size_t size) {
    T      tmp = t;
    int8_t len = 0;
    if(tmp) {
        while(tmp) {
            tmp /= 10;
            len++;
        }
    } else {
        len = 1;
    }

    // one extra size for '\0'
    if(len + 1 > size) {
        return nullptr;
    }

    tmp = t;
    for(int8_t i = len - 1; i >= 0; i--) {
        buffer[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    buffer[len] = '\0';

    return buffer;
}

template <class T,
          core::enable_if_t<
              core::is_integer_v<T> && core::is_unsigned_v<T>> * = nullptr>
char *core::to_hex(const T &t, char *buffer, core::size_t size) {
    T      tmp = t;
    int8_t len = 0;
    if(tmp) {
        while(tmp) {
            tmp /= 16;
            len++;
        }
    } else {
        len = 1;
    }

    // one extra size for '\0'
    if(len + 1 > size) {
        return nullptr;
    }

    tmp = t;
    for(int8_t i = len - 1; i >= 0; i--) {
        buffer[i] = tmp % 16 < 10 ? tmp % 16 + '0' : tmp % 16 - 10 + 'a';
        tmp /= 16;
    }
    buffer[len] = '\0';

    return buffer;
}
