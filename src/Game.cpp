#include "../include/Game.h"
#include "../include/Renderer.h"
#include "raylib.h"

Game::Game() {
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isXTurn = true;
    isRunning = IsWindowReady();

    int fieldSize = BOARD_SIZE / FIELD_AMOUNT;
    fields = std::vector<std::vector<Field>>(3, std::vector<Field>(3, Field(0, 0)));

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            fields[row][col] = Field(OFFSET + col * fieldSize, OFFSET + row * fieldSize);
        }
    }
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

        BeginDrawing();
        ClearBackground(BLACK);
        Renderer::DrawBoard();
        Draw();
        EndDrawing();
    }
}

void Game::Update() {

}

void Game::Draw() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            fields[row][col].Draw();
        }
    }
}