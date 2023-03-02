#include "chess_bot_header.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

tuple<int, int> convertInput(string input) {
  tuple<int, int> position;
  int row = (int)input[0] - 65;
  int col = (int)input[1];
  position = make_tuple(row, col);
  return position;
}

void takeTurn(vector<vector<string>> &board, string color) {
  // takes two inputs of a letter and a number being separated by a space.
  // ex: "E5 F7"
  string one, two;
  cout << "Please make a move.\n";
  cin >> one >> two;
  tuple<int, int> initial, finale;
  initial = convertInput(one);
  finale = convertInput(two);

  // moves the piece from the inital position to the final, while setting the
  // initial position to empty ("  ")
  string piece = board.at(get<0>(initial)).at(get<1>(initial));
  board.at(get<0>(initial)).at(get<1>(initial)) = "  ";
  board.at(get<0>(finale)).at(get<1>(finale)) = piece;
}
