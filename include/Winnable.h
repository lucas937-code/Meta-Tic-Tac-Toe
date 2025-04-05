#ifndef METATICTACTOE_WINNABLE_H
#define METATICTACTOE_WINNABLE_H

#include <unordered_map>
#include <vector>
#include "BoardElement.h"

class Winnable {
public:
    /**
     * Getter of the element matrix
     * @return reference to "elements"
     */
    [[nodiscard]] std::vector<std::vector<BoardElement *>> &GetElements();

    /**
     * Uses the elementMap to determine the position of the given element
     * @return reference to pair of (row, col)
     */
    std::pair<int, int> &GetElementPosition(BoardElement &element);

    BoardElement *GetElementByPosition(std::pair<int, int> &position);

    /**
     * Determines if a player has won
     * @return winner of the winnable
     */
    State CheckWin();

protected:
    std::vector<std::vector<BoardElement *>> elements;
    std::unordered_map<BoardElement *, std::pair<int, int>> elementMap;
};

#endif
