#include <iostream>
#include <tuple>

using namespace std;

void greetAndInstruct() {
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n";
    cout << "The board is numbered from 1 to 27 as per the following:\n";
    cout << endl;
    cout << " 1 | 2 | 3      10 | 11 | 12      19 | 20 | 21\n";
    cout << "-----------    --------------    --------------\n";
    cout << " 4 | 5 | 6      13 | 14 | 15      22 | 23 | 24\n";
    cout << "-----------    --------------    --------------\n";
    cout << " 7 | 8 | 9      16 | 17 | 18      25 | 26 | 27\n";
    cout << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n";
    cout << "Start? (y/n)\n";

    //asking the Player for an input
    //if they input 'n' the program exits
    char c;
    cin >> c;
    if (c == 'n') {
        exit(0);
    }
}

//display the board's current state
void displayBoard(char board[]){
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "    " << board[9] << " | " << board[10] << " | " << board[11] << "    " << board[18] << " | " << board[19] << " | " << board[20] << endl;
    cout << "-----------  -----------  -----------\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "    " << board[12] << " | " << board[13] << " | " << board[14] << "    " << board[21] << " | " << board[22] << " | " << board[23] << endl;
    cout << "-----------  -----------  -----------\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "    " << board[15] << " | " << board[16] << " | " << board[17] << "    " << board[24] << " | " << board[25] << " | " << board[26] << endl;
}

//check if a move by the player is legal
bool checkIfLegal(int cellNbre, char board[]) {
    if ((board[cellNbre - 1] != ' ') || (cellNbre > 27) || (cellNbre < 1)) {
        cout << "This is an illegal move. Please input a different cell number.\n";
        return false;
    }
    else return true;
}

//Checks all the horizontals in the boards for a winner, i.e cells 1 2 3
bool checkHorizontal(char board[]) {

    int cells[] = { 0,3,6,9,12,15,18,21,24 };
    for (int i : cells) {
        if ((board[i] == board[i + 1]) && (board[i] == board[i + 2])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }

        }
    }

    return false;
}

