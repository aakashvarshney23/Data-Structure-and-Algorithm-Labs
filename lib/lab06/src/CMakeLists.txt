project(Lab4_lib)

set(HEADER_FILES
        doubly_linked_list.h
        node.h
        deck.h
        )

set(SOURCE_FILES
        deck.cpp
        )

add_library(Lab6_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})


