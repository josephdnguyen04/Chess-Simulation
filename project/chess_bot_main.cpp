#include "chess_bot_header.h"

int main() {
  vector<vector<string>> board = makeBoard();
  int numPlayers = 2;
  int turn = 0;
  int victory = 0;
  string p1 = "Player 1";
  string p2 = "Player 2";

  cout << "Welcome to Chess." << endl;
  /* right now, we will default to 2 players unless we program computer moves
  cout << "How many players are there? ";
  cin >> numPlayers;
  while (!(numPlayers == 0 || numPlayers == 1 || numPlayers == 2)) {
    cout << "Sorry, " << numPlayers << " is an invalid number of players."
         << endl;
    cout << "Please enter an integer from 0 to 2." << endl;
    cout << "How many players are there? ";
    cin >> numPlayers;
  }
*/
  while (0/*!checkEndGame(board) && turn <= 10*/) { //debug, there should be no turn limit
    turn++;
    takeTurn(board, "white");
    takeTurn(board, "black");
    printBoard(board);
  }
 victory = checkEndGame(board);
  switch (victory) {
  case 0:
    cout << "Error: game finished too early." << endl;
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