#include "kinetic/vec3.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace kinetic;

TEST_CASE("Random test", "[math]") {
    REQUIRE(Vec3{1, 2, 3}.x == 1);
}
