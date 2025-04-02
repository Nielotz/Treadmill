#include "pico/stdlib.h"
#include "config.hpp"


using namespace treadmill_hack;

int main() {
    stdio_init_all();
    config::init();  

    while (true) {
        // Blink the LED on and off every second
        config::BuiltinLed::setHigh();
        sleep_ms(1000);
        config::BuiltinLed::setLow();
        sleep_ms(1000);
    }
 
    return 0;
}