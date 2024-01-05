#pragma once
#include "shoot.hpp"
#include <string>
#define row 12
#define column 20



class helicopter :public shoot
{
private:

public:
    unsigned int X_heli = 0;
    void heli_Status(char playerMove, std::string board[][column]);
    int ox = row/2; // snake head position
};