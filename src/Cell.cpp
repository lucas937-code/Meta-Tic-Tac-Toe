#include "../include/Cell.h"
#include "raylib.h"

Cell::Cell(int x, int y) : x(x), y(y), state(CellState::EMPTY) {}

void Cell::Draw() const {
    if (state == CellState::X) {
        DrawText("X", x + 10, y + 10, 40, RED);
    } else if (state == CellState::O) {
        DrawText("O", x + 10, y + 10, 40, BLUE);
    }

    // TODO remove in prod - debugging only (inscribe cells):
    // DrawText(TextFormat("(%d, %d)", x, y), x + 5, y + 5, 20, GREEN);
}

CellState Cell::GetState() const {
    return state;
}
