find_package(OpenMP)
find_package(Boost COMPONENTS program_options unit_test_framework)

# multi-thread algorithms
if(OpenMP_FOUND AND Boost_FOUND)
  message(DEBUG "Multi-thread algorithm examples labels")
  file(GLOB MT_ALGORITHM algorithm/sort/multithread/*.cpp algorithm/search/multithread/*.cpp)
  foreach(MT_ALGORITHM_EXAMPLE ${MT_ALGORITHM})
    get_filename_component(MT_ALGORITHM_NAME ${MT_ALGORITHM_EXAMPLE} NAME_WE)
    message(DEBUG "Adding ${MT_ALGORITHM_NAME} executable")
    add_executable(${MT_ALGORITHM_NAME} ${MT_ALGORITHM_EXAMPLE})

    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE OpenMP::OpenMP_CXX)
    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE Boost::program_options)
    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE libadas)
  endforeach()
endif()

# serial algorithms
if(Boost_FOUND)
  message(DEBUG "Serial algorithms examples labels")
  file(GLOB ALGORITHM algorithm/sort/serial/*.cpp algorithm/search/serial/*.cpp)
  foreach(ALGORITHM_EXAMPLE ${ALGORITHM})
    get_filename_component(ALGORITHM_NAME ${ALGORITHM_EXAMPLE} NAME_WE)
    message(DEBUG "Adding ${ALGORITHM_NAME} executable")
    add_executable(${ALGORITHM_NAME} ${ALGORITHM_EXAMPLE})

    target_link_libraries(${ALGORITHM_NAME} PRIVATE Boost::program_options)
    target_link_libraries(${ALGORITHM_NAME} PRIVATE libadas)
  endforeach()
endif()

# benchmarks
if(OpenMP_FOUND AND Boost_FOUND)
  message(DEBUG "Benchmark tests labels")
  file(GLOB MT_ALGORITHM benchmarks/bm_*.cpp)
  foreach(MT_ALGORITHM_EXAMPLE ${MT_ALGORITHM})
    get_filename_component(MT_ALGORITHM_NAME ${MT_ALGORITHM_EXAMPLE} NAME_WE)
    message(DEBUG "Adding ${MT_ALGORITHM_NAME} executable")
    add_executable(${MT_ALGORITHM_NAME} ${MT_ALGORITHM_EXAMPLE})

    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE OpenMP::OpenMP_CXX)
    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE Boost::program_options)
    target_link_libraries(${MT_ALGORITHM_NAME} PRIVATE libadas)
  endforeach()
endif()

# adding phone_book example
add_subdirectory(phonebook)

# # data structures
message(DEBUG "Data structures examples labels")
file(GLOB DS ds/matrix.cpp ds/node.cpp ds/binary_node.cpp ds/sllist.cpp ds/slnode.cpp ds/dlnode.cpp ds/dllist.cpp ds/dllist_initialized.cpp ds/sllist_initialized.cpp)
foreach(DS_EXAMPLE ${DS})
  get_filename_component(DS_NAME ${DS_EXAMPLE} NAME_WE)
  message(DEBUG "Adding executable ${DS_NAME}")
  add_executable(${DS_NAME} ${DS_EXAMPLE})
  target_link_libraries(${DS_NAME} PRIVATE libadas)
  if(DS_NAME STREQUAL "matrix" AND OpenMP_FOUND)
    message(DEBUG "Linking ${DS_NAME} with OpenMP library")
    target_link_libraries(${DS_NAME} PRIVATE OpenMP::OpenMP_CXX)
  endif()

endforeach()


# ## unit tests
# message(DEBUG "Compiling unit tests examples")
# if(OpenMP_FOUND AND Boost_FOUND)
#   include_directories(algorithm)
#   file(GLOB TEST unit_test/algorithm/sort/*.cpp)
#   foreach(UNIT_TEST ${TEST})
#     message(DEBUG "Path unit test:  ${ALGORITHM_EXAMPLE}")
#     get_filename_component(UNIT_TEST_NAME ${UNIT_TEST} NAME_WE)
#     message(DEBUG "Adding executable ${UNIT_TEST_NAME}")
#     #add_executable(${UNIT_TEST_NAME} ${UNIT_TEST})

#     message(DEBUG "Linking executable ${UNIT_TEST_NAME} with OpenMP, Boost::program_options and libadas")
#     # target_link_libraries(${UNIT_TEST_NAME} PRIVATE OpenMP::OpenMP_CXX)
#     # target_link_libraries(${UNIT_TEST_NAME} PRIVATE Boost::program_options)
#     # target_link_libraries(${UNIT_TEST_NAME} PRIVATE libadas)
#   endforeach()
# endif()
