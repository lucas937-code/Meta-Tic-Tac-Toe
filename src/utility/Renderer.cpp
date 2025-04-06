#include "Renderer.h"
#include <raylib.h>
#include "Constants.h"
#include "../core/Game.h"
#include <filesystem>

constexpr int thickLineWidth = 7;
constexpr int thinLineWidth = 1;

std::unordered_map<std::string, Texture2D> Renderer::textureMap;
std::string Renderer::logMessage;

void Renderer::SetLogMessage(std::string msg) {
    logMessage = std::move(msg);
}

void Renderer::DrawBoard() {
    ClearBackground(Constants::CUSTOM_BG);

    // draw square around the board
    DrawRectangleLinesEx({static_cast<float>(Constants::OFFSET),
                          static_cast<float>(Constants::OFFSET),
                          static_cast<float>(Constants::BOARD_SIZE),
                          static_cast<float>(Constants::BOARD_SIZE)},
                         thickLineWidth,
                         WHITE);


    // draw thick lines for the meta field
    for (int i = 1; i < Constants::FIELD_AMOUNT; i++) {
        const int pos = i * Constants::FIELD_AMOUNT * Constants::CELL_SIZE + Constants::OFFSET;

        // draw vertical lines
        DrawLineEx({static_cast<float>(pos), static_cast<float>(Constants::OFFSET)},
                   {static_cast<float>(pos), static_cast<float>(Constants::BOARD_SIZE + Constants::OFFSET)},
                   thickLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({static_cast<float>(Constants::OFFSET), static_cast<float>(pos)},
                   {static_cast<float>(Constants::BOARD_SIZE + Constants::OFFSET), static_cast<float>(pos)},
                   thickLineWidth,
                   WHITE);
    }

    // draw thin lines for small fields
    for (int i = 1; i < Constants::FIELD_AMOUNT * Constants::FIELD_AMOUNT; i++) {
        // skip positions for thick lines
        if (i % Constants::FIELD_AMOUNT == 0) continue;

        const int pos = i * Constants::CELL_SIZE + Constants::OFFSET;

        // draw vertical lines
        DrawLineEx({static_cast<float>(pos), static_cast<float>(Constants::OFFSET)},
                   {static_cast<float>(pos), static_cast<float>(Constants::BOARD_SIZE + Constants::OFFSET)},
                   thinLineWidth,
                   WHITE);
        // draw horizontal lines
        DrawLineEx({static_cast<float>(Constants::OFFSET), static_cast<float>(pos)},
                   {static_cast<float>(Constants::BOARD_SIZE + Constants::OFFSET), static_cast<float>(pos)},
                   thinLineWidth,
                   WHITE);
    }
}

void Renderer::ShowLogMessage() {
    DrawText(logMessage.c_str(), 30, Constants::WINDOW_SIZE - 55, 50, WHITE);
}

void Renderer::LoadTextures() {
    for (const auto &img: std::filesystem::directory_iterator("../assets")) {
        textureMap[img.path().filename().string()] = LoadTexture(img.path().string().c_str());
    }
}

void Renderer::UnloadTextures() {
    for (const auto &[fst, snd]: textureMap) {
        UnloadTexture(snd);
    }
}

void Renderer::MarkCell(const Cell *cell) {
    Texture2D texture;
    switch (cell->GetState()) {
        case State::X:
            texture = textureMap["x.png"];
            break;
        case State::O:
            texture = textureMap["o.png"];
            break;
        default:
            return;
    }

    const Rectangle source = {0, 0,
                        static_cast<float>(texture.width),
                        static_cast<float>(texture.height)};

    const Rectangle dest = {static_cast<float>(cell->GetX()),
                      static_cast<float>(cell->GetY()),
                      static_cast<float>(Constants::CELL_SIZE),
                      static_cast<float>(Constants::CELL_SIZE)};

    DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, WHITE);
}

void Renderer::MarkFieldWinner(const Field *field) {
    Texture2D texture;
    switch (field->GetState()) {
        case State::X:
            texture = textureMap["x_white.png"];
            break;
        case State::O:
            texture = textureMap["o_white.png"];
            break;
        case State::TIE:
            texture = textureMap["tie.png"];
            break;
        default:
            return;
    }

    const Rectangle source = {0, 0,
                        static_cast<float>(texture.width),
                        static_cast<float>(texture.height)};
    const Rectangle dest = {static_cast<float>(field->GetX()),
                      static_cast<float>(field->GetY()),
                      static_cast<float>(Constants::FIELD_SIZE),
                      static_cast<float>(Constants::FIELD_SIZE)};

    DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, WHITE);
}

void Renderer::MarkTargetField(const bool isXTurn) {
    const Field *field = Game::GetTargetField();
    if (field == nullptr) return;

    const auto x = static_cast<float>(field->GetX());
    const auto y = static_cast<float>(field->GetY());
    constexpr auto size = static_cast<float>(Constants::FIELD_SIZE);
    const Color color = isXTurn ? Constants::CUSTOM_RED : Constants::CUSTOM_BLUE;
    DrawRectangleLinesEx({x, y, size, size}, thickLineWidth, color);
}

void Renderer::DrawEndScreen(const State winner) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 175});

    const auto text = std::string(winner == State::X ? "Winner: X" :
                                   winner == State::O ? "Winner: O" :
                                   winner == State::TIE ? "Game is a tie" : "Game was paused");

    DrawText(text.c_str(),
             GetScreenWidth() / 2 - MeasureText(text.c_str(), 100) / 2,
             GetScreenHeight() / 2 - 150,
             100,
             WHITE);
    DrawText("Press 'R' to restart",
             GetScreenWidth() / 2 - MeasureText("Press 'R' to restart", 100) / 2,
             GetScreenHeight() / 2,
             100,
             WHITE);
    if (winner == State::EMPTY) {
        DrawText("Or press 'B' to continue",
                 GetScreenWidth() / 2 - MeasureText("Or press 'B' to continue", 100) / 2,
                 GetScreenHeight() / 2 + 150,
                 100,
                 WHITE);
    }
}
