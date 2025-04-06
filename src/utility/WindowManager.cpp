#include "WindowManager.h"
#include "Constants.h"
#include "Renderer.h"

bool WindowManager::InitializeWindow() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(Constants::WINDOW_SIZE, Constants::WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);
    return IsWindowReady();
}

bool WindowManager::ShowEndScreen(Game &game, State winner) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.Draw();
        Renderer::DrawEndScreen(winner);
        EndDrawing();

        if (IsKeyPressed(KEY_R)) return false;
        if (IsKeyPressed(KEY_B) && winner == State::EMPTY) return true;
    }
    return false;
}
