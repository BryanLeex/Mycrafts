# src/CMakelists.txt

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Singleton)
add_subdirectory(AsyncLog)
add_subdirectory(common)
add_subdirectory(GL)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    Singleton
    AsyncLog
    common
    GL
)
