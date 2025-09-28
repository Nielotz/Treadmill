#pragma once

#include "../gpio.hpp"

namespace treadmill_hack::api::config {

using BuildInLed = treadmill_hack::platform::linux_test::gpio::BuildInLed;

inline void initializePlatform() {}

} // namespace treadmill_hack::api::config
