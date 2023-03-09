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
  string team;

public:
  Pawn(string team);
  
  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Knight {
private:
  // NAME used for debugging and error checking
  string name = "knight";

  // TRUE = WHITE and FALSE = BLACK
  string team;

public:
  Knight(string team);
  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Bishop {
private:
  // NAME used for debugging and error checking
  string name = "bishop";

  // TRUE = WHITE and FALSE = BLACK
  string team;

public:
  Bishop(string team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Queen {
private:
  // NAME used for debugging and error checking
  string name = "queen";

  // TRUE = WHITE and FALSE = BLACK
  string team;

public:
  Queen(string team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class King {
private:
  // NAME used for debugging and error checking
  string name = "king";

  // TRUE = WHITE and FALSE = BLACK
  string team;

public:
  King(string team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};

class Rook {
private:
  // NAME used for debugging and error checking
  string name = "rook";

  // TRUE = WHITE and FALSE = BLACK
  string team;

public:
  Rook(string team);

  std::vector<std::tuple<int, int>>
  possibleMoves(std::vector<std::vector<string>> board,
                std::tuple<int, int> current_cell);
};