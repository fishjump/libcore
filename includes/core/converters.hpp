#pragma once

#include <core/stdint.hpp>
#include <core/type_traits.hpp>

namespace core {

template <class T,
          core::enable_if_t<core::is_integer_v<T> && core::is_signed_v<T>>
              * = nullptr>
char *itoa(const T &t, char *buffer, core::size_t size) {
    // TODO
    return buffer;
}

template <class T,
          core::enable_if_t<
              core::is_integer_v<T> && core::is_unsigned_v<T>> * = nullptr>
char *itoa(const T &t, char *buffer, core::size_t size) {
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

} // namespace core
