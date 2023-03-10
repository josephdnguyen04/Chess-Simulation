#include "chess_bot_header.h"
// Potentially Helpful Link For the Project
// https://iopscience.iop.org/article/10.1088/1742-6596/1195/1/012013/pdf

int main() {
  cout << resetColor();
  vector<vector<string>> board = makeBoard();
  int numPlayers;
  char playerColor = 'n'; // 'w' for white and 'b' for black
  int turn = 0;
  int victory = 0; // 0 - running game; 1 - p1 won; 2 - p2 won; 3 - tie
  string p1 = "Player 1";
  string p2 = "Player 2";
  bool visibleBoard = 1; // 0 for invisible board; 1 for visible board
  bool stepByStep = 0;
  srand(1);

  cout << "Welcome to Chess." << endl;

  // get number of players
  cout << "How many players are there? ";
  string junk;
  getline(cin, junk);
  numPlayers = static_cast<int>(junk.at(0)) - 48;
  cout << "number of players: " << numPlayers << endl;
  while (!(numPlayers == 0 || numPlayers == 1 || numPlayers == 2) ||
         !cin.good()) {
    cout << "Sorry, that is an invalid number of players." << endl;
    cout << "Please enter an integer from 0 to 2." << endl;
    cout << "How many players are there? ";
    cin >> numPlayers;
  }
  if (numPlayers == 0) { // 0 players; 2 computers
    p1 = "Computer 1";
    p2 = "Computer 2";
    string response;
    do {
      cout << "Would you like to see individual computer turns (y/n)?" << endl;
      getline(cin, response);
      for (unsigned int i = 0; i < response.size(); i++) {
        response.at(i) = tolower(response.at(i));
      }
    } while (!response.size());
    stepByStep = (response.at(0) == 'y');
  }
  if (numPlayers == 1) { // 1 player; option of white or black
    do {
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

  // main turn loop
  cin.clear();
  cin.ignore(1000, '\n');
  while (!victory && turn <= 10000) { // turn limit to prevent infinite loops
    turn++;
    cout << endl << "Turn: " << turn << endl; // print turn #
    if (visibleBoard) {                       // print initial board
      cout << endl;
      printBoard(board);
    }
    if (stepByStep) {
      string junk;
      getline(cin, junk);
    }
    printcheck(board);
    cout << white() << "White to move: " << resetColor(); // p1's turn
    if (p1 == "Computer 1" || p1 == "Computer") {
      comTurn(board, "white");
    } else {
      takeTurn(board, "white");
    }
    victory = checkEndGame(board);
    if (victory) {
      break;
    }
    if (visibleBoard) { // print board between turns
      cout << endl;
      printBoard(board);
    };
    if (stepByStep) {
      string junk;
      getline(cin, junk);
    }
    printcheck(board);
    cout << red() << "Black to move: " << resetColor(); // p2's turn
    if (p2 == "Computer 2" || p2 == "Computer") {
      comTurn(board, "black");
    } else {
      takeTurn(board, "black");
    }
    victory = checkEndGame(board);
    cout << "____________________________________" << endl;
  }

  // end game stats
  cout << endl << "Game over" << endl;
  if (visibleBoard) { // final board
    printBoard(board);
    cout << endl;
  }
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
  cout << resetColor();
  return 0;
}