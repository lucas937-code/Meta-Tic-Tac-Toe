#include "../include/WindowManager.h"
#include "../include/Constants.h"
#include "../include/Renderer.h"

bool WindowManager::InitializeWindow() {
    InitWindow(Constants::WINDOW_SIZE, Constants::WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);
    return IsWindowReady();
}

void WindowManager::ShowEndScreen(Game &game, State winner) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.Draw();
        Renderer::DrawEndScreen(winner);
        EndDrawing();

        if (IsKeyPressed(KEY_R)) return;
    }
}
