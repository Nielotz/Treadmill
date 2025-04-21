#pragma once

#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

namespace treadmill_hack::gpio {

enum Direction { INVALID, INPUT, OUTPUT };

template <int pin, Direction direction, bool enabled = true> class Pio {
public:
  virtual void setState(bool state) = 0;
};

template <int pin, Direction direction, bool enabled = true>
class Gpio : Pio<pin, direction, enabled> {
public:
  /**
   * @brief Init GPIO pins
   */
  constexpr Gpio() {
    if constexpr (enabled) {
      gpio_init(pin);
      if constexpr (direction == Direction::OUTPUT) {
        gpio_set_dir(pin, GPIO_OUT);
      } else if constexpr (direction == Direction::INPUT) {
        gpio_set_dir(pin, GPIO_IN);
      } else {
        static_assert(direction != Direction::INVALID,
                      "Invalid GPIO direction specified.");
      }
    }
  }

  void setState(bool state) override { gpio_put(pin, state); }
};

template <int pin, Direction direction, bool enabled = true>
class BuiltInLed : public Gpio<pin, direction, enabled> {
public:
  constexpr BuiltInLed() : Gpio<pin, direction, enabled>() {
    if constexpr (enabled) {
      cyw43_arch_gpio_put(pin, 0); // Turn off the LED initially
    }
  }

  void setState(bool state) override {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
  }
};

inline constexpr Gpio<-1, Direction::INVALID, false> Disabled{};

} // namespace treadmill_hack::gpio
