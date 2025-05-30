add_library(AsyncLog "")

target_sources(AsyncLog
    PRIVATE    
    AsyncLog.cpp

    PUBLIC
    AsyncLog.hpp
)

# target_include_directories(AsyncLog
#     ${CMAKE_CURRENT_LIST_DIR}
# )

