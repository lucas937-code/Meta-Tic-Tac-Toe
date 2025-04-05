#include "../include/Cell.h"

Cell::Cell() : BoardElement(), owner(nullptr) {}

Cell::Cell(int x, int y, Field *owner) : BoardElement(x, y), owner(owner) {}

Field *Cell::GetOwner() {
    return owner;
}

void Cell::SetState(BaseState::State newState) {
    state = newState;
}
