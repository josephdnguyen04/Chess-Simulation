#include <iostream>
#include <vector>
#include <string>
#include "chess_bot_header.h"
using namespace std;

int main() {
    vector<vector<string>> board = makeBoard();
for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.at(i).size(); j++) {
        cout << board.at(i).at(j) << ", ";
    }
    cout << endl;
}
    return 0;
}