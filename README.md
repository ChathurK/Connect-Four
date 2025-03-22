# Connect Four (Four in a Row)

This is a simple console-based implementation of the classic Connect Four game using C++.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Connect Four is a two-player connection game in which the players take turns dropping colored discs from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.

This implementation uses procedural programming, a programming paradigm based on the concept of procedure calls, where statements are structured into procedures (also known as routines or functions).

## Features

- Two-player game
- Interactive command-line interface
- Input validation
- Instructions and game rules display
- Option to play again or exit

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/ChathurK/Connect-Four.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Connect-Four
    ```
3. Compile the source code:
    ```sh
    g++ ConnectFour.cpp -o ConnectFour
    ```

## Usage

1. Run the compiled executable:
    ```sh
    ./ConnectFour
    ```
2. Follow the on-screen instructions to play the game.

## Game Rules

1. The game is played on a grid that's 7 columns by 6 rows.
2. Player 1's pieces are marked as 'X' and Player 2's pieces are marked as 'O'.
3. Players take turns to drop their pieces into one of the columns.
4. The first player to get four of their pieces in a row (vertically, horizontally, or diagonally) wins.
5. If the board is full and no player has four in a row, the game is declared a draw.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
