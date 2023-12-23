#include "../include/shoot.hpp"
#include <time.h>
#include <string>

void shoot::shootStatus(int X, std::string board[][column],int Right)

{

    for (int i = 1; i < column; i++)
    {
        board[X][i] = "   ";
    }
    board[X][Right] = " * ";
    

    // for (size_t i = 0; i < down; i++)
    // {
    //     board[X][1] = "   ";
    //     board[X][1] = " * ";
    // }

    // if (down == 11)
    // {
    //     board[X][down] = "   "; // vaghti be akharesh mirese * pak mishe
    // }
}
