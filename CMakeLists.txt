cmake_minimum_required(VERSION 3.24)

project(kinetic LANGUAGES CXX)

add_library(kinetic INTERFACE)

target_include_directories(kinetic INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(kinetic INTERFACE cxx_std_20)

include(FetchContent)
Fetchcontent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)
enable_testing()
add_executable(kinetic_tests tests/test_math.cpp)
target_link_libraries(kinetic_tests PRIVATE kinetic Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(kinetic_tests)