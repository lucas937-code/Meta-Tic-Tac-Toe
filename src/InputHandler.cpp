#include "../include/InputHandler.h"

Cell *InputHandler::DetermineClickedCell(int mouseX, int mouseY, Field *clickedField) {
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

Field *InputHandler::DetermineClickedField(int mouseX, int mouseY, std::vector<std::vector<Field>> &fields) {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Field &field = fields[row][col];

            if (mouseX >= field.GetX() && mouseX <= field.GetX() + FIELD_SIZE &&
                mouseY >= field.GetY() && mouseY <= field.GetY() + FIELD_SIZE) {

                return &field;
            }
        }
    }
    return nullptr;
}