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
        ClearBackground(BLACK);
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
        Cell *clickedCell = nullptr;

        for (int row = 0; row < FIELD_AMOUNT; row++) {
            for (int col = 0; col < FIELD_AMOUNT; col++) {
                // static cast is fine here since the window size can't be changed anyway
                int mouseX = static_cast<int>(mousePos.x);
                int mouseY = static_cast<int>(mousePos.y);

                Field &field = fields[row][col];

                if (mouseX >= field.GetX() && mouseX <= field.GetX() + BOARD_SIZE / FIELD_AMOUNT &&
                    mouseY >= field.GetY() && mouseY <= field.GetY() + BOARD_SIZE / FIELD_AMOUNT) {

                    clickedCell = InputHandler::ProcessClick(mouseX, mouseY, field, isXTurn);
                }
            }
        }
        // condition works because ProcessClick returns nullptr if state is already set
        if (clickedCell != nullptr && clickedCell->GetState() == CellState::EMPTY) {
            Renderer::FillCell(clickedCell);
        }
    }
}
