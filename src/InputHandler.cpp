#include "../include/InputHandler.h"
#include "../include/Constants.h"

Cell *InputHandler::DetermineClickedCell(int mouseX, int mouseY, Field &clickedField) {
    for (int row = 0; row < Constants::FIELD_AMOUNT; row++) {
        for (int col = 0; col < Constants::FIELD_AMOUNT; col++) {
            Cell *cell = dynamic_cast<Cell *>(clickedField.GetElements()[row][col]);

            if (mouseX >= cell->GetX() && mouseX <= cell->GetX() + Constants::CELL_SIZE &&
                mouseY >= cell->GetY() && mouseY <= cell->GetY() + Constants::CELL_SIZE) {

                return cell;
            }
        }
    }
    return nullptr;
}

Field *InputHandler::DetermineClickedField(int mouseX, int mouseY, Game &game) {
    for (int row = 0; row < Constants::FIELD_AMOUNT; row++) {
        for (int col = 0; col < Constants::FIELD_AMOUNT; col++) {
            auto field = dynamic_cast<Field *>(game.GetElements()[row][col]);

            if (mouseX >= field->GetX() && mouseX <= field->GetX() + Constants::FIELD_SIZE &&
                mouseY >= field->GetY() && mouseY <= field->GetY() + Constants::FIELD_SIZE) {

                return field;
            }
        }
    }
    return nullptr;
}