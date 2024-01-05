#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>

#define row 12
#define column 20




class barrier
{
    private:
    public:
    int generateRandom();
    void barrierStatus(int random, std::string board[][column], int Left);
    
};