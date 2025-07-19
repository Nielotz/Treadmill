#include "src/api/bldc_driver.hpp"

template <gpio::PinIn FR = gpio::Disabled, gpio::PinIn BRK = gpio::Disabled,
          gpio::PinIn PWM = gpio::Disabled, gpio::PinOut ALM = gpio::Disabled,
          gpio::PinIn SV = gpio::Disabled, gpio::PinOut EN = gpio::Disabled,
          gpio::PinOut SPEED = gpio::Disabled>
class BLDH400R : BldcDriver {
public:
  bool getMotorSpeed(int &speed) override { return 0; }
  bool setMotorSpeed(int speed) override { return 0; }
};