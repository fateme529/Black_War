#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <exception>
#include <cctype>
#include <time.h>
#include <conio.h>

#include "heli.hpp"
#include "shoot.hpp"
#include "enemy.hpp"
using namespace std;

#define row 9
#define column 12

class App : public helicopter
{
private:
    int speed = 500;
    unsigned int point = 0;
    
    

public:
    shoot s;
    helicopter h;
    enemy e;
    App();
    void welcome() const;
    void help() const;
    int exec();
    void lowercase(string &str);
    void clear() const;
    void delay(int ms);
    void runGame();
    void createBoard(string board[][column]);
    void printBoard(string board[][column], int s);
    bool checkStatus(string board[][column], int OX);
    void checkInput(string board[][column], bool flag);
    int checkHeliPos(string board[][column]);
    bool checkGameOver(int o, string board[][column]);
    void hit( string board[][column]);
};
