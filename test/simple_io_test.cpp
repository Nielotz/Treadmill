#include <iostream>
#include <thread>

#include <catch2/catch_test_macros.hpp>

#include "api/config.hpp"

TEST_CASE("LED control compiles and can be called", "[io]") {
    using led = treadmill_hack::api::config::BuildInLed;
    led::setValue(false);
    // REQUIRE(led::isHigh(), "LED should be set high" );
    led::setValue(true);
    // REQUIRE(led::isLow(), "LED should be set low" );
    SUCCEED();
}