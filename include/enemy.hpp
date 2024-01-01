#pragma once

#include "barrier.hpp"

class enemy : public barrier
{
private:
public:

        int generateRandom() ;// tolid add tasadofi
    
        void enemyStatus(int random, std::string board[][column], int left);
};
