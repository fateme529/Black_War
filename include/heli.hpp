#pragma once
#include <string>
#define row 9
#define column 12



class helicopter 
{
private:

public:

    void heli_Status(char playerMove, std::string board[][column]);
    int ox = row/2; // snake head position
};