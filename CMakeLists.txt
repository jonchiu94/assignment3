cmake_minimum_required(VERSION 3.12)
project(assignment3)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-Wall -Wextra -pedantic -std=c++14)
add_executable(assignment3 heap.hpp main.cpp)