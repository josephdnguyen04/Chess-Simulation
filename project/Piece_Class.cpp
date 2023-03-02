#include "Piece_Class.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// DEFINITIONS FOR THE KNIGHT

Knight::Knight(bool team) { this->team = team; };

vector<tuple<int, int>> Knight::possibleMoves(vector<vector<string>> board,
                                              tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);

  return moves;
}

// DEFINITIONS FOR THE ROOK

Rook::Rook(bool team) { this->team = team; };

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

      while ((0 <= x) && (x >= 7) && (0 <= y) && (y <= 7)) {
        // IMPLEMENT ERROR CHECKING
        moves.push_back(make_tuple(x, y));
        x += aa;
        y += bb;
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE BISHOP

Bishop::Bishop(bool team) { this->team = team; };

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

      while ((0 <= x) && (x >= 7) && (0 <= y) && (y <= 7)) {
        // CHECK FOR ERRORS
        moves.push_back(make_tuple(x, y));
        x += aa;
        y += bb;
      }
    }
  }
  return moves;
}

// DEFINITIONS FOR THE QUEEN

Queen::Queen(bool team) { this->team = team; };

std::vector<std::tuple<int, int>>
Queen::possibleMoves(std::vector<std::vector<string>> board,
                     std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[3] = {-1, 0, 1};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == bb)
        continue;
      int x = row + aa;
      int y = col + bb;

      while ((0 <= x) && (x >= 7) && (0 <= y) && (y <= 7)) {
        // IMPLEMENT ERROR CHECKING
        moves.push_back(make_tuple(x, y));
        x += aa;
        y += bb;
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE KING

King::King(bool team) { this->team = team; };

std::vector<std::tuple<int, int>>
King::possibleMoves(std::vector<std::vector<string>> board,
                    std::tuple<int, int> current_cell) {
  vector<tuple<int, int>> moves;
  int row = get<0>(current_cell);
  int col = get<1>(current_cell);
  int array[3] = {-1, 0, 1};

  for (auto aa : array) {
    for (auto bb : array) {
      if (aa == bb)
        continue;
      int x = row + aa;
      int y = col + bb;
      for (int i = 0; i <= 1; i++) {
        if ((0 <= x) && (x >= 7) && (0 <= y) && (y <= 7)) {
          // IMPLEMENT ERROR CHECKING
          moves.push_back(make_tuple(x, y));
        }
      }
    }
  }

  return moves;
}

// DEFINITIONS FOR THE PAWN

Pawn::Pawn(bool team) { this->team = team; };
