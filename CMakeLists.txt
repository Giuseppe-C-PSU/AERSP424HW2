cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(Homework2 src/main.cpp src/q1.cpp include/q1.h src/q2.cpp include/q2.h)