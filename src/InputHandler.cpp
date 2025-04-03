#include "../include/InputHandler.h"

Cell *InputHandler::DetermineClickedCell(int mouseX, int mouseY, std::vector<std::vector<Field>> &fields,  bool isXTurn) {
    Field *clickedField = DetermineClickedField(fields, mouseX, mouseY);
    if (clickedField == nullptr) return nullptr;

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Cell &cell = clickedField->GetCells()[row][col];

            if (mouseX >= cell.GetX() && mouseX <= cell.GetX() + CELL_SIZE &&
                mouseY >= cell.GetY() && mouseY <= cell.GetY() + CELL_SIZE) {

                return &cell;
            }
        }
    }
    return nullptr;
}

Field *InputHandler::DetermineClickedField(std::vector<std::vector<Field>> &fields, int mouseX, int mouseY) {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Field &field = fields[row][col];
            const int fieldSize = BOARD_SIZE / FIELD_AMOUNT;

            if (mouseX >= field.GetX() && mouseX <= field.GetX() + fieldSize &&
                mouseY >= field.GetY() && mouseY <= field.GetY() + fieldSize) {

                return &field;
            }
        }
    }
    return nullptr;
}