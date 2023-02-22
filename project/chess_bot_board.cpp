#include "chess_bot_header.h"
using namespace std;

vector<vector<string>> makeBoard() {
    vector<vector<string>> board;
    //initialize with blank spaces
    for (int i = 0; i < 8; i++) {
        vector<string> row;
        for (int j = 0; j < 8; j++) {
            row.push_back("_");
        }
        board.push_back(row);
    }

//replace some blank spaces with piece descriptions for the initial setup
//board.at().at() = "w";


    return board;
}