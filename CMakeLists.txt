cmake_minimum_required(VERSION 3.13)
project(adas)

# options for compilation
option(COPY_DATA "Copy data to debug adas")

# set CMake variable
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
if(CMAKE_BUILD_TYPE EQUAL DEBUG)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")
endif()

# Copy data to debug algorithms
if(COPY_DATA)
  message(STATUS "Copying data to test algorithms to ${CMAKE_BINARY_DIR}/test/data")
  file(COPY test/data/*.txt "${CMAKE_BINARY_DIR}/test/data")
endif()

#include adas' header files
include_directories(include/adas/algorithm)
include_directories(include/adas/ds)
include_directories(include/adas/utilities)
include_directories(include/adas/exceptions)

# adding test subdirectory
add_subdirectory(test)
