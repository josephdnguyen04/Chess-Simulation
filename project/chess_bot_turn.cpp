#include "chess_bot_header.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

bool validMove(const vector<vector<string>> &board, int iOld, int jOld,
               int iNew, int jNew, string color) {
  bool valid = 1;
  if (color == "white" && board.at(iOld).at(jOld).at(0) != 'w') {
    valid = 0;
    return valid;
  }
  if (color == "black" && board.at(iOld).at(jOld).at(0) != 'b') {
    valid = 0;
    return valid;
  }
  if (board.at(iOld).at(jOld) == "  ") {
    valid = 0;
    return valid;
  }
  return valid;
}

void moveRequest(int &iOld, int &jOld, int &iNew, int &jNew) {
  string request;
  bool valid = 1;
  do {
    if (!valid) {
      cout << endl;
      cout << "***Sorry, that was an invalid request. Please try again.***" << endl
           << endl;
    }
    cout << "What move would you like to make?" << endl;
    getline(cin, request);
    // check if valid
    // make sure there are at least four characters in request
    if (request.size() < 4) {
      valid = 0;
      continue;
    }
    // make sure that request is alpha-digit-alpha-digit
    if (isalpha(request.at(0)) && isdigit(request.at(1)) &&
        isalpha(request.at(2)) && isdigit(request.at(3))) {
      request.at(0) = tolower(request.at(0)); // ignore capitol letters
      request.at(2) = tolower(request.at(2));
    } else {
      valid = 0;
      continue;
    }
    // make sure each character of request is in range of an 8x8 board
    if ((request.at(0) < 'a') || (request.at(0) > 'h') ||
        (request.at(2) < 'a') || (request.at(2) > 'h') ||
        (request.at(1) < '1') || (request.at(1) > '8') ||
        (request.at(3) < '1') || (request.at(3) > '8')) {
      valid = 0;
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
moveRequest(iOld, jOld, iNew, jNew);
 /*string one, two;
  cout << "Please make a move.\n";
  cin >> one >> two;
  tuple<int, int> initial, finale;
  initial = convertInput(one);
  finale = convertInput(two);
*/
  // moves the piece from the inital position to the final, while setting the
  // initial position to empty ("  ")
  tuple <int, int> initial, finale;
  initial = make_tuple(jOld,iOld);
  finale = make_tuple(jNew, iNew);
  string piece = board.at(get<0>(initial)).at(get<1>(initial));
  board.at(get<0>(initial)).at(get<1>(initial)) = "  ";
  board.at(get<0>(finale)).at(get<1>(finale)) = piece;
}
