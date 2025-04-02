#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include "Field.h"
#include "Cell.h"

class Renderer {
public:
    static void DrawBoard();

    static void DrawCell(Cell& cell, CellState state);
};

#endif
