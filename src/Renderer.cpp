#include "../include/Renderer.h"
#include "raylib.h"
#include "../include/Game.h"

const int thickLineWidth = 7;
const int thinLineWidth = 1;

void Renderer::DrawBoard() {
    ClearBackground(CUSTOM_BG);

    // draw square around the board
    DrawRectangleLinesEx({(float) OFFSET,
                          (float) OFFSET,
                          (float) BOARD_SIZE,
                          (float) BOARD_SIZE},
                         thickLineWidth,
                         WHITE);


    // draw thick lines for the meta field
    for (int i = 1; i < FIELD_AMOUNT; i++) {
        int pos = i * FIELD_AMOUNT * CELL_SIZE + OFFSET;

        // draw vertical lines
        DrawLineEx({(float) pos, (float) OFFSET},
                   {(float) pos, (float) (BOARD_SIZE + OFFSET)},
                   thickLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({(float) OFFSET, (float) pos},
                   {(float) (BOARD_SIZE + OFFSET), (float) pos},
                   thickLineWidth,
                   WHITE);
    }

    // draw thin lines for small fields
    for (int i = 1; i < FIELD_AMOUNT * FIELD_AMOUNT; i++) {
        // skip positions for thick lines
        if (i % FIELD_AMOUNT == 0) continue;

        int pos = i * CELL_SIZE + OFFSET;

        // Vertikale Linien für kleine Felder
        DrawLineEx({(float) pos, (float) OFFSET},
                   {(float) pos, (float) (BOARD_SIZE + OFFSET)},
                   thinLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({(float) OFFSET, (float) pos},
                   {(float) (BOARD_SIZE + OFFSET), (float) pos},
                   thinLineWidth,
                   WHITE);
    }
}
