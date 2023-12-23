#include <iostream>
#include "../include/heli.hpp"
using namespace std;




void helicopter::heli_Status(char playerMove, std::string board[][column])
{

    if (playerMove == 'a')
    {
        board[ox][column-12] = "   ";
        if (ox > 0) // check out of range
        {
            ox -= 1;
            
        }

        board[ox][column-12] = " > ";
    }
    else if (playerMove == 'd')
    {
        board[ox][column-12] = "   ";
        if (ox < column - 1) // check out of range
        {
            ox += 1;
            
        }
        board[ox][column-12] = " > ";

    }
    
}