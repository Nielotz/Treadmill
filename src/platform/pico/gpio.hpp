#pragma once

#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"
#include "src/platform/gpio.hpp"

#include <cstdint>
#include <cassert>

namespace treadmill_hack::platform::pico::gpio {

enum class Direction { INVALID, INPUT, OUTPUT, INPUT_OUTPUT, DISABLED };

template <uint16_t pin, Direction direction> class Gpio {
  public:
  constexpr Gpio() {
    if constexpr (direction == Direction::DISABLED) {
      return;
    }
    if constexpr (pin == CYW43_WL_GPIO_LED_PIN) {
      assert(cyw43_arch_init() == 0);
    } else {
      gpio_init(pin);
    }
    if constexpr (direction == Direction::INPUT) {
      gpio_set_dir(pin, GPIO_IN);
    } else if constexpr (direction == Direction::OUTPUT) {
      gpio_set_dir(pin, GPIO_OUT);
    } else {
      static_assert(direction != Direction::INVALID,
                    "Invalid GPIO direction specified.");
    }
  }

  static const void setHigh() {
    cyw43_arch_gpio_put(pin, 1);
  }

  static const void setLow() {
    cyw43_arch_gpio_put(pin, 0);
  }
};

inline constexpr Gpio<-1, Direction::DISABLED> Disabled{};
} // namespace treadmill_hack::gpio