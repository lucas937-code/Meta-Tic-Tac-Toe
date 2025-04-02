#ifndef METATICTACTOE_INPUTHANDLER_H
#define METATICTACTOE_INPUTHANDLER_H

#include "Field.h"

class InputHandler {
public:
    static void ProcessClick(int mouseX, int mouseY, Field &field, bool isXTurn);
};

#endif
