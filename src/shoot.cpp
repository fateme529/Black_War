#include "../include/shoot.hpp"
#include <time.h>
#include <string>

void shoot::shootStatus(int X, std::string board[][column], int Right)

{

    for (int i = 1; i < Right; i++)
    {

        board[X][i] = "   ";
    }
    board[X][Right] = " * ";

    for (int i = 0; i < row; i++)
    {
        board[i][11] = "   ";
    }
}
