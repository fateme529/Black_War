#include <iostream>
#include "../include/heli.hpp"
using namespace std;



helicopter::helicopter()
{
}
void helicopter::heli_Status(char playerMove, std::string board[][column])
{

    if (playerMove == 'a')
    {
        board[row - 1][ox] = "   ";
        if (ox > 0) // check out of range
        {
            ox -= 1;
        }

        board[row - 1][ox] = " ^ ";
    }
    else if (playerMove == 'd')
    {
        board[row - 1][ox] = "   ";
        if (ox < column - 1) // check out of range
        {
            ox += 1;
        }
        board[row - 1][ox] = " ^ ";
    }
}