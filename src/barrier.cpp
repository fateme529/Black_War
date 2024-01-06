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
barrier::barrier()
{
    set_wall_r();
    set_flag_wall(false);
    set_wall_move(column - 1);
}
void barrier ::set_wall_r()
{
    wall_r = generateRandom();
}
int barrier::get_wall_r()
{
    return wall_r;
}
void barrier::set_flag_wall(bool flag)
{
    wall = flag;
}
bool barrier::get_flag_wall()
{

    return wall;
}
void barrier::set_wall_move(int move)
{
    wall_move = move;
}
int barrier::get_wall_move()
{

    return wall_move;
}
