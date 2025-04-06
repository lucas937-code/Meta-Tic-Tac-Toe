#include "Cell.h"
#include "../utility/Constants.h"

Cell::Cell() : BoardElement(), owner(nullptr) {}

Cell::Cell(int x, int y, Field *owner) : BoardElement(x, y), owner(owner) {}

Field *Cell::GetOwner() {
    return owner;
}

int Cell::GetSize() {
    return Constants::CELL_SIZE;
}
