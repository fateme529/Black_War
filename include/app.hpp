#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <exception>
#include <cctype>
#include <time.h>
#include <conio.h>
#include <fstream>

#include "heli.hpp"
#include "shoot.hpp"
#include "enemy.hpp"
using namespace std;

#define row 12
#define column 20

class App : public helicopter
{
private:
    int speed = 500;
    unsigned int point = 0;
    bool flag_s = false;
    int enemy_r;
    int enemy_1_move = column - 1;

public:
    shoot s;
    helicopter h;
    enemy e;
    barrier b;
    barrier barrier_1;
    barrier barrier_2;
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
    bool hit(string board[][column]);
    void head(int o, string board[][column]);
    int check_randoms(int wall_r, int enemy_r);
    int genrand();
    bool wallHit(string board[][column]);
    // void SaveGameData(ofstream &file, string board[][column]); // mikham toye file benivisam
    void testopen(ofstream &out);
    void testopen(ifstream &out);
};
