cmake_minimum_required(VERSION 3.15)
project(CppColor)

set(CMAKE_CXX_STANDARD 20)

include_directories(ColorCpp)

add_executable(CppColor
        ColorCpp/LineInFunction.hpp
        ColorCpp/main.cpp
        ColorCpp/p8.cpp
        ColorCpp/p8.hpp
        ColorCpp/spans.cpp
        ColorCpp/spans.hpp
        Makefile
        README.md)
