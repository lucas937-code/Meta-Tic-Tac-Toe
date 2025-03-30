#include "../include/Game.h"
#include "../include/Renderer.h"

Game::Game() {
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isXTurn = true;
    isRunning = IsWindowReady();
}

Game::~Game() {
    if (IsRunning()) {
        CloseWindow();
    }
}

bool Game::IsRunning() const {
    return isRunning;
}

void Game::Run() {
    if (!isRunning) return;

    while (!WindowShouldClose()) {
        BeginDrawing();
        Renderer::DrawBoard();
        EndDrawing();
    }
}

void Game::Update() {

}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Raylib funktioniert!", 300, 280, 20, RAYWHITE);
    EndDrawing();
}