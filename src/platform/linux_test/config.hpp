#pragma once

#include "gpio.hpp"

namespace treadmill_hack::platform::linux_test::config {
    using namespace treadmill_hack::platform::linux_test::gpio;
    
    inline constexpr Gpio<0, Direction::DISABLED> Disabled{};
    using BuiltinLed = Gpio<1, Direction::OUTPUT>;
}
