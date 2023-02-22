// This file is the header for the chess bot project
// Please place all public function headers in here
// With a comment description of what the function does

#pragma once
#include <string>
#include <vector>

// makeBoard() returns the initial 2-d vector of chess with pieces (as strings)
// in their starting positions
std::vector<std::vector<std::string>> makeBoard();