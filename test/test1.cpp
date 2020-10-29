#include <catch2/catch.hpp>

#include <template/template.h>

TEST_CASE("Basic functionality", "[basic]") {
    SECTION("Check that the version is greater than 0.0.0") {
        REQUIRE(TEMPLATE_VERSION > 0);
    }
}

TEST_CASE("Advanced functionality", "[advanced]") {
    arosen::Template::MyVeryOwnClass myClass(1,8);
    REQUIRE(myClass.sum() == 9);
}
