#include "chess_bot_header.h"

vector<vector<string>> makeBoard() {
  vector<vector<string>> board;
  // initialize with blank spaces
  for (int i = 0; i < 8; i++) {
    vector<string> row;
    for (int j = 0; j < 8; j++) {
      row.push_back("  ");
    }
    board.push_back(row);
  }

  // replace some blank spaces with piece descriptions for the initial setup
  board.at(0).at(0) = "wR"; // white rook
  board.at(0).at(1) = "wN"; // white knight
  board.at(0).at(2) = "wB"; // white bishop
  board.at(0).at(3) = "wQ"; // white queen
  board.at(0).at(4) = "wK"; // white king
  board.at(0).at(5) = "wB"; // white bishop
  board.at(0).at(6) = "wN"; // white knight
  board.at(0).at(7) = "wR"; // white rook

  for (unsigned int i = 0; i < board.at(0).size(); i++) {
    board.at(1).at(i) = "wP"; // white pawn
  }

  for (unsigned int i = 0; i < board.at(6).size(); i++) {
    board.at(6).at(i) = "bP"; // black pawn
  }

  board.at(7).at(0) = "bR"; // black rook
  board.at(7).at(1) = "bN"; // black knight
  board.at(7).at(2) = "bB"; // black bishop
  board.at(7).at(3) = "bQ"; // black queen
  board.at(7).at(4) = "bK"; // black king
  board.at(7).at(5) = "bB"; // black bishop
  board.at(7).at(6) = "bN"; // black knight
  board.at(7).at(7) = "bR"; // black rook

  return board;
}
