#include "Board.hpp"
#include <iostream>

Board::Board()
{
    boardState = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
}

const vector<vector<uint32_t>> &Board::GetState(void) 
{
    return boardState;
}