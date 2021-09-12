# phone-book examples
message(DEBUG "phone-book example")
if(OpenMP_FOUND AND Boost_FOUND)
  add_library(contact SHARED contact.cpp)
  set(PHONE_BOOK_SRC phone_book.cpp CACHE STRING "Source code of phone-book examples" FORCE)
  get_filename_component(PHONE_BOOK_EXEC ${PHONE_BOOK_SRC} NAME_WE)
  message(DEBUG "Adding ${PHONE_BOOK_EXEC} executable")
  add_executable(${PHONE_BOOK_EXEC} ${PHONE_BOOK_SRC})

  target_link_libraries(${PHONE_BOOK_EXEC} PRIVATE OpenMP::OpenMP_CXX)
  target_link_libraries(${PHONE_BOOK_EXEC} PRIVATE Boost::program_options)
  target_link_libraries(${PHONE_BOOK_EXEC} PRIVATE libadas)
  target_link_libraries(${PHONE_BOOK_EXEC} PRIVATE contact)
endif()
