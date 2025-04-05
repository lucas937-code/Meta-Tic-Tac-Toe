#ifndef METATICTACTOE_BOARDELEMENT_H
#define METATICTACTOE_BOARDELEMENT_H

/**
 * Enum class that represents the state of a cell\n
 * Can't use actual enum here because you can't inherit from an enum :/
 */
class BaseState {
public:
    enum class State {
        EMPTY,      ///< cell is empty
        X,          ///< cell is set by X
        O           ///< cell is set by O
    };
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
    [[nodiscard]] BaseState::State GetState() const;

protected:
    int x, y;
    BaseState::State state;
};

#endif
