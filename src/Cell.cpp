#include "../include/Cell.h"

Cell::Cell() : BoardElement(), state(CellState::EMPTY) {}

Cell::Cell(int x, int y) : BoardElement(x, y), state(CellState::EMPTY) {}

CellState Cell::GetState() const {
    return state;
}

void Cell::SetState(CellState newState) {
    state = newState;
}
