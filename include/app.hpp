#pragma once
#include <iostream>
#include "heli.hpp"
using namespace std;

#define row 9
#define column 12

class App
{
private:
    int speed = 350;
    unsigned int point = 0;
    
public:
    helicopter helicopter;
    App();
    void welcome() const;
    void help() const;
    int  exec();
    void lowercase(string &str);
    void clear() const;
    void delay(int ms);
    void runGame();
    void createBoard(string board[][column]);
    void printBoard(string board[][column]);
};




