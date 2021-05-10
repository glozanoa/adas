find_package(OpenMP REQUIRED)

if(OpenMP_FOUND)
  include_directories(${OpenMP_CXX_INCLUDE_DIRS})

  # multithread algorithms entry points
  include_directories(algorithm)
  file(GLOB MT_ALGORITHM algorithm/sort/mt_*.cpp algorithm/search/mt_*.cpp)
  foreach(MT_ALGORITHM_TEST ${MT_ALGORITHM})
    get_filename_component(MT_ALGORITHM_NAME ${MT_ALGORITHM_TEST} NAME)
    add_executable(${MT_ALGORITHM_NAME} ${MT_ALGORITHM_TEST})
    target_link_libraries(${MT_ALGORITHM_NAME} OpenMP::OpenMP_CXX)
  endforeach()
endif()

# serial algorithms entry points
file(GLOB ALGORITHM algorithm/sort/*.cpp algorithm/search/*.cpp)
foreach(ALGORITHM_TEST ${ALGORITHM})
  get_filename_component(ALGORITHM_NAME ${ALGORITHM_TEST} NAME)
  add_executable(${ALGORITHM_NAME} ${ALGORITHM_TEST})
  #target_link_libraries(${ALGORITHM_NAME} OpenMP::OpenMP_CXX)
endforeach()

# data structure tests entry points
file(GLOB DS ds/*.cpp)
foreach(DS_TEST ${DS})
  get_filename_component(DS_NAME ${DS_TEST} NAME)
  add_executable(${DS_NAME} ${DS_TEST})
endforeach()
