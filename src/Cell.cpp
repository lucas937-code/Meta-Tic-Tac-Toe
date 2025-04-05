#include "../include/Cell.h"

Cell::Cell() : BoardElement() {}

Cell::Cell(int x, int y) : BoardElement(x, y) {}

void Cell::SetState(BaseState::State newState) {
    state = newState;
}
