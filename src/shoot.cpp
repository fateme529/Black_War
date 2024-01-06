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
        board[i][column - 1] = "   ";
    }
}
shoot ::shoot()
{
    set_fire_flag(false);
    set_fire_move(1);
}
void shoot::set_fire_flag(bool flag)
{
    fire_flag = flag;
}
bool shoot::get_fire_flag()
{

    return fire_flag;
}
void shoot::set_fire_move(int move)
{
    fire_move = move;
}
int shoot::get_fire_move()
{

    return fire_move;
}