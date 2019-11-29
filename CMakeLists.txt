cmake_minimum_required(VERSION 3.15)
project(CppColor)

set(CMAKE_CXX_STANDARD 20)

include_directories(ColorCpp)

add_subdirectory("libs/googletest")
include(GoogleTest)
include_directories(${gtest_SOURCE_DIR})
add_executable(ColorTest
        ColorCpp/spans_test.cpp
        ColorCpp/p8_test.cpp
        )
target_link_libraries(ColorTest gtest gtest_main)

enable_testing()
add_test(ColorTest ColorTest)
