#pragma once 

#include <array>

/**
 * https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/
 */
template<size_t N>
struct StringLiteral {
    constexpr StringLiteral(const char (&str)[N]) {
        std::copy_n(str, N, value_.begin());
    }
    
    constexpr StringLiteral(const std::array<char, N> &value) {
        this->value_ = value;
    }

    std::array<char, N> value_;
};
