#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>

#define row 10
#define column 20

class barrier
{
private:
    int wall_r;
    bool wall;
    int wall_move;

public:
    barrier();
    void set_wall_r();
    int get_wall_r();
    void set_flag_wall(bool flag);
    bool get_flag_wall();
    void set_wall_move(int move);
    int get_wall_move();

    int generateRandom();
    void barrierStatus(int random, std::string board[][column], int Left);
};