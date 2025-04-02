cmake_minimum_required(VERSION 3.10)
project(MetaTicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Raylib-Pfad anpassen
set(RAYLIB_DIR "C:/raylib")

include_directories(${RAYLIB_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

add_executable(MetaTicTacToe main.cpp
        include/Game.h
        include/Field.h
        include/Cell.h
        include/Renderer.h
        include/InputHandler.h
        src/Game.cpp
        src/Renderer.cpp
        src/Cell.cpp
        src/Field.cpp)

target_link_libraries(MetaTicTacToe raylib opengl32 gdi32 winmm)
