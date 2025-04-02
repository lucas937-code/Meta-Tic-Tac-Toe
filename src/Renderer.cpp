#include "../include/Renderer.h"
#include "raylib.h"
#include "../include/Game.h"

const int thickLineWidth = 7;
const int thinLineWidth = 1;

Texture2D Renderer::xTexture;
Texture2D Renderer::oTexture;

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

void Renderer::LoadTextures() {
    xTexture = LoadTexture("../assets/x.png");
    oTexture = LoadTexture("../assets/o.png");
}

void Renderer::UnloadTextures() {
    UnloadTexture(xTexture);
    UnloadTexture(oTexture);
}

void Renderer::DrawCell(const Cell &cell) {
    Texture2D texture;
    Rectangle source;
    Rectangle dest = {(float) cell.GetX(), (float) cell.GetY(), (float) CELL_SIZE, (float) CELL_SIZE};

    switch (cell.GetState()) {
        case CellState::X:
            texture = xTexture;
            source = {0, 0, static_cast<float>(xTexture.width), static_cast<float>(xTexture.height)};
            break;
        case CellState::O:
            texture = oTexture;
            source = {0, 0, static_cast<float>(oTexture.width), static_cast<float>(oTexture.height)};
            break;
        default:
            return;
    }

    DrawTexturePro(texture, source, dest,{0, 0},0.0f,WHITE);
}
