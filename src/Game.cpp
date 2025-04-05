#include "../include/Game.h"
#include "../include/Constants.h"
#include "../include/Renderer.h"
#include "../include/InputHandler.h"
#include "raylib.h"

bool Game::isXTurn;
Field *Game::targetField;

Game::Game() : Winnable() {
    InitWindow(Constants::WINDOW_SIZE, Constants::WINDOW_SIZE, "Meta TicTacToe");
    SetTargetFPS(60);

    isRunning = IsWindowReady();
    isXTurn = true;
    targetField = nullptr;
    Renderer::SetLogMessage("It's X's Turn");

    Renderer::LoadTextures();

    elements = std::vector<std::vector<BoardElement *>>(Constants::FIELD_AMOUNT,
                                                        std::vector<BoardElement *>(Constants::FIELD_AMOUNT, nullptr));

    forEachElement([&](int row, int col, BoardElement *&element) {
        element = new Field(Constants::OFFSET + col * Constants::FIELD_SIZE,
                            Constants::OFFSET + row * Constants::FIELD_SIZE);
        elementMap[element] = {row, col};
    });
}

Game::~Game() {
    forEachElement([](int row, int col, BoardElement *&element) {
        delete element;
        element = nullptr;
    });
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

        if (HandleInput() == nullptr) continue;

        State winner = this->CheckWin();
        if (winner == State::EMPTY) continue;
        Renderer::SetLogMessage(winner == State::X ? "X has won" : winner == State::O ? "O has won" : "Game is a tie");
    }
}

void Game::Draw() {
    forEachElement([](int row, int col, BoardElement *&element) {
        auto *field = dynamic_cast<Field *>(element);
        field->Draw();
        Renderer::FillField(dynamic_cast<const Field *>(element));
    });
}

Field *Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        const int mouseX = static_cast<int>(mousePos.x);
        const int mouseY = static_cast<int>(mousePos.y);

        auto *clickedField = dynamic_cast<Field *>(InputHandler::DetermineClickedElement(mouseX, mouseY, *this));
        if (clickedField == nullptr) return nullptr;
        if (clickedField->GetState() != State::EMPTY) {
            Renderer::SetLogMessage("Field is already sealed");
            return nullptr;
        } else if (targetField != nullptr && clickedField != targetField) {
            Renderer::SetLogMessage("Use the highlighted field");
            return nullptr;
        }

        auto clickedCell = dynamic_cast<Cell *>(InputHandler::DetermineClickedElement(mouseX, mouseY, *clickedField));

        if (clickedCell == nullptr) return nullptr;     // shouldn't be possible anyway but safety first
        if (clickedCell->GetState() != State::EMPTY) {
            Renderer::SetLogMessage("Cell is already taken");
            return nullptr;
        }

        clickedCell->SetState(isXTurn ? State::X : State::O);
        NextTurn();
        clickedField->SetState(clickedField->CheckWin());
        targetField = DetermineTargetField(*clickedCell);
        return clickedField;
    }
    return nullptr;
}

Field *Game::DetermineTargetField(Cell &cell) {
    Field *ownerField = cell.GetOwner();
    if (ownerField == nullptr || ownerField->GetState() != State::EMPTY) return nullptr;

    std::pair<int, int> &cellPosition = ownerField->GetElementPosition(cell);
    auto *field = dynamic_cast<Field *>(GetElementByPosition(cellPosition));
    return field->GetState() == State::EMPTY ? field : nullptr;
}
