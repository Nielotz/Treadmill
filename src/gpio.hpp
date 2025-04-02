#pragma once

#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

namespace treadmill_hack::gpio {

enum Direction { INVALID, INPUT, OUTPUT };

template <int pin, Direction direction, bool _enabled = true> class Gpio {
  public:
    /**
     * @brief Init GPIO pins
     */
    constexpr Gpio() {
        if constexpr (_enabled) {
            gpio_init(pin);
            if constexpr (direction == Direction::OUTPUT) {
                gpio_set_dir(pin, GPIO_OUT);
            } else if constexpr (direction == Direction::INPUT) {
                gpio_set_dir(pin, GPIO_IN);
            } else {
                static_assert(direction != Direction::INVALID, "Invalid GPIO direction specified.");
            }
        }
    }

    static const void setHigh() {
        // Ask the wifi "driver" to set the GPIO on or off
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    }

    static const void setLow() {
        // Ask the wifi "driver" to set the GPIO on or off
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    }
};

inline constexpr Gpio<-1, Direction::INVALID, false> Disabled{};
} // namespace treadmill_hack::gpio