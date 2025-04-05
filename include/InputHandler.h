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
     * @return pointer to the clicked cell or nullptr if clicked outside the board
     */
    static Cell *DetermineClickedCell(int mouseX, int mouseY, Field &clickedField);

    /**
     * Determines which field was clicked on
     * @param mouseX x coordinate of the mouse
     * @param mouseY y coordinate of the mouse
     * @param game the current game which contains the fields
     * @return pointer to the clicked field or nullptr if clicked outside the board
     */
    static Field *DetermineClickedField(int mouseX, int mouseY, Game &game);
};

#endif
