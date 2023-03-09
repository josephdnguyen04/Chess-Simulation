#include "Piece_Class.h"
#include "chess_bot_header.h"
#include <limits.h>
#include <tuple>
using namespace std;

bool validMove(const vector<vector<string>> &board, int iOld, int jOld,
               int iNew, int jNew, string color) {
  bool valid = 1;
  // white cannot move anything but white pieces
  if (color == "white" && board.at(iOld).at(jOld).at(0) != 'w') {
    valid = 0;
    return valid;
  }
  // black cannot move anything but black pieces
  if (color == "black" && board.at(iOld).at(jOld).at(0) != 'b') {
    valid = 0;
    return valid;
  }
  // nobody can move a piece from an empty space
  if (board.at(iOld).at(jOld) == "  ") {
    valid = 0;
    return valid;
  }
  // players cannot capture their own color (exception for color == "neutral")
  if (color != "neutral" &&
      board.at(iOld).at(jOld).at(0) == board.at(iNew).at(jNew).at(0)) {
    valid = 0;
    return valid;
  }

  // other conditions. Just return 0 if it is an invalid move (or a 1 otherwise)
  // check pieces
  switch (board.at(iOld).at(jOld).at(1)) {
  case 'K': {
    bool recognized = 0;
    cout << "called king" << endl; // debug
    King piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    cout << list.size() << endl; // debug
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        cout << "good move for a king" << endl; // debug
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      cout << "bad move for a king" << endl; // debug
      return valid;
    }
  } break;
  case 'Q': {
    bool recognized = 0;
    cout << "called queen" << endl;
    Queen piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    cout << list.size() << endl; // debug
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        cout << "good move for a queen" << endl; // debug
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      cout << "bad move for a queen" << endl; // debug
      return valid;
    }
  } break;
  case 'R': {
    bool recognized = 0;
    cout << "called rook" << endl;
    Rook piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    cout << list.size() << endl; // debug
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        cout << "good move for a rook" << endl; // debug
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      cout << "bad move for a rook" << endl; // debug
      return valid;
    }
  } break;
  case 'N': {
    bool recognized = 0;
    cout << "called knight" << endl;
    Knight piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    cout << list.size() << endl; // debug
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        cout << "good move for a knight" << endl; // debug
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      cout << "bad move for a knight" << endl; // debug
      return valid;
    }
  } break;
  case 'B': {
    bool recognized = 0;
    cout << "called bishop" << endl; // debug
    Bishop piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    cout << list.size() << endl; // debug
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        cout << "good move for a bishop" << endl; // debug
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      cout << "bad move for a bishop" << endl; // debug
      return valid;
    }
  } break;
    // case 'P': {
    //     bool recognized = 0;
    //     cout << "called pawn" << endl; // debug
    //     Pawn piece(color);
    //     vector<tuple<int, int>> list = piece.possibleMoves(board, tuple<int,
    //     int>(iOld, jOld)); for (unsigned int i = 0; i < list.size(); i++) {
    //         if (list.at(i) == tuple<int, int>(iNew, jNew)) {
    //             cout << "good move for a king" << endl; // debug
    //             recognized += 1;
    //         } else {
    //             cout << "bad move for a king" << endl; // debug
    //         }
    //     }
    //     valid = recognized;
    //     if (valid == 0) {
    //         return valid;
    //     }
    // }break;

  default: {
    valid = 1;
  }
  }
  //   if (board.at(iOld).at(jOld).at(1) == 'K') {
  //     cout << "called king" << endl; // debug
  //     King piece("white");
  //     vector<tuple<int, int>> list =
  //         piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
  //     cout << list.size() << endl; //debug
  //     bool recognized = 0;
  //     for (unsigned int i = 0; i < list.size(); i++) {
  //       if (list.at(i) == tuple<int, int>(iNew, jNew)) {
  //         cout << "good move for a king" << endl; // debug
  //         recognized += 1;
  //       } else {
  //         cout << "bad move for a king" << endl; // debug
  //       }
  //     }
  //     valid = recognized;
  //     if (valid == 0) {
  //       return 0;
  //     }
  //   }

  return valid;
}

