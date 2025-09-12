#include <iostream>
using namespace std;

const int SIZE = 3;

void printBoard(char board[SIZE][SIZE]) {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---------\n";
    }
    cout << "\n";
}

bool checkWinner(char board[SIZE][SIZE], char player) {
    //Checks row
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Checks Column
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
     // Checks Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void ticTacToe() {
    char board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';

    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameOver) {
        printBoard(board);
        int row, col;

        cout << "Player " << currentPlayer << "'s turn.\n";
        cout << "Enter row (0-2): ";
        cin >> row;
        cout << "Enter column (0-2): ";
        cin >> col;

        // check input
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            cout << "Invalid input! Try again.\n";
            continue;
        }
        if (board[row][col] != ' ') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner(board, currentPlayer)) {
            printBoard(board);
            cout << " Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        
        else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        }
        else {
        
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char choice;
    do {
        ticTacToe();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!  \n";
    return 0;
}
