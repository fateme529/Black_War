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

    for(int i =0 ; i<row ; i++)
    {
        board [i][1] = "   ";
    }

  

 }
    
    /* for (int j = column - 1; j > 0; j--)
        {

            if (board[i][j] == " @ " && board[i][j - 1] == " * ")
            {
                for (int k = j; j < column; j++)
                    board[i][j - 1] = "   ";
            }
        }*/