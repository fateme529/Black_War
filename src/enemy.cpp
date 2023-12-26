#include "../include/enemy.hpp"

int enemy::generateRandom() // tolid add tasadofi
{

    srand((unsigned)time(NULL));
    int random = rand() % row;
    return random;
}

void enemy::enemyStatus(int random, std::string board[][column], int Left)
{
    for (int i = column -1 ; i > Left; i--)
    {
        board[random][i] = "   ";
    }
    board[random][Left] = " @ ";
}
