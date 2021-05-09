find_package(OpenMP REQUIRED)

if(OpenMP_FOUND)
  include_directories(${OpenMP_CXX_INCLUDE_DIRS})

  # multithread algorithms entry points
  file(GLOB MT_ALGORITHM algorithm/sort/mt_*.cpp algorithm/search/mt_*.cpp)
  foreach(MT_ALGORITHM_TEST ${MT_ALGORITHM})
    add_executable(${MT_ALGORITHM_TEST})
    target_link_libraries(${MT_ALGORITHM_TEST} ${OpenMP_CXX_LIBRARIES})
  endforeach()
endif()

# serial algorithms entry points
file(GLOB ALGORITHM algorithm/sort/*.cpp algorithm/search/*.cpp)
foreach(ALGORITHM_TEST ${ALGORITHM})
  add_executable(${ALGORITHM_TEST})
endforeach()

# serial data structure tests entry points
file(GLOB DS ds/*.cpp)
foreach(DS_TEST ${DS})
  add_executable(${DS_TEST})
endforeach()
