#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Field.h"

class InputHandler {
public:
    /**
     * Set state of the clicked field and go to next turn if the clicked cell is still empty
     * @param mouseX x coordinate of the mouse
     * @param mouseY y coordinate of the mouse
     * @param field the field that was clicked on
     * @param isXTurn whose turn it is now
     * @return pointer to the clicked cell
     */
    static Cell *ProcessClick(int mouseX, int mouseY, Field &field, bool isXTurn);
};

#endif
