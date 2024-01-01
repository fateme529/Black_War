#include "../include/barrier.hpp"


int barrier::generateRandom() // tolid add tasadofi
{

    srand((unsigned)time(NULL));
    int random = rand() % (row );

    return random;
}