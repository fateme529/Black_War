#pragma once
#include <string>

#define row 10
#define column 20

class shoot
{
private:
    bool fire_flag ;
    int fire_move;

public:
    shoot();
    void shootStatus(int random, std::string board[][column], int Right);
    void set_fire_flag(bool flag);
    bool get_fire_flag();
    void set_fire_move(int move);
    int get_fire_move();
};