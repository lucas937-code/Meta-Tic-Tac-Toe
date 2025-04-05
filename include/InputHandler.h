#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Game.h"

class InputHandler {
public:
    /**
     * Determines which cell was clicked on in the given field
     * @param mouseX x coordinate of the mouse
     * @param mouseY y coordinate of the mouse
     * @param clickedField the field that was clicked on
     * @param isXTurn whose turn it is now
     * @return pointer to the clicked cell or nullptr if clicked outside the board
     */
    static Cell *DetermineClickedCell(int mouseX, int mouseY, Field *clickedField);

    static Field *DetermineClickedField(int mouseX, int mouseY, Game &game);
};

#endif
