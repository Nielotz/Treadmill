#include "src/platform/platform.hpp"
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    using namespace std::chrono_literals;
    std::cout << "Blinking LED (simulated)..." << std::endl;
    for (int i = 0; i < 5; ++i) {
        treadmill_hack::platform::linux_test::config::BuiltinLed::setHigh();
        std::cout << "LED ON" << std::endl;
        std::this_thread::sleep_for(500ms);
        treadmill_hack::platform::linux_test::config::BuiltinLed::setLow();
        std::cout << "LED OFF" << std::endl;
        std::this_thread::sleep_for(500ms);
    }
    std::cout << "Blink test complete." << std::endl;
    return 0;
}