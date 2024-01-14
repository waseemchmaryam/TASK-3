#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1)
            cout << "---------" << endl;
    }
    cout << endl;
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool checkWin(char player) {
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

bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';

    do {
        initializeBoard();
        bool gameWon = false;

        do {
            displayBoard();

            int row, col;
            cout << "Player " << currentPlayer << ", Enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(row, col)) {
                board[row][col] = currentPlayer;
                gameWon = checkWin(currentPlayer);

                if (!gameWon) {
                    if (isBoardFull()) {
                        cout << "It's a draw!" << endl;
                        break;
                    }
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } while (!gameWon);

        displayBoard();

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }

    } while (true);

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}

