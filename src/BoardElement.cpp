#include "../include/BoardElement.h"

BoardElement::BoardElement() : x(0), y(0), state(BaseState::State::EMPTY) {}

BoardElement::BoardElement(int x, int y) : x(x), y(y), state(BaseState::State::EMPTY) {}

int BoardElement::GetX() const {
    return x;
}

int BoardElement::GetY() const {
    return y;
}

BaseState::State BoardElement::GetState() const {
    return state;
}
