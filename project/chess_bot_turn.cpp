#include "Piece_Class.h"
#include "chess_bot_header.h"
#include <limits.h>
#include <tuple>
using namespace std;

bool validMove(const vector<vector<string>> &board, int iOld, int jOld,
               int iNew, int jNew, string color, bool debug) {
  bool valid = 1;
  // nobody can move a piece from an empty space
  if (board.at(iOld).at(jOld) == "  ") {
    if (debug) { // debug
      cout << "There is no piece there" << endl;
    }
    valid = 0;
    return valid;
  }
  // players cannot put the piece back where it just was
  if (color != "neutral" && iOld == iNew && jOld == jNew) {
    if (debug) { // debug
      cout << "You cannot place a piece back where it just was" << endl;
    }
    valid = 0;
    return valid;
  }
  // white cannot move anything but white pieces
  if (color == "white" && board.at(iOld).at(jOld).at(0) != 'w') {
    if (debug) { // debug
      cout << "That piece is not your color" << endl;
    }
    valid = 0;
    return valid;
  }
  // black cannot move anything but black pieces
  if (color == "black" && board.at(iOld).at(jOld).at(0) != 'b') {
    if (debug) { // debug
      cout << "That piece is not your color" << endl;
    }
    valid = 0;
    return valid;
  }
  // players cannot capture their own color (exception for color == "neutral")
  if (color != "neutral" &&
      board.at(iOld).at(jOld).at(0) == board.at(iNew).at(jNew).at(0)) {
    if (debug) { // debug
      cout << "You cannot capture a piece on your team" << endl;
    }
    valid = 0;
    return valid;
  }

  // other conditions. Just return 0 if it is an invalid move (or a 1 otherwise)
  // check pieces
  switch (board.at(iOld).at(jOld).at(1)) {
  case 'K': {
    bool recognized = 0;
    King piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));
    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a king" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a king" << endl;
      }
      return valid;
    }
  } break;
  case 'Q': {
    bool recognized = 0;
    if (debug) { // debug
      cout << "called queen" << endl;
    }
    Queen piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));

    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a queen" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a queen" << endl;
      }
      return valid;
    }
  } break;
  case 'R': {
    bool recognized = 0;
    if (debug) { // debug
      cout << "called rook" << endl;
    }
    Rook piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));

    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a rook" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a rook" << endl;
      }
      return valid;
    }
  } break;
  case 'N': {
    bool recognized = 0;
    Knight piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));

    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a knight" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a knight" << endl;
      }
      return valid;
    }
  } break;
  case 'B': {
    bool recognized = 0;
    Bishop piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));

    for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a bishop" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a bishop" << endl;
      }
      return valid;
    }
  } break;
  case 'P': {
    bool recognized = 0;
    Pawn piece(color);
    vector<tuple<int, int>> list =
        piece.possibleMoves(board, tuple<int, int>(iOld, jOld));

    for (unsigned int i = 0; i < list.size(); i++) {
      if (debug) { // debug
        cout << "row = " << get<0>(list.at(i))
             << ", col = " << get<1>(list.at(i)) << endl;
      }
      if (list.at(i) == tuple<int, int>(iNew, jNew)) {
        if (debug) { // debug
          cout << color << " moved a pawn" << endl;
        }
        recognized += 1;
      }
    }
    valid = recognized;
    if (valid == 0) {
      if (debug) { // debug
        cout << "bad move for a pawn" << endl;
      }
      return valid;
    }
  } break;

  default: {
    if (debug) { // debug
      cout << "That should be a legal move" << endl;
    }
    valid = 1;
  }
  }
  if (debug && !valid) { // debug
    cout << "That was not a legal move, please try again" << endl;
  }
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
        request.at(stringIndex) =
            tolower(request.at(stringIndex)); // if a letter, make it lowercase
        stringIndex++;
      }
    }
    // check if valid
    // make sure there are at least four characters in request
    switch (request.size()) {
    case 0: {
      cout << "Sorry, I don't recognize that entry" << endl;
      valid = false;
      continue;
    }
    case 1: {
      cout << "Sorry, I don't recognize that entry" << endl;
      valid = false;
      continue;
    }
    case 2: {
      if (!(isalpha(request.at(0)) && isdigit(request.at(1)))) {
        valid = false;
        continue;
      }
      string start = request;
      cout << "To which square would you like to move?" << endl;
      getline(cin, request);
      if (request.size() != 2) {
        valid = false;
        continue;
      }
      if (!(isalpha(request.at(0)) && isdigit(request.at(1)))) {
        valid = false;
        continue;
      }
      request = start + request;
      continue;
    }
    case 3: {
      if (!(isalpha(request.at(0)) && isalpha(request.at(1)) &&
            isdigit(request.at(2)))) {
        valid = false;
      }
      if ((request.at(1) < 'a') || (request.at(1) > 'h') ||
          (request.at(2) < '1') || (request.at(2) > '8')) {
        valid = false;
        continue;
      }
      switch (request.at(0)) {
      case 'k':
      case 'q':
      case 'b':
      case 'n':
      case 'r':
      case 'p': {
        // debug I am not done with this yet, I was hoping to get a notation
        // with three characters
        valid = false;
        continue;
      }
      default: {
        valid = false;
        continue;
      }
      }
    }
    case 5: {
      valid = false;
      continue;
    }
    case 4: {
      // make sure that request is alpha-digit-alpha-digit
      if (!(isalpha(request.at(0)) && isdigit(request.at(1)) &&
            isalpha(request.at(2)) && isdigit(request.at(3)))) {
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
      break;
    }
    default: {
      cout << "Too many characters" << endl;
      valid = false;
      continue;
    }
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
    // moves the piece from the inital position to the final, while setting
    // the initial position to empty ("  ")
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
  } while (!validMove(board, iOld, jOld, iNew, jNew, color, 0));

  tuple<int, int> initial, finale;
  initial = make_tuple(iOld, jOld);
  finale = make_tuple(iNew, jNew);
  if (validMove(board, iOld, jOld, iNew, jNew, color, 0)) {
    string piece = board.at(get<0>(initial)).at(get<1>(initial));
    board.at(get<0>(initial)).at(get<1>(initial)) = "  ";
    board.at(get<0>(finale)).at(get<1>(finale)) = piece;
    cout << "Computer " << ((color != "white") + 1)
         << " played: " << static_cast<char>(jOld + 97)
         << static_cast<char>(iOld + 49) << static_cast<char>(jNew + 97)
         << static_cast<char>(iNew + 49) << endl;
  } else {
    cout << "That was not a legal move by the computer." << endl;
  }
}

void promotion(vector<vector<string>> &board, string color) {
  for (int i = 0; i < board.size(); i += board.size() - 1) {
    for (unsigned int j = 0; j < board.at(7).size(); j++) {
      if (board.at(7).at(j).at(0) == color.at(0)) {
          string response;
          bool validResponse = 0;
          char promotion;
        cout << "To what would you like to promote the pawn at "
             << static_cast<char>(j + 48) << static_cast<char>(i + 48) << "?"
             << endl;
             do {
getline(cin, response);
if (!response.size()) {
    break;
}
promotion = toupper(response.at(0));
switch (promotion) {
    case 'Q':
    case 'B':
    case 'N':
    case 'R':
    
}
             } while(validResponse);

      }
    }
  }
}