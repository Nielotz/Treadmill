#include <catch2/catch_test_macros.hpp>

#include "api/config.hpp"

TEST_CASE("LED control compiles and can be called", "[io]") {
    using led = treadmill_hack::api::config::BuildInLed;
    led::setValue(false);
    REQUIRE(led::_getValue() == false);
    led::setValue(true);
    REQUIRE(led::_getValue() == true);
    SUCCEED();
}