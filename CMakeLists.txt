cmake_minimum_required(VERSION 3.13)
project(adas)

# set CMake variable
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
if(CMAKE_BUILD_TYPE EQUAL DEBUG)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")
endif()

add_library(libadas INTERFACE)
target_include_directories(libadas
  INTERFACE
  ${PROJECT_SOURCE_DIR}/include
  )

# adding adas' test
add_subdirectory(test)
