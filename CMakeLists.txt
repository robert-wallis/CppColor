cmake_minimum_required(VERSION 3.15)
project(CppColor)

include_directories(ColorCpp)

add_subdirectory("libs/googletest")
include(GoogleTest)
include_directories(${gtest_SOURCE_DIR})

add_executable(ColorTest)

add_library(Edabit OBJECT
    ColorCpp/Edabit/transform_letter.cpp
    ColorCpp/Edabit/transform_reducer.cpp
    ColorCpp/Edabit/double_letter.cpp
    ColorCpp/Edabit/automorphic_numbers.cpp
)
target_link_libraries(Edabit gtest)
set_property(TARGET Edabit PROPERTY CXX_STANDARD 17)

if(WIN32)
    target_link_libraries(ColorTest gtest gtest_main Edabit)
else()
    add_library(Cpp20 OBJECT
            ColorCpp/Cpp20/spans_test.cpp
            ColorCpp/Cpp20/p8_test.cpp
            )
    target_link_libraries(Cpp20 gtest)
    set_property(TARGET Cpp20 PROPERTY CXX_STANDARD 20)

    target_link_libraries(ColorTest gtest gtest_main Edabit Cpp20)
endif()


enable_testing()
add_test(ColorTest ColorTest)
