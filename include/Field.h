#ifndef METATICTACTOE_FIELD_H
#define METATICTACTOE_FIELD_H

#include <vector>
#include <unordered_map>
#include "Cell.h"

/// Enum class that is used to declare the winner of \b one \b field
enum class Winner {
    NOT_SET,     ///< No winner yet
    TIE,         ///< Tie on the field
    X,           ///< player X has won this field
    O            ///< player O has one this field
};

/**
 * Represents one of the 9 fields of the whole board\n
 * contains 9 cells
 */
class Field {
public:
    /**
     * Initializes the cells of the field
     * @param x x coordinate of the field (pixels relative to top left corner of the window)
     * @param y y coordinate of the field (pixels relative to top left corner of the window)
     */
    Field(int x, int y);

    /**
     * Getter of field "cells"
     * @return reference to object "cells"
     */
    [[nodiscard]] std::vector<std::vector<Cell>> &GetCells();

    /**
     * Uses the cellMap to determine the position of the given cell
     * @return pair of (row, col)
     */
     std::pair<int, int> GetCellPosition(Cell &cell);

    /// Draws cells of the field
    void Draw() const;

    /**
     * Getter of field "x"\n
     * x = x coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "x"
     */
    [[nodiscard]] int GetX() const;

    /**
     * Getter of field "y"\n
     * y = y coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "y"
     */
    [[nodiscard]] int GetY() const;

    /**
     * Getter of field "winner"
     * @return copy of "winner"
     */
     [[nodiscard]] Winner GetWinner() const;

    /**
     * Determines if a player has won the game and sets the winner if so
     * @return winner of the field
     */
    Winner CheckWin();

private:
    std::vector<std::vector<Cell>> cells;
    std::unordered_map<Cell*, std::pair<int, int>> cellMap;
    Winner winner;
    int x, y;
};

#endif
