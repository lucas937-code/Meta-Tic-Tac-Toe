#ifndef METATICTACTOE_WINNABLE_H
#define METATICTACTOE_WINNABLE_H

#include <unordered_map>
#include <vector>
#include <functional>
#include "BoardElement.h"

/**
 * Represents a thing that can be won in a game, so a field or the game itself\n
 * It's mainly used for managing the matrix of board elements that both a game and a field contains
 */
class Winnable {
public:
    /**
     * @brief Uses the elementMap to determine the position of the given element
     * @return reference to pair of (row, col)
     */
    std::pair<int, int> &GetElementPosition(BoardElement &element);

    /**
     * @brief Searches the elementMap for a BoardElement with the given position
     * @param position reference to the position in the element matrix (row, col)
     * @return pointer to the corresponding BoardElement or nullptr if there is no element at the given position
     */
    BoardElement *GetElementByPosition(std::pair<int, int> &position);

    /**
     * @brief Determines if a player has won
     * @return winner of the winnable as a state
     */
    State CheckWin();

    /**
     * @brief Executes the passed lambda function for every element in the element matrix
     * @param function lambda function that is to be executed
     */
    void forEachElement(const std::function<void(int row, int col, BoardElement *&element)> &function);

protected:
    /// @brief Matrix of board element that the winnable contains
    std::vector<std::vector<BoardElement *>> elements;

    /// @brief Map that assigns every element its position in the matrix< (indicated as (row, col))
    std::unordered_map<BoardElement *, std::pair<int, int>> elementMap;
};

#endif
