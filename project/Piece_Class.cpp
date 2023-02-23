
#include <iostream>
#include <tuple>
#include <vector>
using std::string;

class ChessPieces {
private:
  bool team;

public:
  ChessPieces(bool color) { team = color; };

  std::vector<std::tuple<int, int>>
  move(std::tuple<int> current_cell,
       std::vector<std::vector<string>> current_board) {
    std::vector<std::tuple<int, int>> moves;
    moves.push_back(std::make_tuple(0, 0));
    moves.push_back(std::make_tuple(0, 7));
    moves.push_back(std::make_tuple(7, 0));
    moves.push_back(std::make_tuple(7, 7));
    moves.push_back(std::make_tuple(4, 0));
    moves.push_back(std::make_tuple(4, 7));
    moves.push_back(std::make_tuple(3, 0));
    moves.push_back(std::make_tuple(3, 7));
    return moves;
  }
};

class Pawn : public ChessPieces {
private:
  string name = "pawn";

public:
  Pawn(bool team);
};
// Pawn::Pawn(bool team) {
//     super(team);
// }

class Knight : public ChessPieces {
private:
  string name = "knight";

public:
};

class Bishop : public ChessPieces {
private:
  string name = "bishop";

public:
};

class Queen : public ChessPieces {
private:
  string name = "queen";

public:
};

class King : public ChessPieces {
private:
  string name = "king";

public:
};

class Rook : public ChessPieces {
private:
  string name = "rook";

public:
};