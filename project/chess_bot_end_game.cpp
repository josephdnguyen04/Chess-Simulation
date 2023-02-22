#include "chess_bot_header.h"

int checkEndGame(const vector<vector<string>> &board) {
  bool p1K = 0;
  bool p2K = 0;
  int victory = 0;
  for (int i = 0; i < board.size(); i++) { // find if each player has a king
    for (int j = 0; j < board.at(i).size(); j++) {
      if (board.at(i).at(j) == "wK") {
        p1K = 1;
      }
      if (board.at(i).at(j) == "bK") {
        p2K = 1;
      }
    }
  }
  // I haven't gotten to checkmate yet, it is only dependent on whether they
  // have a king
  if (p1K && !p2K) { // p1 has a king and p2 does not
    victory = 1;
  }
  if (!p1K && p2K) { // p1 does not have a king and p2 does
    victory = 2;
  }
  if (!p1K && !p2K) { // neither has a king
    victory = 3;
  }
  return victory;
}