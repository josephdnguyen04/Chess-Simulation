#include "chess_bot_header.h"

void printBoard(const vector<vector<string>> &board) {
    for (int i  = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            cout << board.at(i).at(j) << " ";
        }
        cout << endl;
    }
}