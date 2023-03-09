// This file is the header for the chess bot project
// Please place all public function headers in here
// With a comment description of what the function does

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// makeBoard() returns the initial 2-d vector of chess with pieces (as strings)
// in their starting positions
vector<vector<string>> makeBoard();

// takeTurn() should be a void function that passes the current chess board
// vector by reference to edit that board. The second parameter is for the color
// of piece to move, either "white" or "black". It should prompt the player for
// a move and then move accordingly.
// the definition is in chess_bot_turn.cpp
// THERE IS CURRENTLY AN ERROR WHERE MAIN DOES NOT LIKE THE FUNCTION.
void takeTurn(vector<vector<string>> &board, string color); // Keegan

// converts a string of 2 character, where the first is a MAYUS letter and the
// second character must be a number it returns a tuple with the letter
// converted into a number where A = 0, B = 1 and so on. it should be used to
// convert user input into rows and columns the definition is in
// chess_bot_turn.cpp
tuple<int, int> convertInput(string input);

// comTurn() should be similar to takeTurn(), but the turn will be completed by
// the computer.
void comTurn(vector<vector<string>> &board, string color); 

// printBoard() is a void function with the current chess board as a const
// reference. It should cout ascii art to display the board.
void printBoard(const vector<vector<string>> &board); // Joseph

// checkEndGame() is an integer function that returns integers based on the game
// state. It takes the chess board vector as a const reference.
int checkEndGame(const vector<vector<string>> &board);
// returns 0 if game is in progress
// returns 1 if player 1 (white) won
// returns 2 if player 2 (black) won
// returns 3 if the game is a draw

// valid move takes the board as a parameter along with coordinates for the old
// point and coordinates for the new point
bool validMove(const vector<vector<string>> &board, int iOld, int jOld,
               int iNew, int jNew, string color = "neutral");

