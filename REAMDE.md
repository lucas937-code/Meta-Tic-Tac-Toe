# ❌ Meta-Tic-Tac-Toe ⭕️

A C++ implementation of a *Meta-Tic-Tac-Toe* game, where each cell of a classic 
3x3 board is itself a complete Tic-Tac-Toe game. 

Players compete to win three subgames in a row to achieve victory on the meta level. Player X begins.
Clicking a cell sends the next player to the corresponding field. If the field is already sealed, the next player can
choose freely where to make their next move.

You can find the detailed ruleset on 
[tictactoefree.com](https://tictactoefree.com/ultimate-tic-tac-toe/rules).

---

## 🎮 Controls

- **Left Click**: Place your mark
- **Enter**: Pause current game and show end screen
- **B**: Continue the paused game
- **R**: Restart the game from the end screen
- **Escape**: Exit the application

---

## 🖥️ Development Environment

- **Operating System**: Windows 11 (64-bit)
- **Compiler**: g++ via MinGW (v14.2.0)
- **CMake Version**: 3.31.5
- **Raylib Version**: 5.5
- **Build Tool**: Ninja
- **IDE**: CLion

---

## ⚙️ Requirements & Setup

### Requirements
- C++17 or later
- [Raylib](https://www.raylib.com/) (recommended: v5.5 or later)
- CMake

### Setup instructions


👉 You can also use the [prebuilt version here](./bin/MetaTicTacToe.exe) to try it out directly (Windows only).

TODO

---

## 📁 Project structure

```
.
├── assets/               → X/O images and tie graphic
│
├── src/
│   ├── core/             → Game logic and architecture
│   │
│   └── utility/          → utilities for input, rendering & window management
│
├── main.cpp              → Program entry point
│
├── CMakeLists.txt
│
└── README.md             → You’re reading this 🎉
```

---

## 🧠 Architecture Overview 

- **Game:** Top-level manager of game state and main loop
- **Field:** Represents a subgame (3x3 grid of cells)
- **Cell:** Holds the state of a single square in a subgame
- **BoardElement & Winnable:** Abstract logic for win-checking
- **InputHandler:** Processes user input (mouse clicks)
- **Renderer:** Responsible for rendering all visuals (board, X/O, winner screen)
- **WindowManager:** Handles window lifecycle and endscreen display

---

## 📚 Doxygen documentation

The project uses [Doxygen](https://www.doxygen.nl/download.html) for generating code documentation. If you want to generate 
and view the documentation locally, make sure you have Doxygen installed. You can then run the following command in the project root:

```bash
doxygen Doxyfile
```

This will generate the documentation in the `docs/` folder. By default, it is available in HTML, LaTeX and XML. 

---

## 🎓 Academic Note

This project was created as part of the university course "Programming in C++" at the
Berlin School of Economics and Law.