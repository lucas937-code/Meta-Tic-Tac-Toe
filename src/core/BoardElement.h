#ifndef METATICTACTOE_BOARDELEMENT_H
#define METATICTACTOE_BOARDELEMENT_H

/**
 * Enum class that represents the state of a BoardElement\n
 *
 * - `EMPTY`: The cell is empty or the field contains one or more empty cells.\n
 * - `X`: The cell is marked by X or the field is won by X.\n
 * - `O`: The cell is marked by O or the field is won by O.\n
 * - `TIE`: The field has reached a tie (no winner).\n
 */
enum class State {
    EMPTY,
    X,
    O,
    TIE
};

/// Abstract class that represents an element of the board, so either a cell or a field
class BoardElement {
public:
    /// @brief Default constructor that initializes x & y to 0 and the state to EMPTY
    BoardElement();

    /**
     * @brief Constructor that initializes x & y with the given values and the state as EMPTY
     * @param x x coordinate of the element (pixels relative to top left corner of the window)
     * @param y y coordinate of the element (pixels relative to top left corner of the window)
     */
    BoardElement(int x, int y);

    /// @brief Virtual default destructor to make polymorphism possible
    virtual ~BoardElement() = default;

    /**
     * @brief Abstract method that returns the size of the element\n
     * The method must be implemented by derived classes to specify their own size.
     *
     * @return size of the element in pixels
     */
    [[nodiscard]] virtual int GetSize() = 0;

    /**
     * @brief Getter for the x coordinate of the element (pixels relative to top left corner of the window)
     * @return copy of the x coordinate
     */
    [[nodiscard]] int GetX() const;

    /**
     * @brief Getter for the y coordinate of the element (pixels relative to top left corner of the window)
     * @return copy of the y coordinate
     */
    [[nodiscard]] int GetY() const;

    /**
     * @brief Getter for the state
     * @return copy of "state"
     */
    [[nodiscard]] State GetState() const;

    /**
     * @brief Setter for the state
     * @param newState new state of the element
     */
    void SetState(State newState);

protected:
    /// @brief Coordinates of the element (relative to the top left corner of the window)
    int x, y;

    /// @brief Current state of the element
    State state;
};

#endif
