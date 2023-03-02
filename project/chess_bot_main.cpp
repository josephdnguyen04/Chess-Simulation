#include "chess_bot_header.h"
// Potentially Helpful Link For the Project
// https://iopscience.iop.org/article/10.1088/1742-6596/1195/1/012013/pdf

int main() {
  vector<vector<string>> board = makeBoard();
  int numPlayers = 2;
  char playerColor = 'n';
  int turn = 0;
  int victory = 0;
  string p1 = "Player 1";
  string p2 = "Player 2";

  cout << "Welcome to Chess." << endl;
  cout << "How many players are there? ";
  cin >> numPlayers;
  while (!(numPlayers == 0 || numPlayers == 1 || numPlayers == 2) ||
         !cin.good()) {
    cout << "Sorry, that is an invalid number of players." << endl;
    cout << "Please enter an integer from 0 to 2." << endl;
    cout << "How many players are there? ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> numPlayers;
  }
  if (numPlayers == 1) {
    do {
      cin.clear();
      cin.ignore(10000, '\n');
      string temp;
      cout << "Do you want to be white or black? ";
      cin >> temp;
      playerColor = static_cast<char>(tolower(temp.at(0)));

    } while ((playerColor != 'w' && playerColor != 'b') || !cin.good());
    if (playerColor == 'w') {
      p2 = "Computer";
    } else if (playerColor == 'b') {
      p1 = "Computer";
    }
  }
  cin.ignore(1000, '\n');
  while (!victory && turn <= 10) { // debug, no turn limit
    turn++;
    cout << endl << endl << "Turn: " << turn << endl << endl;
    printBoard(board);
    cout << "White to move: ";
    if (p1 == "Computer") {
      comTurn(board, "white");
    } else {
      takeTurn(board, "white");
    }
    victory = checkEndGame(board);
    if (victory) {
      break;
    }
    cout << endl;
    printBoard(board);
    cout << "Black to move: ";
    if (p2 == "Computer") {
      comTurn(board, "black");
    } else {
      takeTurn(board, "black");
    }
    victory = checkEndGame(board);
    cout << "____________________________________" << endl;
  }

  cout << endl << "Game over" << endl;
  printBoard(board);
  cout << endl;
  victory = checkEndGame(board);
  switch (victory) {
  case 0:
    cout << "The game stopped before it finished." << endl;
    break;
  case 1:
    cout << p1 << " won!" << endl;
    break;
  case 2:
    cout << p2 << " won!" << endl;
    break;
  case 3:
    cout << "The game ended in a draw" << endl;
    break;
  default:
    cout << "Error: inocorrect ending" << endl;
  }

  return 0;
}