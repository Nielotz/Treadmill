#include <pico/stdio.h>

#include "config.hpp"


using namespace treadmill_hack;

int main() {
    stdio_init_all();
    config::init();  

    while (true) {
        // Blink the LED on and off every second
        config::BuiltInLed.setState(0);
        sleep_ms(1000);
        config::BuiltInLed.setState(1);
        sleep_ms(1000);
    }
 
    return 0;
}