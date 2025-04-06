cmake_minimum_required(VERSION 3.10)
project(MetaTicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Look for CMake modules in the local cmake/ folder
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Find raylib (requires FindRaylib.cmake in cmake/ folder)
find_package(raylib REQUIRED)

# Include directories and source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        src/core/*.cpp
        src/core/*.h
        src/utility/*.cpp
        src/utility/*.h
        main.cpp
)

add_executable(MetaTicTacToe ${SOURCES})

# Link raylib and required Windows libs
target_link_libraries(MetaTicTacToe PRIVATE raylib opengl32 gdi32 winmm)
