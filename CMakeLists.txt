cmake_minimum_required(VERSION 3.24)

project(kinetic LANGUAGES CXX)

add_library(kinetic INTERFACE)

target_include_directories(kinetic INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(kinetic INTERFACE cxx_std_20)