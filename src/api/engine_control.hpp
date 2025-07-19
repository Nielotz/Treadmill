#pragma once

#include "src/gpio.hpp"

namespace treadmill_hack {

// Simple engine control class for testing purposes
template<typename RelayPin>
class EngineControl {
private:
    RelayPin& relay;
    bool running = false;

public:
    explicit EngineControl(RelayPin& relay_pin) : relay(relay_pin) {}

    void start() {
        running = true;
        relay.setState(true);
    }

    void stop() {
        running = false;
        relay.setState(false);
    }

    bool isRunning() const {
        return running;
    }
};

} // namespace treadmill_hack
