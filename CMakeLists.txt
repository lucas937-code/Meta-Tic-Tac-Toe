cmake_minimum_required(VERSION 3.10)
project(MetaTicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Raylib-Pfad anpassen
set(RAYLIB_DIR "C:/raylib")

include_directories(${RAYLIB_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

add_executable(MetaTicTacToe main.cpp
        src/core/Game.h
        src/core/Field.h
        src/core/Cell.h
        src/utility/Renderer.h
        src/utility/InputHandler.h
        src/core/Game.cpp
        src/utility/Renderer.cpp
        src/core/Cell.cpp
        src/core/Field.cpp
        src/utility/InputHandler.cpp
        src/core/BoardElement.h
        src/core/BoardElement.cpp
        src/core/Winnable.h
        src/core/Winnable.cpp
        src/utility/Constants.h
        src/utility/WindowManager.h
        src/utility/WindowManager.cpp)

target_link_libraries(MetaTicTacToe raylib opengl32 gdi32 winmm)
