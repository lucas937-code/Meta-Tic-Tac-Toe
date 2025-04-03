#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

/// Enum class that represents the state of a cell
enum class CellState {
    EMPTY,      ///< cell is empty
    X,          ///< cell is set by X
    O           ///< cell is set by O
};

/**
 * Represents one cell of the a field and is the smallest unit on the board
 */
class Cell {
public:
    /// Initializes fields with standard values
    Cell();

    /**
     * Initializes fields with given values
     * @param x x coordinate of the cell (pixels relative to top left corner of the window)
     * @param y y coordinate of the cell (pixels relative to top left corner of the window)
     */
    Cell(int x, int y);

    /**
     * Getter of the field "state"
     * @return copy of the current state of the cell
     */
    [[nodiscard]] CellState GetState() const;

    /**
     * Setter of the field "state"
     * @param newState
     */
    void SetState(CellState newState);

    /**
     * Getter of the field "x"\n
     * x = x coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "x"
     */
    [[nodiscard]] int GetX() const;

    /**
     * Getter of the field "y"\n
     * y = y coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "y"
     */
    [[nodiscard]] int GetY() const;

private:
    CellState state;
    int x, y;
};

#endif
