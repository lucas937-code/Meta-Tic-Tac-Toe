#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

enum class CellState {
    EMPTY, X, O
};

class Cell {
public:
    Cell() : x(0), y(0), state(CellState::EMPTY) {}

    Cell(int x, int y);

    int x, y;

    [[nodiscard]] CellState GetState() const;

    void Draw() const;

private:
    CellState state;
};

#endif
