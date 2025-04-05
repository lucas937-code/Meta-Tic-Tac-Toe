#include "../include/Field.h"
#include "../include/Game.h"
#include "../include/Renderer.h"

Field::Field(int x, int y) : BoardElement(x, y) {
    winner = ExtendedState::Winner::NOT_SET;

    elements = std::vector<std::vector<BoardElement *>>(FIELD_AMOUNT, std::vector<BoardElement *>(FIELD_AMOUNT, nullptr));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            elements[row][col] = new Cell(x + col * CELL_SIZE, y + row * CELL_SIZE);
            elementMap[elements[row][col]] = {row, col};
        }
    }
}

void Field::Draw() const {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Renderer::FillCell(dynamic_cast<const Cell *>(elements[row][col]));
        }
    }

    // TODO remove - debugging only (mark field centers)
    /*int centerX = x + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    int centerY = y + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    DrawLine(centerX - 10, centerY - 10, centerX + 10, centerY + 10, RED);
    DrawLine(centerX - 10, centerY + 10, centerX + 10, centerY - 10, RED);*/
}