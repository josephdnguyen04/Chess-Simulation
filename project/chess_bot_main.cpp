#include "chess_bot_header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<vector<string>> board = makeBoard();
  int numPlayers = 0;
  cout << "Welcome to Chess." << endl;
  cout << "How many players are there? ";
  cin >> numPlayers;
  while (!(numPlayers == 0 || numPlayers == 1 || numPlayers == 2)) {
    cout << "Sorry, " << numPlayers << " is an invalid number of players."
         << endl;
    cout << "Please enter an integer from 0 to 2." << endl;
    cout << "How many players are there? ";
    cin >> numPlayers;
  }

  return 0;
}