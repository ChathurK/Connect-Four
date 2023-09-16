#include <iostream>		// Handling inputs and outputs
#include <cstdlib>		// Provide general purpose functions. Such as system operations (system())
#include <limits>		// Provide information about numeric limits for different data types. Used to handle input validation

using namespace std;

const int ROWS = 6;
const int COLS = 7;
char board[ROWS][COLS];
char currentPlayer = '1';
char ch;
bool active;

// Function prototypes
void initializeBoard();
void startWindow();
void instructions();
void displayBoard();
int getPlayerMove();
bool placePiece(int column);
bool checkWin();
bool boardIsFull();
bool playAgain();
bool gameDraw();
bool playOneRound();
void goodBye();

int main()
{
    startWindow();

    bool playAnotherRound = true;
    while (playAnotherRound) 
    {
        playAnotherRound != playOneRound();
    }
    // goodBye();
    return 0;
}

void initializeBoard()
{
    // Initialize the board with empty spaces.
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard()
{		
        cout << "\t\t\t               *** CONNECT FOUR *** \n\n"
				"\t\t\t .8888888888888888888888888888888888888888888888888. \n"
                "\t\t\t B88888888888888888888888888888888888888888888888888 \n"
   				"\t\t\t B888|__1__|__2__|__3__|__4__|__5__|__6__|__7__|B888 \n"
    			"\t\t\t B888|  "<< board[0][0] <<"  |  "<< board[0][1] <<"  |  "<< board[0][2] <<"  |  "<< board[0][3] <<"  |  "<< board[0][4] <<"  |  "<< board[0][5] <<"  |  "<< board[0][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B888|  "<< board[1][0] <<"  |  "<< board[1][1] <<"  |  "<< board[1][2] <<"  |  "<< board[1][3] <<"  |  "<< board[1][4] <<"  |  "<< board[1][5] <<"  |  "<< board[1][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B888|  "<< board[2][0] <<"  |  "<< board[2][1] <<"  |  "<< board[2][2] <<"  |  "<< board[2][3] <<"  |  "<< board[2][4] <<"  |  "<< board[2][5] <<"  |  "<< board[2][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B888|  "<< board[3][0] <<"  |  "<< board[3][1] <<"  |  "<< board[3][2] <<"  |  "<< board[3][3] <<"  |  "<< board[3][4] <<"  |  "<< board[3][5] <<"  |  "<< board[3][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B888|  "<< board[4][0] <<"  |  "<< board[4][1] <<"  |  "<< board[4][2] <<"  |  "<< board[4][3] <<"  |  "<< board[4][4] <<"  |  "<< board[4][5] <<"  |  "<< board[4][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B888|  "<< board[5][0] <<"  |  "<< board[5][1] <<"  |  "<< board[5][2] <<"  |  "<< board[5][3] <<"  |  "<< board[5][4] <<"  |  "<< board[5][5] <<"  |  "<< board[5][6] <<"  |B888 \n"
    			"\t\t\t B888|_____|_____|_____|_____|_____|_____|_____|B888 \n"
    			"\t\t\t B88888888888888888888888888888888888888888888888888 \n"
    			"\t\t\t `8888888888888888888888888888888888888888888888888' \n\n";
}
 
int getPlayerMove()
{
    int column;
    active = 1;
    while (active == 1) 
    {
        // Get player movement.
        cout << "\t\t\t\tPlayer " << currentPlayer << ", enter your move (1-" << COLS << "): ";
        cin >> column;

        if (cin.good() && column >= 1 && column <= COLS)
        {
            active = 0;
            cout << endl;  
        }
        else
        {
            cin.clear(); // Clear the error flag from cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
            system("cls");
            cout << "\t\t\t\t  Invalid input. Please try again.\n\n";
            displayBoard();
        }
    }
    return column - 1; // Subtract 1 to convert to 0-based index.
}

bool placePiece(int Column)
{
    char piece;
    if (currentPlayer == '1')
    {
        piece = 'X';
    }
    else
    {
        piece = 'O';
    }

    // Place the player's movement.
    for (int i = ROWS - 1; i >= 0; --i)
    {
        if (board[i][Column] == ' ')
        {
            board[i][Column] = piece;
            return true; // Piece successfully placed.
        }
    }
    return false; // Column is full.
}

bool checkWin()
{
    system("cls");

    // Check rows for a win.
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j <= COLS - 4; ++j)
        {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3])
            {
                return true;
            }
        }
    }

    // Check columns for a win.
    for (int i = 0; i <= ROWS - 4; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j])
            {
                return true;
            }
        }
    }

    // Check diagonals from top-left to bottom-right
    for (int i = 0; i <= ROWS - 4; ++i)
    {
        for (int j = 0; j <= COLS - 4; ++j)
        {
            char currentPiece = board[i][j];
            if (currentPiece != ' ' &&
                currentPiece == board[i + 1][j + 1] &&
                currentPiece == board[i + 2][j + 2] &&
                currentPiece == board[i + 3][j + 3])
            {
                return true; // Found a win in this diagonal.
            }
        }
    }

    // Check diagonals from top-right to bottom-left
    for (int i = 0; i <= ROWS - 4; ++i)
    {
        for (int j = COLS - 1; j >= 3; --j)
        {
            char currentPiece = board[i][j];
            if (currentPiece != ' ' &&
                currentPiece == board[i + 1][j - 1] &&
                currentPiece == board[i + 2][j - 2] &&
                currentPiece == board[i + 3][j - 3])
            {
                return true; // Found a win in this diagonal.
            }
        }
    }
    return false; // No win found.
}

