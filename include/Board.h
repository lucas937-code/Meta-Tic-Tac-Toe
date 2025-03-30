#ifndef METATICTACTOE_BOARD_H
#define METATICTACTOE_BOARD_H

#include <vector>
#include "Cell.h"

enum class Winner { TIE, X, O };

class Board {
public:
    Board(bool isMainBoard);

    void Draw();

    void HandleClick(int mouseX, int mouseY, bool isXTurn);

    bool checkWin();

private:
    std::vector<std::vector<Cell>> cells;
    int cellSize;
    int boardSize;
    bool isMainBoard;
    Winner winner;
};

#endif
