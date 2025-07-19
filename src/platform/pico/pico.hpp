#include "pico/stdlib.h"

namespace treadmill_hack::platform::pico {
    void init() {
        gpio_init();
    }
}