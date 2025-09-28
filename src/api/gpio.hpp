#pragma once

#include <cstdint>
#include <functional>

namespace treadmill_hack::api::gpio {

using Pin = std::uint16_t;

enum class Direction { INVALID, INPUT, OUTPUT, INPUT_OUTPUT };

template <Pin pin_, Direction direction, typename Type_, bool enabled = true>
struct Gpio {
    static constexpr Pin pin = pin_;
    static constexpr Direction Dir = direction;
    static constexpr bool Enabled = enabled;
    using Type = Type_;
    /* void callback(Type newValue) */
    using Callback = std::function<void(Type)>;

    static void setValue(Type) {
        static_assert(enabled == false, "Unspecified GPIO pin is enabled");
    }

    static Type getValue() {
        static_assert(enabled == false, "Unspecified GPIO pin is enabled");
        return 0;
    }

    static void onValueChange(const Callback &) {
        static_assert(enabled == false, "Unspecified GPIO pin is enabled");
    }
};

using NotConfigured = gpio::Gpio<0, gpio::Direction::INVALID, bool, false>;

} // namespace treadmill_hack::api::gpio
