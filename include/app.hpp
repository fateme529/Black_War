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

#define row 10
#define column 20

class App : public helicopter
{
private:
    int speed = 500;
    unsigned int point = 0;
    bool flagEnemyHit = false;
    bool flagWallHit = true;

public:
    shoot s;
    helicopter h;
    enemy e;

    barrier barrier_1;
    barrier barrier_2;
    enemy enemy_1;
    App();
    void welcome() const;
    void help() const;
    int exec();
    void lowercase(string &str);
    void clear() const;
    void delay(int ms);
    void runGame(string board[][column], int o);
    void createBoard(string board[][column]);
    void printBoard(string board[][column], int s);
    bool checkStatus(string board[][column], int OX);
    int checkHeliPos(string board[][column]);
    bool checkGameOver(int o, string board[][column]);
    bool enemyHit(string board[][column]);
    bool wallHit(string board[][column]);
    void saveStringArrayToFile(const string arr[][column], const string &filename);
    void loadStringArrayFromFile(string arr[][column], const string &filename);

    string board_m[row][column];
    string board_l[row][column];

    void saveIntToFile(int value, const std::string &filename);
    int loadIntFromFile(const std::string &filename);
};
