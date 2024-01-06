#include "../include/enemy.hpp"
#include "../include/barrier.hpp"
enemy::enemy()
{
    set_enemy_flag(true);
    set_enemy_move(column - 1);
}
int enemy::generateRandom()
{
    int rand;
    rand = barrier::generateRandom();
    if (rand == 0)
    {
        ++rand;
    }
    if (rand == row - 1)
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

void enemy::set_enemy_random()
{
    enemy_r = generateRandom();
}
int enemy::get_enemy_random()
{
    return enemy_r;
}
bool enemy::get_enemy_flag()
{
    return enemy_flag;
}
void enemy::set_enemy_flag(bool flag)
{
    enemy_flag = flag;
}
void enemy::set_enemy_move(int move)
{
    enemy_move = move;
}
int enemy::get_enemy_move()
{
    return enemy_move;
}
