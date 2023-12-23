#include "../include/enemy.hpp"

int enemy::generateRandom() // tolid add tasadofi
{
    srand((unsigned)time(NULL));
    int random = rand() % column; // bein baze mishakhas
    return random;
}

void enemy::enemyStatus(int random, std::string board[][column], int down) 
{
    for (size_t i =11 ; i> down; i--)
    {
        board[random][i] = "   ";
    }
    board[random][down] = " @ ";
}
