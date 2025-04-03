#include "../include/Game.h"
#include "../include/Renderer.h"
#include "../include/InputHandler.h"
#include "raylib.h"

bool Game::isXTurn;
Field *Game::targetField;

Game::Game() {
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isRunning = IsWindowReady();
    isXTurn = true;
    targetField = nullptr;
    Renderer::SetLogMessage("It's X's Turn");

    Renderer::LoadTextures();

    fields = std::vector<std::vector<Field>>(FIELD_AMOUNT, std::vector<Field>(FIELD_AMOUNT, Field(0, 0)));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            fields[row][col] = Field(OFFSET + col * FIELD_SIZE, OFFSET + row * FIELD_SIZE);
            fieldMap[{row, col}] = &fields[row][col];
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

Field *Game::GetTargetField() {
    return targetField;
}

void Game::NextTurn() {
    isXTurn = !isXTurn;
    Renderer::SetLogMessage(isXTurn ? "It's X's Turn" : "It's O's Turn");
}

void Game::Run() {
    if (!isRunning) return;

    while (!WindowShouldClose()) {
        BeginDrawing();
        Renderer::DrawBoard();
        Draw();
        Renderer::ShowLogMessage();
        Renderer::MarkTargetField(isXTurn);
        EndDrawing();

        HandleInput();
    }
}

void Game::Draw() {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            fields[row][col].Draw();
            Renderer::FillField(fields[row][col]);
        }
    }
}

Field *Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        const int mouseX = static_cast<int>(mousePos.x);
        const int mouseY = static_cast<int>(mousePos.y);

        Field *clickedField = InputHandler::DetermineClickedField(mouseX, mouseY, fields);
        if (clickedField == nullptr) return nullptr;
        if (clickedField->GetWinner() != Winner::NOT_SET) {
            Renderer::SetLogMessage("Field is already sealed");
            return nullptr;
        } else if (targetField != nullptr && clickedField != targetField) {
            Renderer::SetLogMessage("Use the highlighted field");
            return nullptr;
        }

        Cell *clickedCell = InputHandler::DetermineClickedCell(mouseX, mouseY, clickedField, isXTurn);

        if (clickedCell == nullptr) return nullptr;

        if (clickedCell->GetState() != CellState::EMPTY) {
            Renderer::SetLogMessage("Cell is already taken");
        } else {
            clickedCell->SetState(isXTurn ? CellState::X : CellState::O);
            Game::NextTurn();
            SetTargetField(*clickedCell);
            if (clickedField->CheckWin() != Winner::NOT_SET) {
                targetField = nullptr;
            }
            return clickedField;
        }
    }
    return nullptr;
}

void Game::SetTargetField(Cell &cell) {
    std::pair<int, int> &cellPosition = Field::GetCellPosition(cell);
    Field &field = *fieldMap[cellPosition];
    targetField = field.GetWinner() == Winner::NOT_SET ? &field : nullptr;
}
