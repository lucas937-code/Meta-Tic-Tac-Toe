#include "../include/Renderer.h"
#include "raylib.h"
#include "../include/Game.h"
#include <filesystem>
#include <utility>

const int thickLineWidth = 7;
const int thinLineWidth = 1;

std::unordered_map<std::string, Texture2D> Renderer::textureMap;
std::string Renderer::logMessage;

void Renderer::SetLogMessage(std::string msg) {
    logMessage = std::move(msg);
}

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

void Renderer::ShowLogMessage() {
    DrawText(logMessage.c_str(), 30, WINDOW_SIZE - 55, 50, WHITE);
}

void Renderer::LoadTextures() {
    std::string dirPath = "../assets";
    for (const auto &img : std::filesystem::directory_iterator(dirPath)) {
        textureMap[img.path().filename().string()] = LoadTexture(img.path().string().c_str());
    }
}

void Renderer::UnloadTextures() {
    for (const auto &texture : textureMap) {
        UnloadTexture(texture.second);
    }
}

void Renderer::FillCell(const Cell *cell) {
    Texture2D texture;
    switch (cell->GetState()) {
        case BaseState::State::X:
            texture = textureMap["x.png"];
            break;
        case BaseState::State::O:
            texture = textureMap["o.png"];
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

void Renderer::FillField(const Field *field) {
    Texture2D texture;
    switch (field->GetWinner()) {
        case ExtendedState::Winner::X:
            texture = textureMap["x_white.png"];
            break;
        case ExtendedState::Winner::O:
            texture = textureMap["o_white.png"];
            break;
        case ExtendedState::Winner::TIE:
            texture = textureMap["tie.png"];
            break;
        default:
            return;
    }

    Rectangle source = {0, 0,
                        static_cast<float>(texture.width),
                        static_cast<float>(texture.height)};
    Rectangle dest = {static_cast<float>(field->GetX()),
                      static_cast<float>(field->GetY()),
                      static_cast<float>(FIELD_SIZE),
                      static_cast<float>(FIELD_SIZE)};

    DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, WHITE);
}

void Renderer::MarkTargetField(bool isXTurn) {
    Field *field = Game::GetTargetField();
    if (field == nullptr) return;

    auto x = static_cast<float>(field->GetX());
    auto y = static_cast<float>(field->GetY());
    auto size = static_cast<float>(FIELD_SIZE);
    Color color = isXTurn ? CUSTOM_RED : CUSTOM_BLUE;
    DrawRectangleLinesEx({x, y, size, size}, thickLineWidth, color);
}
