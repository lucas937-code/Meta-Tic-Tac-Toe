#include "../include/Renderer.h"
#include "raylib.h"
#include "../include/Game.h"

const int boardSize = WINDOW_SIZE - 150;
const int offset = (WINDOW_SIZE - boardSize) / 2;
const int fieldAmount = 3;
const int cellSize = boardSize / (fieldAmount * fieldAmount);
const int thickLineWidth = 6;
const int thinLineWidth = 2;

void Renderer::DrawBoard() {
    ClearBackground(BLACK);

    // draw square around the board
    DrawRectangleLinesEx({(float) offset,
                          (float) offset,
                          (float) boardSize,
                          (float) boardSize},
                         thickLineWidth,
                         WHITE);


    // draw thick lines for the meta field
    for (int i = 1; i < fieldAmount; i++) {
        int pos = i * fieldAmount * cellSize + offset;

        // draw vertical lines
        DrawLineEx({(float) pos, (float) offset},
                   {(float) pos, (float) (boardSize + offset)},
                   thickLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({(float) offset, (float) pos},
                   {(float) (boardSize + offset), (float) pos},
                   thickLineWidth,
                   WHITE);
    }

    // draw thin lines for small fields
    for (int i = 1; i < fieldAmount * fieldAmount; i++) {
        // skip positions for thick lines
        if (i % fieldAmount == 0) continue;

        int pos = i * cellSize + offset;

        // Vertikale Linien für kleine Felder
        DrawLineEx({(float) pos, (float) offset},
                   {(float) pos, (float) (boardSize + offset)},
                   thinLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({(float) offset, (float) pos},
                   {(float) (boardSize + offset), (float) pos},
                   thinLineWidth,
                   WHITE);
    }
}
