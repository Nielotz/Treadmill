#pragma once

#include "api/gpio.hpp"

namespace treadmill_hack {

template<api::gpio::Gpio RelayPin>
class EngineControl {
private:
    bool running = false;

public:
    void start() {
        running = true;
        RelayPin.setValue(true);
    }

    void stop() {
        running = false;
        RelayPin.setValue(false);
    }

    bool isRunning() const {
        return running;
    }
};

} // namespace treadmill_hack
