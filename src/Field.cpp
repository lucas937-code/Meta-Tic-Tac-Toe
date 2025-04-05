#include "../include/Field.h"
#include "../include/Renderer.h"
#include "../include/Constants.h"

Field::Field(int x, int y) : BoardElement(x, y) {
    state = State::EMPTY;

    elements = std::vector<std::vector<BoardElement *>>(Constants::FIELD_AMOUNT,
                                                        std::vector<BoardElement *>(Constants::FIELD_AMOUNT, nullptr));

    for (int row = 0; row < Constants::FIELD_AMOUNT; row++) {
        for (int col = 0; col < Constants::FIELD_AMOUNT; col++) {
            elements[row][col] = new Cell(x + col * Constants::CELL_SIZE, y + row * Constants::CELL_SIZE, this);
            elementMap[elements[row][col]] = {row, col};
        }
    }
}

void Field::Draw() const {
    for (int row = 0; row < Constants::FIELD_AMOUNT; row++) {
        for (int col = 0; col < Constants::FIELD_AMOUNT; col++) {
            Renderer::FillCell(dynamic_cast<const Cell *>(elements[row][col]));
        }
    }
}
