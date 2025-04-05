#ifndef METATICTACTOE_WINNABLE_H
#define METATICTACTOE_WINNABLE_H

#include <unordered_map>
#include <vector>
#include "BoardElement.h"

/**
 * Enum class that is used to declare the winner of \b one \b field\n
 * Can't use actual enum here so inheriting becomes possible
 */
class ExtendedState : public BaseState {
public:
    enum class Winner {
        NOT_SET = static_cast<int>(BaseState::State::EMPTY),
        X = static_cast<int>(BaseState::State::X),
        O = static_cast<int>(BaseState::State::O),
        TIE
    };
};

class Winnable {
public:
    /**
     * Getter of field "winner"
     * @return copy of "winner"
     */
    [[nodiscard]] ExtendedState::Winner GetWinner() const;

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
    ExtendedState::Winner CheckWin();

protected:
    ExtendedState::Winner winner;
    std::vector<std::vector<BoardElement *>> elements;
    std::unordered_map<BoardElement *, std::pair<int, int>> elementMap;
};

#endif
