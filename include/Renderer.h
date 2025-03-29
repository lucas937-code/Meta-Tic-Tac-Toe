#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include "Board.h"
#include "Cell.h"

class Renderer {
public:
    static void DrawBoard(const Board &board);

    static void DrawCell(int x, int y, CellState state);
};

#endif
