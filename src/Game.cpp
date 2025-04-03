#include "../include/Game.h"
#include "../include/Renderer.h"
#include "../include/InputHandler.h"
#include "raylib.h"

bool Game::isXTurn;

Game::Game() {
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isRunning = IsWindowReady();
    isXTurn = true;

    Renderer::LoadTextures();

    int fieldSize = BOARD_SIZE / FIELD_AMOUNT;
    fields = std::vector<std::vector<Field>>(FIELD_AMOUNT, std::vector<Field>(FIELD_AMOUNT, Field(0, 0)));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            fields[row][col] = Field(OFFSET + col * fieldSize, OFFSET + row * fieldSize);
        }
    }
}

Game::~Game() {
    Renderer::UnloadTextures();
    CloseWindow();
}

bool Game::IsRunning() const {
    return isRunning;
}

void Game::NextTurn() {
    isXTurn = !isXTurn;
}

void Game::Run() {
    if (!isRunning) return;

    while (!WindowShouldClose()) {
        Update();

        BeginDrawing();
        Renderer::DrawBoard();
        Draw();
        EndDrawing();

        HandleInput();
    }
}

void Game::Update() {

}

void Game::Draw() {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            fields[row][col].Draw();
        }
    }
}

void Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        const int mouseX = static_cast<int>(mousePos.x);
        const int mouseY = static_cast<int>(mousePos.y);

        Cell *clickedCell = InputHandler::DetermineClickedCell(mouseX, mouseY, fields, isXTurn);

        if (clickedCell != nullptr && clickedCell->GetState() == CellState::EMPTY) {
            clickedCell->SetState(isXTurn ? CellState::X : CellState::O);
            Game::NextTurn();
            Renderer::FillCell(clickedCell);
        }
    }
}
