#include "../include/InputHandler.h"
#include "../include/Constants.h"

BoardElement *InputHandler::DetermineClickedElement(int mouseX, int mouseY, Winnable &winnable) {
    for (int row = 0; row < Constants::FIELD_AMOUNT; row++) {
        for (int col = 0; col < Constants::FIELD_AMOUNT; col++) {
            BoardElement *element = winnable.GetElements()[row][col];
            if (mouseX >= element->GetX() && mouseX <= element->GetX() + element->GetSize() &&
                mouseY >= element->GetY() && mouseY <= element->GetY() + element->GetSize()) {
                return element;
            }
        }
    }
    return nullptr;
}
