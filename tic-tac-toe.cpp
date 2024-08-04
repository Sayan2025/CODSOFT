#include <iostream>
#include <limits>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player1, player2;
int row, column;
char current_token = 'X';
bool is_draw = false;

void displayBoard() {
    cout << "    |     |    " << endl;
    cout << board[0][0] << "   |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << board[1][0] << "   |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << board[2][0] << "   |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "    |     |    " << endl;
}

void makeMove() {
    int choice;
    if (current_token == 'X') {
        cout << player1 << ", enter your move (1-9): ";
    } else {
        cout << player2 << ", enter your move (1-9): ";
    }
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid integer: \n";
    }

    else{

        if (choice < 1 || choice > 9){
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            makeMove();
            return;
        }

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (board[row][column] != 'X' && board[row][column] != 'O') {
            board[row][column] = current_token;
            current_token = (current_token == 'X') ? 'O' : 'X';
        } else {
            cout << "The position is already occupied. Try again." << endl;
            makeMove();
        }

    }
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }

    is_draw = true;
    return true;
}

int main() {
    cout << "Enter the name of player 1: ";
    getline(cin, player1);
    cout << "Enter the name of player 2: ";
    getline(cin, player2);

    cout << player1 << " is 'X' and goes first." << endl;
    cout << player2 << " is 'O' and goes second." << endl;

    while (!checkWin()) {
        displayBoard();
        makeMove();
        checkWin();
    }

    displayBoard();
    if (is_draw) {
        cout << "The game is a draw!" << endl;
    } else {
        cout << ((current_token == 'X') ? player2 : player1) << " wins!" << endl;
    }

    return 0;
}


