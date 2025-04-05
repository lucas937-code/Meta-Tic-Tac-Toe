#include "../include/InputHandler.h"

Cell *InputHandler::DetermineClickedCell(int mouseX, int mouseY, Field *clickedField) {
    if (clickedField == nullptr) return nullptr;

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Cell *cell = dynamic_cast<Cell*>(clickedField->GetElements()[row][col]);

            if (mouseX >= cell->GetX() && mouseX <= cell->GetX() + CELL_SIZE &&
                mouseY >= cell->GetY() && mouseY <= cell->GetY() + CELL_SIZE) {

                return cell;
            }
        }
    }
    return nullptr;
}

Field *InputHandler::DetermineClickedField(int mouseX, int mouseY, Game &game) {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            auto field = dynamic_cast<Field *>(game.GetElements()[row][col]);

            if (mouseX >= field->GetX() && mouseX <= field->GetX() + FIELD_SIZE &&
                mouseY >= field->GetY() && mouseY <= field->GetY() + FIELD_SIZE) {

                return field;
            }
        }
    }
    return nullptr;
}