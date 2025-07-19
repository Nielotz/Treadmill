#pragma once

#include <cstdint>
#include <iostream>

namespace treadmill_hack::platform::linux_test::gpio {

enum class Direction { INVALID, INPUT, OUTPUT, INPUT_OUTPUT, DISABLED };

template <uint16_t pin, Direction direction> class Gpio {
public:
  constexpr Gpio() {
    if constexpr (direction == Direction::DISABLED) {
      return;
    }
    if constexpr (direction == Direction::INPUT) {
      std::cout << "Configuring GPIO pin " << pin << " as INPUT." << std::endl;
    } else if constexpr (direction == Direction::INPUT_OUTPUT) {
      std::cout << "Configuring GPIO pin " << pin << " as INPUT/OUTPUT."
                << std::endl;
    } else if constexpr (direction == Direction::OUTPUT) {
      std::cout << "Configuring GPIO pin " << pin << " as OUTPUT." << std::endl;
    } else {
      static_assert(direction != Direction::INVALID,
                    "Invalid GPIO direction specified.");
    }
  }

  static const void setHigh() {
    std::cout << "Setting GPIO pin " << pin << " high." << std::endl;
  }

  static const void setLow() {
    std::cout << "Setting GPIO pin " << pin << " low." << std::endl;
  }
};
} // namespace treadmill_hack::platform::linux_test::gpio