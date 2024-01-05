#include "../include/barrier.hpp"

int barrier::generateRandom() // tolid add tasadofi
{

    srand((unsigned)time(NULL));
    int random = rand() % (row);

    return random;
}

void barrier::barrierStatus(int random, std::string board[][column], int Left)
{
    for (int i = column - 1; i > Left; i--)
    {
        board[random][i] = "   ";
    }
    board[random][Left] = " # ";

    for (int i = 0; i < row; i++)
    {
        if (board[i][0] != " > ")
        {
            board[i][0] = "   ";
        }
    }
}
