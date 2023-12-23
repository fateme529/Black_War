#include "../include/shoot.hpp"
#include <time.h>
#include <string>

void shoot::shootStatus(int X, std::string board[][column], int Right)

{

    for (size_t i = 1; i < Right; i++)
    {
        board[X][i] = "   ";
    }
    board[X][Right] = " * ";
}
