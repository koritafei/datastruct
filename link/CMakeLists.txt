set(base_SRCS
  linklist/linklist.cc
  )

add_library(data_struct_base ${base_SRCS})
target_link_libraries(data_struct_base pthread)

install(TARGETS data_struct_base DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/datastruct/)

if(DATA_STRUCT_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()