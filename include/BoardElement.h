#ifndef METATICTACTOE_BOARDELEMENT_H
#define METATICTACTOE_BOARDELEMENT_H

/**
 * Enum class that represents the state of a BoardElement\n
 */
enum class State {
    EMPTY,      ///< cell is empty or field has one or more empty cells
    X,          ///< cell is set by X or field is won by X
    O,          ///< cell is set by O or field is won by O
    TIE         ///< field is a tie
};

class BoardElement {
public:
    /**
     * Default constructor\n
     * Initializes x & y as 0 and state as EMPTY
     */
    BoardElement();

    /**
     * Constructor with given x & y\n
     * Initializes state as EMPTY
     * @param x x coordinate of the element (pixels relative to top left corner of the window)
     * @param y y coordinate of the element (pixels relative to top left corner of the window)
     */
    BoardElement(int x, int y);

    /// virtual default destructor to make polymorphism possible
    virtual ~BoardElement() = default;

    [[nodiscard]] virtual int GetSize() = 0;

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
     * @param newState new state of the element
     */
    void SetState(State newState);

protected:
    int x, y;
    State state;
};

#endif
