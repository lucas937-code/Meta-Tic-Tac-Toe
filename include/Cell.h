#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

enum class CellState { EMPTY, X, O };

class Cell {
public:
    Cell();

    void Draw();

    void SetState(CellState state);

    CellState GetState() const;

private:
    CellState state;
};

#endif
