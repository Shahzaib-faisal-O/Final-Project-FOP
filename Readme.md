# Eater and Passer Game

This repository contains the C implementation of the **Eater and Passer Game**, a strategic multiplayer or single-player game where players take turns to dominate the board by creating paths or blocking the opponent. The game involves dynamic memory allocation, recursion, and interactive gameplay.

## Features

- **Game Modes**:
  - Multiplayer mode: Two players can play against each other.
  - Single-player mode: Play against a computer.
- **Dynamic Board**: Allows users to define the board size (minimum 3x3, maximum 9x9).
- **Custom Logic**:
  - "Passer" wins by creating a connected path from top to bottom.
  - "Eater" wins by preventing the "Passer" from achieving their goal.
- **Interactive Gameplay**: Provides visual representation of the board and animations.

## Technologies Used

- **C Language**: Core programming language.
- **Libraries**: Utilizes `stdio.h`, `stdlib.h`, `unistd.h`, and others for efficient game logic and UI.

## Project Structure

```
.
├── src
│   ├── game_logic.c      # Implements core game mechanics.
│   ├── display.c         # Handles board rendering and UI.
│   ├── main.c            # Entry point of the application.
│   └── utilities.c       # Includes helper functions for game operations.
├── include
│   ├── game_logic.h
│   ├── display.h
│   └── utilities.h
├── Makefile              # Build automation tool.
```

## How to Run

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Shahzaib-faisal-O/Final-Project-FOP.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd eater_passer_game
   ```

3. **Build the Project**:

   ```bash
   make
   ```

4. **Run the Game**:

   ```bash
   ./game
   ```

5. **Gameplay Instructions**:
   - Enter the board size (3x3 to 9x9).
   - Select game mode (multiplayer or vs computer).
   - Play according to the rules displayed in the game.

## Functions Overview

### Core Functions

- `void displayScreen()`: Displays the game menu and handles mode selection.
- `void Gamestart()`: Initializes the game board and starts gameplay.
- `void Showboard(int size, int **board)`: Renders the current state of the game board.
- `void logic_of_game(int size, int **board, int **check)`: Implements game logic for both players.
- `bool endgame(int size, int **board)`: Checks if the board is full and ends the game if so.
- `bool win_condition(int size, int **board, int y, int x, int **check)`: Validates if a player meets the win conditions.
- `bool valid_move(int size, int **board, int x, int y)`: Ensures that the move is valid on the board.

### Code Snippets

#### Example: Board Display

```c
void Showboard(int size, int **board) {
    printf("ROW:COLUMN:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            switch (board[i][j]) {
                case 0: printf("|*|"); break;
                case 1: printf("|P|"); break;
                case 2: printf("|E|"); break;
            }
        }
        printf("\n");
    }
}
```

## Hardware/Software Requirements

- **Hardware**:
  - Computer or Laptop
  - Mouse and Keyboard
- **Software**:
  - IDE: Code::Blocks or DEV C/C++
  - GCC Compiler

## Future Enhancements

- Add graphical interface for better user experience.
- Implement advanced AI for computer mode.
- Enhance performance for larger board sizes.

## Acknowledgements

- **Shahzaib Faisal** (Roll No: 2212349) for project lead and coding.
- **Aatir Raza** (Roll No: 221277) for analysis and documentation.
- Special thanks to **Abid Ali** and **Miss Bakhtawar** for guidance and support.

## License

This project is licensed under the [MIT License](LICENSE).

---

Enjoy the game! Feel free to contribute and report issues.
