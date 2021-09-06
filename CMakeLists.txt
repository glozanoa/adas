cmake_minimum_required(VERSION 3.13)
project(adas)
enable_testing()
option(CMAKE_COMPILER_WALL "Warning all" ON)

# set CMake variable
set(CMAKE_CXX_STANDARD 20)
if(${CMAKE_COMPILER_WALL})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()
if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
  message(DEBUG "Adding -ggdb compiler flag")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb" CACHE STRING "gdb debug support" FORCE)
endif()

add_library(libadas INTERFACE)
target_include_directories(libadas
  INTERFACE
  ${PROJECT_SOURCE_DIR}
  )

# adding adas' test
add_subdirectory(tests)
