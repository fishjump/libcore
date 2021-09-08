#pragma once

#include <core/stdint.hpp>

namespace core {

inline void *memset(void *dest, const core::uint8_t &value,
                    const core::size_t &count);
inline void *memcpy(void *dest, const void *&src,
                    const core::size_t &count);

} // namespace core

void *core::memset(void *dest, const core::uint8_t &value,
                   const core::size_t &count) {
    for(core::size_t i = 0; i < count; i++) {
        ((uint8_t *)dest)[i] = value;
    }

    return dest;
}

void *core::memcpy(void *dest, const void *&src,
                   const core::size_t &count) {
    for(core::size_t i = 0; i < count; i++) {
        ((uint8_t *)dest)[i] = ((const uint8_t *)src)[i];
    }

    return dest;
}
