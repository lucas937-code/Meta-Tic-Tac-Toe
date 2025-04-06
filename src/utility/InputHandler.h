#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "../core/Game.h"

/// Contains utility functions for handling user inputs
class InputHandler {
public:
    /**
     * Determines which element was clicked on
     * @param mouseX x coordinate of the mouse
     * @param mouseY y coordinate of the mouse
     * @param game the winnable object which contains the elements
     * @return pointer to the clicked element or nullptr if clicked outside the board
     */
    static BoardElement *DetermineClickedElement(int mouseX, int mouseY, Winnable &winnable);
};

#endif
