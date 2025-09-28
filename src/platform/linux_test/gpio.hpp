#pragma once

#include <iostream>

#include "api/gpio.hpp"

namespace treadmill_hack {

namespace platform::linux_test::gpio {

template <api::gpio::Pin pin, api::gpio::Direction direction, typename Type, bool enabled = true>
class SimulatedGpio : api::gpio::Gpio<pin, direction, Type, enabled> {
    inline static Type value;

  public:
    SimulatedGpio() = delete;

    /**
     * @brief Get the value of the GPIO pin - requires pin to be enabled and configured as OUTPUT or INPUT_OUTPUT.
     */
    static Type getValue() {
        static_assert(enabled, "GPIO pin is disabled.");
        using enum api::gpio::Direction;
        static_assert(direction == OUTPUT || direction == INPUT_OUTPUT, "GPIO pin is disabled.");

        std::cout << "[linux_test] Read GPIO " << pin << " -> " << SimulatedGpio::value << std::endl;
        return SimulatedGpio::value;
    }

    /**
     * @brief Set the value of the GPIO pin - requires pin to be enabled and configured as OUTPUT or INPUT_OUTPUT.
     */
    static void setValue(Type value_) {
        static_assert(enabled, "GPIO pin is disabled.");
        using enum api::gpio::Direction;
        static_assert(direction == OUTPUT || direction == INPUT_OUTPUT, "GPIO pin is disabled.");

        std::cout << "[linux_test] Writing " << value_ << " -> GPIO " << pin << std::endl;
        SimulatedGpio::value = value_;
    }

    /**
     * @brief Get the value of the GPIO pin - even if not configured as OUTPUT or INPUT_OUTPUT.
     */
    static Type _getValue() {
        static_assert(enabled, "GPIO pin is disabled.");
        return SimulatedGpio::value;
    }

    /**
     * @brief Set the value of the GPIO pin - even if not configured as INPUT or INPUT_OUTPUT.
     */
    static void _setValue(Type value_) {
        static_assert(enabled, "GPIO pin is disabled.");
        SimulatedGpio::value = value_;
    }
};

using BuildInLed = platform::linux_test::gpio::SimulatedGpio<1, api::gpio::Direction::OUTPUT, bool>;

} // namespace platform::linux_test::gpio
} // namespace treadmill_hack