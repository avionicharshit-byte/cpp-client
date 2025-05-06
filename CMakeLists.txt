cmake_minimum_required(VERSION 3.14)
project(tofupilot-client VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library target
add_library(tofupilot
        src/client.cpp
        src/models.cpp
)

target_include_directories(tofupilot
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Install rules
include(GNUInstallDirs)
install(TARGETS tofupilot
        EXPORT tofupilot-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Add examples
add_executable(basic_example examples/basic_usage.cpp)
target_link_libraries(basic_example PRIVATE tofupilot)