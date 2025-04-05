#ifndef METATICTACTOE_BOARDELEMENT_H
#define METATICTACTOE_BOARDELEMENT_H

/**
 * Enum class that represents the state of a cell\n
 * Can't use actual enum here because you can't inherit from an enum :/
 */
enum class State {
    EMPTY,      ///< cell is empty or field has empty cell
    X,          ///< cell is set by X or field is won by X
    O,          ///< cell is set by O or field is won by O
    TIE         ///< field is a tie
};

class BoardElement {
public:
    BoardElement();

    BoardElement(int x, int y);

    virtual ~BoardElement() = default;

    /**
     * Getter of the x coordinate of the element (pixels relative to top left corner of the window)
     * @return copy of "x"
     */
    [[nodiscard]] int GetX() const;

    /**
     * Getter of the y coordinate of the element (pixels relative to top left corner of the window)
     * @return copy of "y"
     */
    [[nodiscard]] int GetY() const;

    /**
     * Getter of the state
     * @return copy of "state"
     */
    [[nodiscard]] State GetState() const;

    /**
     * Setter of the state
     * @param newState
     */
    void SetState(State newState);

protected:
    int x, y;
    State state;
};

#endif