bool boardIsFull()
{
    // Check for empty spaces.
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false; // If there's an empty space, the board isn't full.
            }
        }
    }
    return true; // If no empty spaces are found, the board is full.
}

bool gameDraw() // Handles the game state when it ends in a draw.
{
    active = 1;
    while (active)
    {
        cout << "\t\t\t .88888888888888888888888888888888888888888888888. \n"
                "\t\t\t B888888888888888888888888888888888888888888888888 \n"
                "\t\t\t B88|                                         |B88 \n"
                "\t\t\t B88|               -----------               |B88 \n"
                "\t\t\t B88|                  DRAW!                  |B88 \n"
                "\t\t\t B88|               -----------               |B88 \n"
                "\t\t\t B88|                                         |B88 \n"
                "\t\t\t B88|   *Do you want to play again?           |B88 \n"
                "\t\t\t B88|                                         |B88 \n"
                "\t\t\t B88|      1.Yes                    2.No      |B88 \n"
                "\t\t\t B88|                                         |B88 \n"
                "\t\t\t B888888888888888888888888888888888888888888888888 \n"
                "\t\t\t 'B8888888888888888888888888888888888888888888888' \n\n"
                "\t\t\t                      =>";

        cin >> ch;

        if (ch == '1')
        {
            initializeBoard();
            active = 0;
            system("cls");
            currentPlayer = '1';
        }
        else if (ch == '2')
        {
            active = 0;
            system("cls");
            currentPlayer = '1';
            startWindow();
        }
        else
        {
            system("cls");
            cout << "\t\t\t\t Invalid input. Please try again.\n" << endl;
        }
    }
    return 1;
}

