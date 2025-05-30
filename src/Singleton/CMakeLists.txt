# src/Singleton/CMakelists.txt

add_library(Singleton "")

target_sources(Singleton
PRIVATE    
    Singleton.cpp

PUBLIC
    Singleton.hpp
)

target_include_directories(Singleton
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

