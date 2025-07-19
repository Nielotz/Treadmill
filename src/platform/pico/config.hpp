#pragma once

#include "gpio.hpp"
#include "pico/cyw43_arch.h"  // Onboard LED on RPI pico W is controlled via this library 

namespace treadmill_hack::config {

enum class Status {
    OK,
};

inline void init() {
    assert();  // Initialize the CYW43 driver to control led
}

    
inline gpio::BuiltInLed BuiltInLed = gpio::BuiltInLed<CYW43_WL_GPIO_LED_PIN, gpio::Direction::OUTPUT>();
} // namespace treadmill_hack::config 