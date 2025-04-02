#include "../include/Cell.h"

Cell::Cell() : x(0), y(0), state(CellState::EMPTY) {}

Cell::Cell(int x, int y) : x(x), y(y), state(CellState::EMPTY) {}

CellState Cell::GetState() const {
    return state;
}

void Cell::SetState(CellState newState) {
    state = newState;
}

int Cell::GetX() const {
    return x;
}

int Cell::GetY() const {
    return y;
}