bool playAgain()
{
    active = 1;
    while (active)
    {
        cout << "\t\t\t .888888888888888888888888888888888888888888888888. \n"
                "\t\t\t B8888888888888888888888888888888888888888888888888 \n"
                "\t\t\t B88|           --------------------       *   |B88 \n"
                "\t\t\t B88|   *         Congratulations!             |B88 \n"
                "\t\t\t B88|      *    --------------------     *     |B88 \n"
                "\t\t\t B88|               Player ";cout << currentPlayer <<" won        *      |B88 \n"
                "\t\t\t B88|    *                                     |B88 \n"
                "\t\t\t B88|   *Do you want to play again?            |B88 \n"
                "\t\t\t B88|                                          |B88 \n"
                "\t\t\t B88|      1.Yes                    2.No       |B88 \n"
                "\t\t\t B88|                                          |B88 \n"
                "\t\t\t B8888888888888888888888888888888888888888888888888 \n"
                "\t\t\t 'B88888888888888888888888888888888888888888888888' \n\n"
                "\t\t\t                       =>";

        cin >> ch;

        if (ch == '1')
        {   
            initializeBoard();
            active = 0;
            system("cls");            
            currentPlayer = '1';
        }
        else if (ch == '2')
        {
            active = 0;
            system("cls");
            currentPlayer = '1';
            startWindow();
        }
        else
        {
            system("cls");
            cout << "\t\t\t\t Invalid input. Please try again.\n" << endl;
        }
    }
    return 1;
}

bool playOneRound()  // Manages the flow of one round of the game, including player turns and win/draw conditions.
{
    initializeBoard();

    bool isGameOver = false;
    while (!isGameOver)
    {
        displayBoard();
        int Column = getPlayerMove();
        if (placePiece(Column))
        {
            if (checkWin())
            {
                displayBoard();
                isGameOver != playAgain();
            }
            else if (boardIsFull())
            {
                displayBoard();
                isGameOver != gameDraw();
            }
            else if (currentPlayer == '1')
            {
                currentPlayer = '2'; // If it's currently Player 1's turn, switch to Player 2.
            }
            else
            {
                currentPlayer = '1'; // Otherwise, switch to Player 1.
            }
            // Above player switching statements can be replaced by; currentPlayer = (currentPlayer == '1') ? '2' : '1';
        }
        else
        {
            system("cls");
            cout << "\t\t\t\t Column is full. Try another column.\n" << endl;
        }
    }
    return 1;
}

void startWindow()
{
    // Starting window
    active = 1;
    while (active)
    {
        cout << "\t\t\t .8888888888888888888888888888888888888888888888888888888888. \n"
                "\t\t\t B88888888888888888888888888888888888888888888888888888888888 \n"
                "\t\t\t B88|              ------------------------              |B88 \n"
                "\t\t\t B88|                    CONNECT FOUR                    |B88 \n"
                "\t\t\t B88|              ------------------------      o       |B88 \n"
                "\t\t\t B88|   XX.                                      O       |B88 \n"
                "\t\t\t B88|    `XX.            ~ Main Menu ~           O       |B88 \n"
                "\t\t\t B88|      `XX.                                  O       |B88 \n"
                "\t\t\t B88|        `XX                                 o       |B88 \n"
                "\t\t\t B88|                      1. Play                       |B88 \n"
                "\t\t\t B88|                                                    |B88 \n"
                "\t\t\t B88|                                                    |B88 \n"
                "\t\t\t B88|                  2. Instructions          .XX      |B88 \n"
                "\t\t\t B88|                                         .XX'       |B88 \n"
                "\t\t\t B88|     OOOOOOOO                          .XX'         |B88 \n"
                "\t\t\t B88|                      3. Exit        XX'            |B88 \n"
                "\t\t\t B88|                                                    |B88 \n"
                "\t\t\t B88|____________________________________________________|B88 \n"
                "\t\t\t B88888888888888888888888888888888888888888888888888888888888 \n"
                "\t\t\t 'B888888888888888888888888888888888888888888888888888888888' \n\n"

                "\t\t\t                           =>";

        cin >> ch;

        if (ch == '1')
        {
            active = 0;
            system("cls");
            initializeBoard();
        }
        else if (ch == '2')
        {
            active = 0;
            system("cls");
            initializeBoard();
            instructions();
        }
        else if (ch == '3')
        {
            active = 0;
            system("cls");
            goodBye();
        }
        else
        {
            active = 1;
            system("cls");
            cout << "\t\t\t\t\tInvalid input. Please try again.\n\n";
        }
    }
}

