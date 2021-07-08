#pragma once

#include <core/stdint.hpp>

namespace core {
struct bitmap_t {
    core::uint8_t *_buffer;
    core::size_t   _size;

    // Element access
    constexpr bool operator[](const core::size_t &pos) const;

    // Capacity
    constexpr core::size_t size() const;

    // Modifiers
    bitmap_t &set(const core::size_t &pos, const bool &value = true);
    bitmap_t &reset(const core::size_t &pos);
    bitmap_t &flip(const core::size_t &pos);

    // Conversions
    char *to_string(char *buffer, const core::size_t &size) const;
};
} // namespace core

constexpr bool core::bitmap_t::operator[](const core::size_t &pos) const {
    core::size_t byte_pos = pos / 8, bit_pos = pos % 8;
    return _buffer[byte_pos] & (0b1000'0000 >> bit_pos);
}

constexpr core::size_t core::bitmap_t::size() const {
    return this->_size;
}

core::bitmap_t &core::bitmap_t::set(const core::size_t &pos,
                                    const bool &        value) {
    core::size_t byte_pos = pos / 8, bit_pos = pos % 8;

    core::uint8_t mask = 0b1000'0000 >> bit_pos;
    value ? (_buffer[byte_pos] |= mask) : (_buffer[byte_pos] &= ~mask);

    return *this;
}

core::bitmap_t &core::bitmap_t::reset(const core::size_t &pos) {
    core::size_t byte_pos = pos / 8, bit_pos = pos % 8;

    core::uint8_t mask = 0b1000'0000 >> bit_pos;
    _buffer[byte_pos] &= ~mask;

    return *this;
}

core::bitmap_t &core::bitmap_t::flip(const core::size_t &pos) {
    core::size_t byte_pos = pos / 8, bit_pos = pos % 8;

    core::uint8_t mask = 0b1000'0000 >> bit_pos;
    (*this)[pos] ? (_buffer[byte_pos] &= ~mask)
                 : (_buffer[byte_pos] |= mask);

    return *this;
}

char *core::bitmap_t::to_string(char *              buffer,
                                const core::size_t &size) const {
    // one extra size for '\0'
    if(this->size() + 1 > size) {
        return nullptr;
    }

    for(core::size_t i = 0; i < this->size(); i++) {
        buffer[i] = (*this)[i] ? '1' : '0';
    }
    buffer[this->size()] = '\0';

    return buffer;
}
