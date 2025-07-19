#pragma once

// Platform selection - change this to switch platforms
#ifdef PLATFORM_PICO
    #include "src/platform/pico/gpio.hpp"
    #include "src/platform/pico/config.hpp"
    namespace treadmill_hack::platform {
        using namespace treadmill_hack::platform::pico;
    }
#elif defined(PLATFORM_LINUX_TEST)
    #include "src/platform/linux_test/gpio.hpp"
    #include "src/platform/linux_test/config.hpp"
    namespace treadmill_hack::platform {
        using namespace treadmill_hack::platform::linux_test;
    }
#else
    #error "No platform selected! Define PLATFORM_*"
#endif