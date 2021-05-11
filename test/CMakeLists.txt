find_package(OpenMP REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options unit_test_framework)

# multi-thread algorithms
message(DEBUG "Compiling multi-thread algorithm examples")
if(OpenMP_FOUND AND Boost_FOUND)
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
message(DEBUG "Compiling serial algorithms examples")
if(Boost_FOUND)
  file(GLOB ALGORITHM algorithm/sort/serial/*.cpp algorithm/search/serial/*.cpp)
  foreach(ALGORITHM_EXAMPLE ${ALGORITHM})
    get_filename_component(ALGORITHM_NAME ${ALGORITHM_EXAMPLE} NAME_WE)
    message(DEBUG "Adding ${ALGORITHM_NAME} executable")
    add_executable(${ALGORITHM_NAME} ${ALGORITHM_EXAMPLE})

    target_link_libraries(${ALGORITHM_NAME} PRIVATE Boost::program_options)
    target_link_libraries(${ALGORITHM_NAME} PRIVATE libadas)
  endforeach()
endif()

# # data structures
# message(DEBUG "Compiling data structures examples")
# file(GLOB DS ds/*.cpp)
# foreach(DS_EXAMPLE ${DS})
#   message(DEBUG "Path ds example:  ${DS_EXAMPLE}")
#   get_filename_component(DS_NAME ${DS_EXAMPLE} NAME_WE)
#   message(DEBUG "Adding executable ${DS_NAME}")
#   #add_executable(${DS_NAME} ${DS_EXAMPLE})
#   message(DEBUG "Linking executable ${DS_NAME} with libadas")
#   #target_link_libraries(${DS_NAME} libadas)
# endforeach()


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
