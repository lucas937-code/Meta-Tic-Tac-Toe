#include "../include/InputHandler.h"
#include "../include/Game.h"
#include "raylib.h"

void InputHandler::ProcessClick(int mouseX, int mouseY, Field &field, bool isXTurn) {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Cell &cell = field.GetCells()[row][col];

            if (mouseX >= cell.GetX() && mouseX <= cell.GetX() + CELL_SIZE &&
                mouseY >= cell.GetY() && mouseY <= cell.GetY() + CELL_SIZE) {

                if (cell.GetState() == CellState::EMPTY) {
                    cell.SetState(isXTurn ? CellState::X : CellState::O);
                    Game::NextTurn();
                }
            }
        }
    }
}