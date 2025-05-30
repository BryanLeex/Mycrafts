add_library(GL "")

target_sources(GL
    PRIVATE    
    GL.cpp
    glad.c

    PUBLIC
    GL.hpp
)

target_include_directories(GL
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

find_package(glfw3 REQUIRED)

target_link_libraries(GL
    PRIVATE
    glfw
)

