// This file is the header for the chess bot project
// Please place all public function headers in here
// With a comment description of what the function does

#pragma once
#include <string>
#include <vector>
using namespace std;

// makeBoard() returns the initial 2-d vector of chess with pieces (as strings)
// in their starting positions
vector<vector<string>> makeBoard();

// takeTurn() should be a void function that passes the current chess board vector by reference to edit that board. The second parameter is for the color of piece to move. It should prompt the player for a move and then move accordingly.
void takTurn(vector<vector<string>>&, string color);

// comTurn() should be similar to takeTurn(), but the turn will be completed by the computer.
void comTurn(vector<vector<string>>&, string color);

// printBoard() is a void function with the current chess board as a const reference. It should cout ascii art to display the board.
void printBoard(const vector<vector<string>>&);