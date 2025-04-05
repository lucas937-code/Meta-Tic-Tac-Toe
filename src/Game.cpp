#include "../include/Game.h"
#include <iostream>
#include "../include/Renderer.h"
#include "../include/InputHandler.h"
#include "raylib.h"

bool Game::isXTurn;
Field *Game::targetField;

Game::Game() : Winnable() {
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isRunning = IsWindowReady();
    isXTurn = true;
    targetField = nullptr;
    Renderer::SetLogMessage("It's X's Turn");

    Renderer::LoadTextures();

    elements = std::vector<std::vector<BoardElement *>>(FIELD_AMOUNT,
                                                        std::vector<BoardElement *>(FIELD_AMOUNT, nullptr));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            elements[row][col] = new Field(OFFSET + col * FIELD_SIZE, OFFSET + row * FIELD_SIZE);
            elementMap[elements[row][col]] = {row, col};
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
            auto *field = dynamic_cast<Field *>(elements[row][col]);
            field->Draw();
            Renderer::FillField(dynamic_cast<const Field *>(elements[row][col]));
        }
    }
}

Field *Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        const int mouseX = static_cast<int>(mousePos.x);
        const int mouseY = static_cast<int>(mousePos.y);

        Field *clickedField = InputHandler::DetermineClickedField(mouseX, mouseY, *this);
        if (clickedField == nullptr) return nullptr;
        if (clickedField->GetWinner() != ExtendedState::Winner::NOT_SET) {
            Renderer::SetLogMessage("Field is already sealed");
            return nullptr;
        } else if (targetField != nullptr && clickedField != targetField) {
            Renderer::SetLogMessage("Use the highlighted field");
            return nullptr;
        }

        Cell *clickedCell = InputHandler::DetermineClickedCell(mouseX, mouseY, clickedField);

        if (clickedCell == nullptr) return nullptr;

        if (clickedCell->GetState() != BaseState::State::EMPTY) {
            Renderer::SetLogMessage("Cell is already taken");
        } else {
            clickedCell->SetState(isXTurn ? BaseState::State::X : BaseState::State::O);
            Game::NextTurn();
            SetTargetField(*clickedCell);
            if (clickedField->CheckWin() != ExtendedState::Winner::NOT_SET) {
                targetField = nullptr;
            }
            return clickedField;
        }
    }
    return nullptr;
}

/*void Game::SetTargetField(Cell &cell) {
    std::pair<int, int> &cellPosition = GetElementPosition(cell);
    auto field = dynamic_cast<Field *>(GetElementByPosition(cellPosition));
    targetField = field->GetWinner() == ExtendedState::Winner::NOT_SET ? field : nullptr;
    delete field;
}*/

void Game::SetTargetField(Cell &cell) {
    std::pair<int, int> &cellPosition = cell.GetOwner()->GetElementPosition(cell);
    BoardElement *field = GetElementByPosition(cellPosition);
    std::cout << "Returned type: " << typeid(*field).name() << std::endl;
    targetField = dynamic_cast<Field *>(field->GetState() == BaseState::State::EMPTY ? field : nullptr);
}
