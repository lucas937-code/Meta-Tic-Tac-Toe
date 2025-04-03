#include "../include/Renderer.h"
#include "raylib.h"
#include "../include/Game.h"
#include <string>

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

void Renderer::FillCell(const Cell *cell) {
    Texture2D texture;
    switch (cell->GetState()) {
        case CellState::X:
            texture = xTexture;
            break;
        case CellState::O:
            texture = oTexture;
            break;
        default:
            return;
    }

    Rectangle source = {0, 0,
                        static_cast<float>(texture.width),
                        static_cast<float>(texture.height)};

    Rectangle dest = {static_cast<float>(cell->GetX()),
                      static_cast<float>(cell->GetY()),
                      static_cast<float>(CELL_SIZE),
                      static_cast<float>(CELL_SIZE)};

    DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, WHITE);
}

void Renderer::FillField(Field &field) {
    Texture2D texture;
    switch (field.GetWinner()) {
        case Winner::X:
            texture = xTexture;
            break;
        case Winner::O:
            texture = oTexture;
            break;
        case Winner::TIE:
            return;
        default:
            return;
    }

    Rectangle source = {0, 0,
                        static_cast<float>(texture.width),
                        static_cast<float>(texture.height)};
    Rectangle dest = {static_cast<float>(field.GetX()),
                      static_cast<float>(field.GetY()),
                      static_cast<float>(FIELD_SIZE),
                      static_cast<float>(FIELD_SIZE)};

    DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, WHITE);
}