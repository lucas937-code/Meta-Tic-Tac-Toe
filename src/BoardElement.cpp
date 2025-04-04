#include "../include/BoardElement.h"

BoardElement::BoardElement() : x(0), y(0) {}

BoardElement::BoardElement(int x, int y) : x(x), y(y) {}

int BoardElement::GetX() const {
    return x;
}

int BoardElement::GetY() const {
    return y;
}