void moveRequest(int &iOld, int &jOld, int &iNew, int &jNew) {
  string request;
  bool valid = true;
  do {
    if (!valid) {
      valid = true;
      cout << endl;
      cout << "***Sorry, that was an invalid request. Please try again.***"
           << endl;
      cout << "Enter the coordinates of your starting square followed by the "
              "coordinates of your target square (letter, number, letter, "
              "number)"
           << endl;
    }
    cout << "What move would you like to make?" << endl;
    getline(cin, request);
    unsigned int stringIndex = 0;
    while (stringIndex < request.size()) {
      if ((!isalpha(request.at(stringIndex)) &&
           !isdigit(request.at(stringIndex))) ||
          tolower(request.at(stringIndex)) == 'x') {
        request.erase(request.begin() + stringIndex);
      } else {
        stringIndex++;
      }
    }
    // check if valid
    // make sure there are at least four characters in request
    if (request.size() < 4) {
      valid = false;
      continue;
    }
    // make sure that request is alpha-digit-alpha-digit
    if (isalpha(request.at(0)) && isdigit(request.at(1)) &&
        isalpha(request.at(2)) && isdigit(request.at(3))) {
      request.at(0) = tolower(request.at(0)); // ignore capitol letters
      request.at(2) = tolower(request.at(2));
    } else {
      valid = false;
      continue;
    }
    // make sure each character of request is in range of an 8x8 board
    if ((request.at(0) < 'a') || (request.at(0) > 'h') ||
        (request.at(2) < 'a') || (request.at(2) > 'h') ||
        (request.at(1) < '1') || (request.at(1) > '8') ||
        (request.at(3) < '1') || (request.at(3) > '8')) {
      valid = false;
      continue;
    }
  } while (!valid);
  jOld = static_cast<int>(request.at(0)) - 97;
  iOld = static_cast<int>(request.at(1)) - 49;
  jNew = static_cast<int>(request.at(2)) - 97;
  iNew = static_cast<int>(request.at(3)) - 49;
}

tuple<int, int> convertInput(string input) {
  tuple<int, int> position;
  int row = (int)input[0] - 65;
  int col = (int)input[1];
  position = make_tuple(row, col);
  return position;
}

void takeTurn(vector<vector<string>> &board, string color) {
  // takes two inputs of a letter and a number being.
  // ex: "E5 F7"
  int iOld;
  int jOld;
  int iNew;
  int jNew;
  bool legalMove = 1;
  do {
    moveRequest(iOld, jOld, iNew, jNew);
    // moves the piece from the inital position to the final, while setting the
    // initial position to empty ("  ")
    tuple<int, int> initial, finale;
    initial = make_tuple(iOld, jOld);
    finale = make_tuple(iNew, jNew);
    legalMove = validMove(board, iOld, jOld, iNew, jNew, color);
    if (legalMove) {
      // moves the piece from the inital position to the final, while
      // setting the initial position to empty ("  ")
      string piece = board.at(get<0>(initial)).at(get<1>(initial));
      board.at(get<0>(initial)).at(get<1>(initial)) = "  ";
      board.at(get<0>(finale)).at(get<1>(finale)) = piece;
    } else {
      cout << "That was not a legal move." << endl;
    }
  } while (!legalMove);
}

void comTurn(vector<vector<string>> &board, string color) {
  int iOld;
  int jOld;
  int iNew;
  int jNew;
  do {
    iOld = rand() % 8;
    jOld = rand() % 8;
    iNew = rand() % 8;
    jNew = rand() % 8;
  } while (!validMove(board, iOld, jOld, iNew, jNew, color));

  tuple<int, int> initial, finale;
  initial = make_tuple(iOld, jOld);
  finale = make_tuple(iNew, jNew);
  if (validMove(board, iOld, jOld, iNew, jNew, color)) {
    string piece = board.at(get<0>(initial)).at(get<1>(initial));
    board.at(get<0>(initial)).at(get<1>(initial)) = "  ";
    board.at(get<0>(finale)).at(get<1>(finale)) = piece;
    cout << "Computer played: " << static_cast<char>(jOld + 97)
         << static_cast<char>(iOld + 49) << static_cast<char>(jNew + 97)
         << static_cast<char>(iNew + 49) << endl;
  } else {
    cout << "That was not a legal move by the computer." << endl;
  }
}