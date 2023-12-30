#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

// Function to initialize the game board
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '*';
        }
    }
}

// Function to display the game board
void displayBoard(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won the game
bool checkWinner(const char board[][BOARD_SIZE], char player) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game board is full
bool isBoardFull(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    bool gameOver = false;
    char currentPlayer = 'X';

    // Main game loop
    while (!gameOver) {
        cout << "Current board:\n";
        displayBoard(board);

        int row, cols;
        cout << "Player " << currentPlayer << ", enter row and column (1-3) to place your symbol: ";
        cin >> row >> cols;

        row--;
        cols--;

        // Check for invalid move
        if (row < 0 || row >= BOARD_SIZE || cols < 0 || cols >= BOARD_SIZE || board[row][cols] != '*') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Place the player's symbol on the board
        board[row][cols] = currentPlayer;

        // Check for a winner
        if (checkWinner(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        // Check for a draw
        else if (isBoardFull(board)) {
            cout << "Game draw!\n";
            gameOver = true;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the final game board
    cout << "Final board:\n";
    displayBoard(board);

    return 0;
}