void instructions()
{
    // Instructions window
    active = 1;
    while (active)
    {
        cout << "\t\t .888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888. \n"
                "\t\t B8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 \n"
                "\t\t B88|                              ------------------------                              |B88 \n"
                "\t\t B88|                                    INSTRUCTIONS                                    |B88 \n"
                "\t\t B88|                              ------------------------                              |B88 \n"
                "\t\t B88|        * Two players are required.                                                 |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88| (1)The goal of the game is to be the first player to connect for of your own dices |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88| (2)The dice of the player 1 will be marked as 'X' and the dice of the player 2     |B88 \n"
                "\t\t B88|    will be marked as '0'.                                                          |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88| (3)When a player takes turn he/she should enter the column number which his/her    |B88 \n"
                "\t\t B88|    dice need to be entered.                                                        |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88| (4)The game is won as soon as a player has four of their own discs consecutively   |B88 \n"
                "\t\t B88|    in a row, either horizontally, vertically, or diagonally.                       |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88| (5)If the entire board is filled with discs and no player has four in a row, the   |B88 \n"
                "\t\t B88|    game is declared a draw.                                                        |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88|        *Enjoy the game!                                                            |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88|                 1.Play                                   2.Back                    |B88 \n"
                "\t\t B88|                                                                                    |B88 \n"
                "\t\t B88|____________________________________________________________________________________|B88 \n"
                "\t\t B8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 \n"
                "\t\t 'B88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888' \n\n"

                "\t\t                                          =>";

        cin >> ch;

        if (ch == '1')
        {
            active = 0;
            system("cls");
        }
        else if (ch == '2')
        {
            active = 0;
            system("cls");
            startWindow();
        }
        else
        {
            active = 1;
            system("cls");
            cout << "\t\t\t\t\t      Invalid input. Please try again.\n\n";
        }
    }
}

void goodBye()
{
    cout << "\t\t .8888888888888888888888888888888888888888888888888888888888888888888888888888888. \n"
            "\t\t B88888888888888888888888888888888888888888888888888888888888888888888888888888888 \n"
            "\t\t B88|                                                                         |B88 \n"
            "\t\t B88|        oooo.                               oo                           |B88 \n"
            "\t\t B88|      88Y                                   88                           |B88 \n"
            "\t\t B88|     88P          .00**00.  .00**00.  .00**08d                           |B88 \n"
            "\t\t B88|     888    ooo   88    88  88    88  88    88                           |B88 \n"
            "\t\t B88|      88b.  ;8'   88.  ,88  88.  ,88  88.  ,88                           |B88 \n"
            "\t\t B88|       `YbooY'     *YooY*    *YooY*    *YooY*B                           |B88 \n"
            "\t\t B88|                                                                         |B88 \n"
            "\t\t B88|                                  B88oo.                                 |B88 \n"
            "\t\t B88|                                  B8  88                                 |B88 \n"
            "\t\t B88|                                  B8oo8'                oooo.    88      |B88 \n"
            "\t\t B88|                                  B8***88. `*00    00' A88*88:  :88:     |B88 \n"
            "\t\t B88|                                  B8   88;   '88  88'  88       :88:     |B88 \n"
            "\t\t B88|                                  B8888*'     '8b8Y'   'Y0oo*`   88      |B88 \n"
            "\t\t B88|                                               .B'               ..      |B88 \n"
            "\t\t B88|                                               8'                **      |B88 \n"
            "\t\t B88|                                             '*'                         |B88 \n"
            "\t\t B88|_________________________________________________________________________|B88 \n"
            "\t\t B88888888888888888888888888888888888888888888888888888888888888888888888888888888 \n"
            "\t\t 'B888888888888888888888888888888888888888888888888888888888888888888888888888888' \n";

    exit(0);
}