//Checks all the verticals in the boards for a winner, i.e cells 1 4 7
bool checkVertical(char board[]) {

    //Verticals accross only 1 board

    int cells1[] = { 0,1,2,9,10,11,18,19,20 };
    for (int i : cells1) {
        if ((board[i] == board[i + 3]) && (board[i] == board[i + 6])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Verticals accross all 3 boards

    int cells3[] = {0,1,2,3,4,5,6,7,8};
    for (int i : cells3) {
        if ((board[i] == board[i + 9]) && (board[i] == board[i + 18])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    return false;
}

//Checks all the diagonals in the boards for a winner
bool checkDiagonal(char board[]) {

    //Diagonals accross only 1 board

    //Diagonals from left to right, i.e cells 1 5 9
    int cellsLR1[] = {0, 9, 18};
    for (int i : cellsLR1) {
        if ((board[i] == board[i + 4]) && (board[i] == board[i + 8])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Diagonals from right to left, i.e cells 3 5 7
    int cellsRL1[] = {2, 11, 20};
    for (int i : cellsRL1) {
        if ((board[i] == board[i + 2]) && (board[i] == board[i + 4])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Diagonals accross all 3 boards

    //Real diagonals, i.e cells 1 14 27 or cells 3 14 25
    if ((board[0] == board[13]) && (board[0] == board[26])) {
        char x = board[0];
        if ((x == 'X') || (x == 'O')) {
            return true;
        }
    }
    if ((board[2] == board[13]) && (board[2] == board[24])) {
        char x = board[2];
        if ((x == 'X') || (x == 'O')) {
            return true;
        }
    }
    if ((board[6] == board[13]) && (board[6] == board[20])) {
        char x = board[6];
        if ((x == 'X') || (x == 'O')) {
            return true;
        }
    }
    if ((board[8] == board[13]) && (board[8] == board[18])) {
        char x = board[8];
        if ((x == 'X') || (x == 'O')) {
            return true;
        }
    }

    //Diagonals accross 1 plane

    //Diagonals from left to right, i.e cells 1 11 21
    int cellsLR3[] = {0,3,6};
    for (int i : cellsLR3) {
        if ((board[i] == board[i + 10]) && (board[i] == board[i + 20])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Diagonals from right to left, i.e cells 3 11 19
    int cellsRL3[] = {2, 5, 8};
    for (int i : cellsRL3) {
        if ((board[i] == board[i + 8]) && (board[i] == board[i + 16])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Diagonals up - down, i.e cells 1 13 25
    int cellsUP[] = { 0, 1, 2 };
    for (int i : cellsUP) {
        if ((board[i] == board[i + 12]) && (board[i] == board[i + 24])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    //Diagonals down - up, i.e cells 7 13 19
    int cellsDU[] = { 6, 7, 8 };
    for (int i : cellsDU) {
        if ((board[i] == board[i + 6]) && (board[i] == board[i + 12])) {
            char x = board[i];
            if ((x == 'X') || (x == 'O')) {
                return true;
            }
        }
    }

    return false;
}

//check if it's a tie - all cells are filled with an 'X' or an 'O'
bool checkTie(char board[]) {
    int cells[27];
    for (int i = 0; i < 27; i++) {
        cells[i] = i;
    }
    //if a cell still contains a space return false, there is no tie
    for (int i : cells) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

//check if there is a winning sequence
//if checkVertical, checkHorizontal or checkDiagonal return true  - there is a winner
bool checkWinner(char board[]) {
    bool diag = checkDiagonal(board);
    bool ver = checkVertical(board);
    bool hor = checkHorizontal(board);

    if ((diag == true) || (ver == true) || (hor == true)) {
        return true;
    }
    
    //Checking for a tie
    bool tie = checkTie(board);
    if (tie == true) {
        cout << "It's a tie !\n";
        exit(0);
    }

    return false;
}

//Check if the computer can win with it's next move
tuple<bool, int> checkStatusComp(char board[]) {

    int cells[27];
    for (int i = 0; i < 27; i++) {
        cells[i] = i;
    }

    //copy of the board for testing
    char board_copy[27];

    //for every empty cell (i.e board[i] = ' ') check if filling it with 'O' wins the game
    //if true - return true and the index of the cell
    //else - return false and a random integer
    for (int index : cells) {
        if (board[index] == ' ') {
            for (int x = 0; x < 27; x++) {
                board_copy[x] = board[x];
            }
            board_copy[index] = 'O';
            bool win = checkWinner(board_copy);
            if (win == true) {
                return make_tuple(true, index);
            }
        }
    }

    return make_tuple(false, 28);
}

//Check if the player can win with their next move
tuple<bool, int> checkStatusPlayer(char board[]) {

    int cells[27];
    for (int i = 0; i < 27; i++) {
        cells[i] = i;
    }

    //copy of the board for testing
    char board_copy[27];

    //for every empty cell (i.e board[i] == ' ') check if filling it with 'X' wins the game
    //if true - return true and the index of the cell
    //else - return false and a random integer
    for (int index : cells) {
        if (board[index] == ' ') {
            for (int x = 0; x < 27; x++) {
                board_copy[x] = board[x];
            }
            board_copy[index] = 'X';
            bool win = checkWinner(board_copy);
            if (win == true) {
                return make_tuple(true, index);
            }
        }
    }

    return make_tuple(false, 28);
}


void computerMove(char board[]) {
    auto winP = checkStatusPlayer(board);
    auto winC = checkStatusComp(board);

    //if checkStatusComp returns true there is a winning move
    //therefore fill the cell (whose index was returned by checkStatusComp) with 'O'
    if (get<0>(winC) == true) {
        board[get<1>(winC)] = 'O';
        return;
    }

    //if checkStatusPlayer returns true the computer must prevent the player's winning move
    //therefore fill the cell (whose index was returned by checkStatusPlayer) with 'O'
    if (get<0>(winP) == true) {
        board[get<1>(winP)] = 'O';
        return;
    }

    //if no winning moves are found, find the first empty cell (i.e board[i] == ' ')
    else {
        int cells[27];
        for (int i = 0; i < 27; i++) {
            cells[i] = i;
        }
        for (int index : cells) {
            if (board[index] == ' ') {
                board[index] = 'O';
                return;
            }
        }
    }

}