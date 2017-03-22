cmake_minimum_required(VERSION 3.6)
project(argument_parser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES library.cpp library.h)
add_library(argument_parser ${SOURCE_FILES})