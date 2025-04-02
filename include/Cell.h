#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

enum class CellState {
    EMPTY, X, O
};

class Cell {
public:
    Cell();

    Cell(int x, int y);

    [[nodiscard]] CellState GetState() const;

    void SetState(CellState newState);

    [[nodiscard]] int GetX() const;

    [[nodiscard]] int GetY() const;

private:
    CellState state;
    int x, y;
};

#endif
