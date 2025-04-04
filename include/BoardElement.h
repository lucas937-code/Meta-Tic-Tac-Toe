#ifndef METATICTACTOE_BOARDELEMENT_H
#define METATICTACTOE_BOARDELEMENT_H

class BoardElement {
public:
    BoardElement();
    BoardElement(int x, int y);

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

protected:
    int x, y;
};

#endif //METATICTACTOE_BOARDELEMENT_H
