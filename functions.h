#include <tuple>

void greetAndInstruct();
void displayBoard(char board[]);
bool checkIfLegal(int cellNbre, char board[]);
bool checkHorizontal(char board[]);
bool checkVertical(char board[]);
bool checkDiagonal(char board[]);
bool checkWinner(char board[]);
std::tuple<bool, int> checkStatusComp(char board[]);
std::tuple<bool, int> checkStatusPlayer(char board[]);
void computerMove(char board[]);
bool checkTie(char board[]);

