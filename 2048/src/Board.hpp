#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

class Board
{
public:
    Board();
    const vector<vector<uint32_t>> &GetState(void);

private:
    vector<vector<uint32_t>> boardState;
};


#endif // !BOARD_H