cmake_minimum_required(VERSION 3.6)
project(CppAP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -std=c++14" )

set(SOURCE_FILES CppAP_library.hpp CppAP_Test.cpp)
file(GLOB SOURCES
        CppAP_Test.cpp
        CppAP_library.hpp
        )

add_executable(CppAP ${SOURCES})