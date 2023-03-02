#include "chess_bot_header.h"

void printBoard(const vector<vector<string>> &board) {
  int num = 8;
    for (unsigned int i  = 0; i < board.size(); i++, num--) {
        cout << num << " |";
        for (unsigned int j = 0; j < board.at(num - 1).size(); j++) {
            cout << board.at(num - 1).at(j) << "|";
        }
        cout << endl;
        cout << "   -- -- -- -- -- -- -- --" << endl;
        
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
}