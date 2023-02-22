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
board.at(0).at(0) = "wRook";
board.at(0).at(1) = "wKnight";
board.at(0).at(2) = "wBishop";
board.at(0).at(3) = "wQueen";
board.at(0).at(4) = "wKing";
board.at(0).at(5) = "wBishop";
board.at(0).at(6) = "wKnight";
board.at(0).at(7) = "wRook";

for (unsigned int i = 0; i < board.at(0).size(); i++) {
    board.at(1).at(i) = "wPawn";
}

for (unsigned int i = 0; i < board.at(6).size(); i++) {
    board.at(6).at(i) = "bPawn";
}

board.at(7).at(0) = "bRook";
board.at(7).at(1) = "bKnight";
board.at(7).at(2) = "bBishop";
board.at(7).at(3) = "bQueen";
board.at(7).at(4) = "bKing";
board.at(7).at(5) = "bBishop";
board.at(7).at(6) = "bKnight";
board.at(7).at(7) = "bRook";


    return board;
}
