#project(lab06)

set(HEADER_FILES
        inc/doubly_linked_list.h
        inc/node.h
        inc/deck.h
        )

set(SOURCE_FILES
        src/deck.cpp
        src/doubly_linked_list.cpp)
include_directories(inc)
add_library(lab6_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

#target_include_directories(lab6_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

