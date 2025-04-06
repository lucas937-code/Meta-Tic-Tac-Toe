#ifndef METATICTACTOE_WINDOWMANAGER_H
#define METATICTACTOE_WINDOWMANAGER_H

#include "../core/Game.h"

/// @brief Contains utility functions for managing the main window
class WindowManager {
public:
    /**
     * Initializes the window and sets the target fps to 60
     * @return is window ready
     */
    static bool InitializeWindow();

    /**
     * Shows the end screen with the last state of the game in the background
     * @param game game that was just finished
     * @param winner winner of the game
     * @return if the game should be continued
     */
    static bool ShowEndScreen(Game &game, State winner);
};

#endif
