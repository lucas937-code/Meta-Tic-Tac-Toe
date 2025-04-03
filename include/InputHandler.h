#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Field.h"
#include "Game.h"

class InputHandler {
public:
    /**
     * Determines which cell was clicked on
     * @param mouseX x coordinate of the mouse
     * @param mouseY y coordinate of the mouse
     * @param field the field that was clicked on
     * @param isXTurn whose turn it is now
     * @return pointer to the clicked cell or nullptr if clicked outside the board
     */
    static Cell *DetermineClickedCell(int mouseX, int mouseY, std::vector<std::vector<Field>> &fields, bool isXTurn);

private:
    static Field *DetermineClickedField(std::vector<std::vector<Field>> &fields, int mouseX, int mouseY);
};

#endif
