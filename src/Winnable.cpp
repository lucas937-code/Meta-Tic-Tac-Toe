#include <stdexcept>
#include "../include/Winnable.h"

std::vector<std::vector<BoardElement *>> &Winnable::GetElements() {
    return elements;
}

std::pair<int, int> &Winnable::GetElementPosition(BoardElement &element) {
    return elementMap[&element];
}

BoardElement *Winnable::GetElementByPosition(std::pair<int, int> &position) {
    for (auto &it: elementMap) {
        if (it.second == position) {
            return it.first;
        }
    }
    throw std::invalid_argument("Given position does not exist");
}

State Winnable::CheckWin() {
    bool isDraw = true;

    for (int i = 0; i < elements.size(); i++) {
        // check rows
        if (elements[i][0]->GetState() == elements[i][1]->GetState() &&
            elements[i][0]->GetState() == elements[i][2]->GetState() &&
            elements[i][0]->GetState() != State::EMPTY &&
            elements[i][0]->GetState() != State::TIE) {
            return elements[i][0]->GetState() == State::X ? State::X : State::O;
        }

        // check columns
        if (elements[0][i]->GetState() == elements[1][i]->GetState() &&
            elements[0][i]->GetState() == elements[2][i]->GetState() &&
            elements[0][i]->GetState() != State::EMPTY &&
            elements[0][i]->GetState() != State::TIE) {
            return elements[0][i]->GetState() == State::X ? State::X : State::O;
        }

        // no draw if there is an empty field left
        for (int j = 0; j < elements.size(); j++) {
            if (elements[i][j]->GetState() == State::EMPTY) {
                isDraw = false;
                break;
            }
        }
    }

    // check diagonal (top left -> bottom right)
    if (elements[0][0]->GetState() == elements[1][1]->GetState() &&
        elements[0][0]->GetState() == elements[2][2]->GetState() &&
        elements[0][0]->GetState() != State::EMPTY &&
        elements[0][0]->GetState() != State::TIE) {
        return elements[0][0]->GetState() == State::X ? State::X : State::O;
    }

    // check diagonal (top right -> bottom left)
    if (elements[0][2]->GetState() == elements[1][1]->GetState() &&
        elements[0][2]->GetState() == elements[2][0]->GetState() &&
        elements[0][2]->GetState() != State::EMPTY &&
        elements[0][2]->GetState() != State::EMPTY) {
        return elements[0][2]->GetState() == State::X ? State::X : State::O;
    }

    return isDraw ? State::TIE : State::EMPTY;
}
