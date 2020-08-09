#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    
    greetAndInstruct();

    //creating the boards and filling them with ' '
    char board[27];
    fill_n(board, 27, ' ');

    //displaying the new game board
    cout << endl;
    cout << " 1 | 2 | 3      10 | 11 | 12      19 | 20 | 21\n";
    cout << "-----------    --------------    --------------\n";
    cout << " 4 | 5 | 6      13 | 14 | 15      22 | 23 | 24\n";
    cout << "-----------    --------------    --------------\n";
    cout << " 7 | 8 | 9      16 | 17 | 18      25 | 26 | 27\n";
    cout << endl;
    
    //while there's no winner the game continues
    bool win = false;
    while (win == false) {

        //Player's turn
        //Asking for input
        cout << "It is your turn. Please input a cell number.\n";
        int cell;
        cin >> cell;
        
        //if the input is not an integer or if it is not a valid move ask the player for a different input
        while ((cin.fail()) || (checkIfLegal(cell, board) == false)) {
            if (cin.fail()) {
                cout << "Please input a valid integer.\n";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> cell;
            }
            else {
                cin >> cell;
            }
        }

        //updating  and displaying the board with the player's move
        board[cell - 1] = 'X';
        displayBoard(board);
        cout << endl;

        //checking if the player's last move resulted in a win
        //if true - exit the program
        //if false - continue
        win = checkWinner(board);
        if (win == true) {
            cout << "Congratulations, you won !\n";
            exit(0);
        }

        //computer's turn
        computerMove(board);
        displayBoard(board);

        //checking if the computer won the game
        win = checkWinner(board);
        if (win == true) {
            cout << "Unfortunately you lost...Better luck next time !\n";
            exit(0);
        }
    }
}
