find_package(OpenMP REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options unit_test_framework)

# multithread algorithms
if(OpenMP_FOUND AND Boost_FOUND)
  include_directories(algorithm)
  file(GLOB MT_ALGORITHM algorithm/sort/mt_*.cpp algorithm/search/mt_*.cpp)
  foreach(MT_ALGORITHM_EXAMPLE ${MT_ALGORITHM})
    get_filename_component(MT_ALGORITHM_NAME ${MT_ALGORITHM_EXAMPLE} NAME)
    add_executable(${MT_ALGORITHM_NAME} ${MT_ALGORITHM_EXAMPLE})

    target_link_libraries(${MT_ALGORITHM_NAME} PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(${MT_ALGORITHM_NAME} PUBLIC Boost::program_options)
    target_link_libraries(${MT_ALGORITHM_NAME} libadas)
  endforeach()
endif()

# serial algorithms
if(Boost_FOUND)
  file(GLOB ALGORITHM algorithm/sort/*.cpp algorithm/search/*.cpp)
  foreach(ALGORITHM_EXAMPLE ${ALGORITHM})
    get_filename_component(ALGORITHM_NAME ${ALGORITHM_EXAMPLE} NAME)
    add_executable(${ALGORITHM_NAME} ${ALGORITHM_EXAMPLE})

    target_link_libraries(${ALGORITHM_NAME} PUBLIC Boost::program_options)
    target_link_libraries(${ALGORITHM_NAME} libadas)
  endforeach()
endif()

# data structures
file(GLOB DS ds/*.cpp)
foreach(DS_EXAMPLE ${DS})
  get_filename_component(DS_NAME ${DS_EXAMPLE} NAME)
  add_executable(${DS_NAME} ${DS_EXAMPLE})
  target_link_libraries(${DS_NAME} libadas)
endforeach()


## unit tests
if(OpenMP_FOUND AND Boost_FOUND)
  include_directories(algorithm)
  file(GLOB TEST unit_test/algorithm/sort/*.cpp)
  foreach(UNIT_TEST ${TEST})
    get_filename_component(UNIT_TEST_NAME ${UNIT_TEST} NAME)
    add_executable(${UNIT_TEST_NAME} ${UNIT_TEST})

    target_link_libraries(${UNIT_TEST_NAME} PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(${UNIT_TEST_NAME} PUBLIC Boost::program_options)
    target_link_libraries(${UNIT_TEST_NAME} libadas)
  endforeach()
endif()
