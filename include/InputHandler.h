#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Field.h"

class InputHandler {
public:
    static void ProcessClick(int mouseX, int mouseY, Field &board, bool isXTurn);
};

#endif
