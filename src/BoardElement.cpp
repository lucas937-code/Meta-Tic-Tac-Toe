#include "../include/BoardElement.h"

BoardElement::BoardElement() : x(0), y(0), state(State::EMPTY) {}

BoardElement::BoardElement(int x, int y) : x(x), y(y), state(State::EMPTY) {}

int BoardElement::GetX() const {
    return x;
}

int BoardElement::GetY() const {
    return y;
}

State BoardElement::GetState() const {
    return state;
}

void BoardElement::SetState(State newState) {
    state = newState;
}
