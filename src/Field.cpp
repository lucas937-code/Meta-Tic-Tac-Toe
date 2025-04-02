#include "../include/Field.h"
#include "../include/Game.h"

Field::Field(int x, int y) : x(x), y(y), winner(Winner::NOT_SET) {
    cells.resize(FIELD_AMOUNT, std::vector<Cell>(FIELD_AMOUNT));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            cells[row][col] = Cell(x + col * CELL_SIZE, y + row * CELL_SIZE);
        }
    }
}

void Field::Draw() const {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            cells[row][col].Draw();
        }
    }

    // TODO remove - debugging only (mark field centers)
    /*int centerX = x + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    int centerY = y + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    DrawLine(centerX - 5, centerY - 5, centerX + 5, centerY + 5, RED);
    DrawLine(centerX - 5, centerY + 5, centerX + 5, centerY - 5, RED);*/
}

std::vector<std::vector<Cell>> Field::GetCells() const {
    return cells;
}
