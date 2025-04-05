#ifndef METATICTACTOE_WINNABLE_H
#define METATICTACTOE_WINNABLE_H

#include <unordered_map>
#include <vector>
#include <functional>
#include "BoardElement.h"

class Winnable {
public:
    /**
     * Getter of the element 3x3 matrix
     * @return reference to "elements"
     */
    [[nodiscard]] std::vector<std::vector<BoardElement *>> &GetElements();

    /**
     * Uses the elementMap to determine the position of the given element
     * @return reference to pair of (row, col)
     */
    std::pair<int, int> &GetElementPosition(BoardElement &element);

    /**
     * Searches the elementMap for a BoardElement with the given position
     * @param position reference to the position in the element matrix (row, col)
     * @return pointer to the corresponding BoardElement or nullptr if there is no element at that position
     */
    BoardElement *GetElementByPosition(std::pair<int, int> &position);

    /**
     * Determines if a player has won
     * @return winner of the winnable as a state
     */
    State CheckWin();

    /**
     * Executes the passed lambda function for every element in the element matrix
     * @param function lambda function that is to be executed
     */
    void forEachElement(const std::function<void(int row, int col, BoardElement *&element)> &function);

protected:
    std::vector<std::vector<BoardElement *>> elements;
    std::unordered_map<BoardElement *, std::pair<int, int>> elementMap;
};

#endif
