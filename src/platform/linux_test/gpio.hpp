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

    static Type getValue() {
        static_assert(enabled, "GPIO pin is disabled.");
        using enum api::gpio::Direction;
        static_assert(direction == OUTPUT || direction == INPUT_OUTPUT, "GPIO pin is disabled.");

        std::cout << "[linux_test] Read GPIO " << pin << " -> " << SimulatedGpio::value << std::endl;
        return SimulatedGpio::value;
    }

    static void setValue(Type value_) {
        static_assert(enabled, "GPIO pin is disabled.");
        using enum api::gpio::Direction;
        static_assert(direction == OUTPUT || direction == INPUT_OUTPUT, "GPIO pin is disabled.");

        std::cout << "[linux_test] Writing " << value_ << " -> GPIO " << pin << std::endl;
        SimulatedGpio::value = value_;
    }
};

using BuildInLed = platform::linux_test::gpio::SimulatedGpio<1, api::gpio::Direction::OUTPUT, bool>;

} // namespace platform::linux_test::gpio
} // namespace treadmill_hack