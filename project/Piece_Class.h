/*********************************************************************************
 * This file has all the classes for the chess pieces.
 *
 * there is a description of each attribute and methods.
 *
 */

#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using std::string;

class Pawn {
private:
  // NAME used for debugging and error checking
  string name = "pawn";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  Pawn(bool team);
};

class Knight {
private:
  // NAME used for debugging and error checking
  string name = "knight";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  Knight(bool team);
  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Bishop {
private:
  // NAME used for debugging and error checking
  string name = "bishop";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  Bishop(bool team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Queen {
private:
  // NAME used for debugging and error checking
  string name = "queen";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  Queen(bool team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class King {
private:
  // NAME used for debugging and error checking
  string name = "king";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  King(bool team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Rook {
private:
  // NAME used for debugging and error checking
  string name = "rook";

  // TRUE = WHITE and FALSE = BLACK
  bool team;

public:
  Rook(bool team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};