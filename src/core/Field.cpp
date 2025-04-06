#include "Field.h"
#include "../utility/Renderer.h"
#include "../utility/Constants.h"

Field::Field(int x, int y) : BoardElement(x, y) {
    state = State::EMPTY;

    elements = std::vector<std::vector<BoardElement *>>(Constants::FIELD_AMOUNT,
                                                        std::vector<BoardElement *>(Constants::FIELD_AMOUNT, nullptr));

    forEachElement([&](int row, int col, BoardElement *&element) {
        element = new Cell(x + col * Constants::CELL_SIZE, y + row * Constants::CELL_SIZE, this);
        elementMap[element] = {row, col};
    });
}

Field::~Field() {
    forEachElement([](int row, int col, BoardElement *&element) {
        delete element;
        element = nullptr;
    });
}

void Field::Draw() {
    forEachElement([](int row, int col, BoardElement *&element) {
        Renderer::MarkCell(dynamic_cast<const Cell *>(element));
    });
}

int Field::GetSize() {
    return Constants::FIELD_SIZE;
}
