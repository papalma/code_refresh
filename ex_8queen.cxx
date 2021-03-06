// Based in solution the backtrack solution presented in 
// presented the book "Competitive Programming 3" by Steven and Felix Halim.

#include <iostream>
#include <vector>

std::vector<int> positionInRow;

bool canPlaceIn(int row, int col)
{
    for (int prev = 0; prev < col; ++prev)
    {
        if (positionInRow[prev] == row ||
            abs(positionInRow[prev] - row) == abs(prev - col))
            return false;
    }
    return true;
}

bool backtrack(int col, int side)
{
    if (col >= side)
        return true;

    for (int row = 0; row < side; ++row)
    {
        if (canPlaceIn(row, col))
        {
            positionInRow[col] = row;
            if (backtrack(col + 1, side))
                return true;
        }
    }
    return false;
}


int main()
{
    int side = 30;
    // std::cin >> side;
    positionInRow.resize(side, -1);

    if (backtrack(0, side))
    {
        for (auto i : positionInRow)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}