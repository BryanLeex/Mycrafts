# src/external/CMakelists.txt

add_library(glad "")

target_sources(glad
PRIVATE    
    glad.c
PUBLIC
    glad.h
    khrplatform.h
)

target_include_directories(glad
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

