#include "chess_bot_header.h"

// functions for colors
string grey() { return "\033[1;30m"; }
string red() { return "\033[1;31m"; }
string green() { return "\033[1;32m"; }
string yellow() { return "\033[1;33m"; }
string blue() { return "\033[1;34m"; }
string purple() { return "\033[1;35m"; }
string lightBlue() { return "\033[1;36m"; }
string white() { return "\033[1;37m"; }
string resetColor() { return "\033[0m"; }

void printBoard(const vector<vector<string>> &board) {
    string boardColor = grey();
  cout << boardColor;
  int num = 8;
  for (unsigned int i = 0; i < board.size(); i++, num--) {
    cout << num << " |";
    for (unsigned int j = 0; j < board.at(num - 1).size(); j++) {
        string color;
        if (board.at(num - 1).at(j).at(0) == 'w') {
            color = white();
        } else if (board.at(num - 1).at(j).at(0) == 'b') {
            color = red();
        } else {
            color = boardColor;
        }
      cout << color << board.at(num - 1).at(j) << grey() << "|";
    }
    cout << endl;
    cout << "   -- -- -- -- -- -- -- --" << endl;
  }
  cout << "   a  b  c  d  e  f  g  h" << endl;
  cout << resetColor();
}