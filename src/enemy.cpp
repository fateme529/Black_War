#include "../include/enemy.hpp"
#include "../include/barrier.hpp"

int enemy::generateRandom()
{
    int rand;
    rand = barrier::generateRandom();
    if (rand == 0)
    {
        ++rand;
    }
    if (rand == 8)
    {
        --rand;
    }
    return rand;
}

void enemy::enemyStatus(int random, std::string board[][column], int Left)
{
    for (int i = column - 1; i > Left; i--)
    {

        board[random + 1][i] = "   ";
        board[random - 1][i] = "   ";
    }
    if (Left % 2 == 0 && Left != 0)
    {
        board[random + 1][Left] = " < ";
    }
    else if (Left != 0)
    {
        board[random - 1][Left] = " < ";
    }

    for (int i = 0; i < row; i++)
    {
        if (board[i][0] != " > ")
        {
            board[i][0] = "   ";
        }
    }
}
