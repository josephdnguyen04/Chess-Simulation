#include "Piece_Class.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// DEFINITIONS FOR THE KNIGHT

Knight::Knight(string team) { this->team = team; };

vector<tuple<int, int>> Knight::possibleMoves(vector<vector<string>> board,
                                              tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[4] = {-2, -1, 1, 2};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == bb || aa + bb == 0)
        continue;
      int x = row + aa;
      int y = col + bb;
      if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        if (board.at(x).at(y) != "  ") {
          if (board.at(x).at(y).at(0) != team.at(0)) {
            moves.push_back(make_tuple(x, y));
            continue;
          } else {
            continue;
          }
        } else {
          moves.push_back(make_tuple(x, y));
        }
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE ROOK

Rook::Rook(string team) { this->team = team; };

vector<tuple<int, int>> Rook::possibleMoves(vector<vector<string>> board,
                                            tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[3] = {-1, 0, 1};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == bb || aa + bb == 0)
        continue;
      int x = row + aa;
      int y = col + bb;

      while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        if (board.at(x).at(y) != "  ") {
          if (board.at(x).at(y).at(0) != team.at(0)) {
            moves.push_back(make_tuple(x, y));
            break;
          } else {
            break;
          }
        } else {
          moves.push_back(make_tuple(x, y));
        }
        x += aa;
        y += bb;
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE BISHOP

Bishop::Bishop(string team) { this->team = team; };

std::vector<std::tuple<int, int>>
Bishop::possibleMoves(std::vector<std::vector<string>> board,
                      std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[2] = {-1, 1};

  for (int aa : array) {
    for (int bb : array) {
      int x = row + aa;
      int y = col + bb;

      while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        if (board.at(x).at(y) != "  ") {
          if (board.at(x).at(y).at(0) != team.at(0)) {
            moves.push_back(make_tuple(x, y));
            break;
          } else {
            break;
          }
        } else {
          moves.push_back(make_tuple(x, y));
        }
        x += aa;
        y += bb;
      }
    }
  }
  return moves;
}

// DEFINITIONS FOR THE QUEEN

Queen::Queen(string team) { this->team = team; };

std::vector<std::tuple<int, int>>
Queen::possibleMoves(std::vector<std::vector<string>> board,
                     std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[3] = {-1, 0, 1};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == 0 && bb == 0)
        continue;
      int x = row + aa;
      int y = col + bb;

      while ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        if (board.at(x).at(y) != "  ") {
          if (board.at(x).at(y).at(0) != team.at(0)) {
            moves.push_back(make_tuple(x, y));
            break;
          } else {
            break;
          }
        } else {
          moves.push_back(make_tuple(x, y));
        }
        x += aa;
        y += bb;
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE KING

King::King(string team) { this->team = team; };

std::vector<std::tuple<int, int>>
King::possibleMoves(std::vector<std::vector<string>> board,
                    std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[3] = {-1, 0, 1};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == 0 && bb == 0)
        continue;
      int x = row + aa;
      int y = col + bb;
      if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7)) {
        if (board.at(x).at(y) != "  ") {
          if (board.at(x).at(y).at(0) != team.at(0)) {
            moves.push_back(make_tuple(x, y));
            continue;
          } else {
            continue;
          }
        } else {
          moves.push_back(make_tuple(x, y));
        }
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE PAWN

Pawn::Pawn(string team) { this->team = team; };

std::vector<std::tuple<int, int>>
Pawn::possibleMoves(std::vector<std::vector<string>> board,
                    std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;

  return moves;
}
