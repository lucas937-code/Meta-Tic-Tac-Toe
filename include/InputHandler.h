#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Board.h"

class InputHandler {
public:
    static void ProcessClick(int mouseX, int mouseY, Board &board, bool isXTurn);
};

#endif
