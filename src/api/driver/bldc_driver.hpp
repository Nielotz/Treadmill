#pragma once

#include "src/gpio.hpp"

namespace treadmill_hack::bldc_driver {
class BldcDriver {
    virtual bool getMotorSpeed(int &speed) = 0;
    virtual bool setMotorSpeed(int speed) = 0;
};


} // namespace treadmill_hack::bldc_driver