
#include "Piece_Class.h"
#include "chess_bot_header.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

vector<tuple<int, int>> getmoves(std::vector<std::vector<string>> board,
                                 tuple<int, int> current_cell, string piece) {
  switch (piece[1]) {
  case 'P': {
    Pawn pawn(piece);
    vector<tuple<int, int>> pawn_moves;
    pawn_moves = pawn.possibleMoves(board, current_cell);
    return pawn_moves;
  } break;
  case 'K': {
    King king(piece);
    vector<tuple<int, int>> king_moves;
    king_moves = king.possibleMoves(board, current_cell);
    return king_moves;
  } break;
  case 'N':{
    Knight knight(piece);
    vector<tuple<int, int>> knight_moves;
    knight_moves = knight.possibleMoves(board, current_cell);
    return knight_moves;
  } break;
  case 'Q':{
    Queen queen(piece);
    vector<tuple<int, int>> queen_moves;
    queen_moves = queen.possibleMoves(board, current_cell);
    return queen_moves;
  } break;
  case 'R':{
    Rook rook(piece);
    vector<tuple<int, int>> rook_moves;
    rook_moves = rook.possibleMoves(board, current_cell);
    return rook_moves;
  } break;
  case 'B':{
    Bishop bishop(piece);
    vector<tuple<int, int>> bishop_moves;
    bishop_moves = bishop.possibleMoves(board, current_cell);
    return bishop_moves;
  } break;
  default:
    {
    vector<tuple<int, int>> moves;
    moves.push_back(make_tuple(0,0));
    return moves;
    }
    break;
  }
}

// int isCheck(vector<vector<string>> board) {
//   vector<tuple<int, int>> entire_moves;
//   for (int row = 0; row < 8; row++) {
//     for (int col = 0; col < 8; col++) {
//       if (board.at(row).at(col) != "  ") {
//         vector<tuple<int, int>> temporary;
//         temporary = getmoves(board, make_tuple(row, col), board.at(row).at(col));
//       }
//     }
//   }
// }