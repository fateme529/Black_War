#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>

#define row 9
#define column 12

class enemy
{
private:
public:
    int generateRandom();
    void enemyStatus(int random, std::string board[][column], int left);
};
