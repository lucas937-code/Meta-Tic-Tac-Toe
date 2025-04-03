#include "../include/Field.h"
#include "../include/Game.h"
#include "../include/Renderer.h"

std::unordered_map<Cell *, std::pair<int, int>> Field::cellMap;

Field::Field(int x, int y) : x(x), y(y), winner(Winner::NOT_SET) {
    cells.resize(FIELD_AMOUNT, std::vector<Cell>(FIELD_AMOUNT));

    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            cells[row][col] = Cell(x + col * CELL_SIZE, y + row * CELL_SIZE);
            cellMap[&cells[row][col]] = {row, col};
        }
    }
}

void Field::Draw() const {
    for (int row = 0; row < FIELD_AMOUNT; row++) {
        for (int col = 0; col < FIELD_AMOUNT; col++) {
            Renderer::FillCell(&cells[row][col]);
        }
    }

    // TODO remove - debugging only (mark field centers)
    /*int centerX = x + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    int centerY = y + ((BOARD_SIZE / FIELD_AMOUNT) / 2);
    DrawLine(centerX - 10, centerY - 10, centerX + 10, centerY + 10, RED);
    DrawLine(centerX - 10, centerY + 10, centerX + 10, centerY - 10, RED);*/
}

std::vector<std::vector<Cell>> &Field::GetCells() {
    return cells;
}

std::pair<int, int> &Field::GetCellPosition(Cell &cell) {
    return cellMap[&cell];
}

int Field::GetX() const {
    return x;
}

int Field::GetY() const {
    return y;
}

Winner Field::GetWinner() const {
    return winner;
}

Winner Field::CheckWin() {
    bool isDraw = true;

    for (int i = 0; i < FIELD_AMOUNT; i++) {
        // check rows
        if (cells[i][0].GetState() == cells[i][1].GetState() &&
            cells[i][0].GetState() == cells[i][2].GetState() &&
            cells[i][0].GetState() != CellState::EMPTY) {
            return winner = cells[i][0].GetState() == CellState::X ? Winner::X : Winner::O;
        }

        // check columns
        if (cells[0][i].GetState() == cells[1][i].GetState() &&
            cells[0][i].GetState() == cells[2][i].GetState() &&
            cells[0][i].GetState() != CellState::EMPTY) {
            return winner = cells[0][i].GetState() == CellState::X ? Winner::X : Winner::O;
        }

        // no draw if there is an empty field left
        for (int j = 0; j < FIELD_AMOUNT; j++) {
            if (cells[i][j].GetState() == CellState::EMPTY) {
                isDraw = false;
                break;
            }
        }
    }

    // check diagonal (top left -> bottom right)
    if (cells[0][0].GetState() == cells[1][1].GetState() &&
        cells[0][0].GetState() == cells[2][2].GetState() &&
        cells[0][0].GetState() != CellState::EMPTY) {
        return winner = cells[0][0].GetState() == CellState::X ? Winner::X : Winner::O;
    }

    // check diagonal (top right -> bottom left)
    if (cells[0][2].GetState() == cells[1][1].GetState() &&
        cells[0][2].GetState() == cells[2][0].GetState() &&
        cells[0][2].GetState() != CellState::EMPTY) {
        return winner = cells[0][2].GetState() == CellState::X ? Winner::X : Winner::O;
    }

    return winner = isDraw ? Winner::TIE : Winner::NOT_SET;
}
