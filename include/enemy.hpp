#pragma once

#include "barrier.hpp"

class enemy : public barrier
{
private:
        bool enemy_flag;
        int enemy_move;
        int enemy_r;

public:
        enemy();
        int generateRandom(); // tolid add tasadofi
        void enemyStatus(int random, std::string board[][column], int left);
        void set_enemy_random(int rand);
        int get_enemy_random();
        void set_enemy_flag(bool flag);
        bool get_enemy_flag();
        void set_enemy_move(int move);
        int get_enemy_move();
        void set_enemy_o(int move);
        int get_enemy_o();
};
