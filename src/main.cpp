#include "platform/platform.hpp"

using namespace treadmill_hack::platform::config;

int main() {
    while (true) {
        BuiltinLed::setHigh();
        BuiltinLed::setHigh();
        BuiltinLed::setHigh();
    }
 
    return 0;
}