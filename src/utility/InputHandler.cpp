#include "InputHandler.h"

BoardElement *InputHandler::DetermineClickedElement(int mouseX, int mouseY, Winnable &winnable) {
    BoardElement *boardElement = nullptr;

    winnable.forEachElement([&mouseX, &mouseY, &boardElement](int row, int col, BoardElement *&element) {
        if (mouseX >= element->GetX() && mouseX <= element->GetX() + element->GetSize() &&
            mouseY >= element->GetY() && mouseY <= element->GetY() + element->GetSize()) {
            boardElement = element;
        }
    });
    return boardElement;
}
