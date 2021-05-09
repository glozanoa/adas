cmake_minimum_required(VERSION 3.13)
project(adas)

# set CMake variable
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#include adas' header files
include_directories(include/adas/algorithm)
include_directories(include/adas/ds)
include_directories(include/adas/utilities)
include_directories(include/adas/exceptions)

# adding test subdirectory
add_subdirectory(tests)
