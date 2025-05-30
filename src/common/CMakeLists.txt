# src/common/CMakelists.txt

add_library(common "")

target_sources(common
    PRIVATE    
    common.cpp

    PUBLIC
    common.hpp
)

target_include_directories(common
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

