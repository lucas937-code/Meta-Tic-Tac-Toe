#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

#include "BoardElement.h"
#include "Field.h"

/**
 * Represents one cell of the a field and is the smallest unit on the board
 */
class Cell : public BoardElement {
public:
    /// Initializes fields with standard values
    Cell();

    /**
     * Initializes fields with given values
     * @param x x coordinate of the cell (pixels relative to top left corner of the window)
     * @param y y coordinate of the cell (pixels relative to top left corner of the window)
     */
    Cell(int x, int y, Field *owner);

    /**
     * Getter of the owner field of the cell
     * @return pointer to the field that the cell belongs to
     */
    [[nodiscard]] Field *GetOwner();

    /**
     * Setter of the field "state"
     * @param newState
     */
    void SetState(BaseState::State newState);

private:
    Field *owner;
};

#endif
