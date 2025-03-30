#include "../include/Game.h"

Game::Game() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Meta TicTacToe");

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
        Update();
        Draw();
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