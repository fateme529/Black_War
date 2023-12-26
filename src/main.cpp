#include <iostream>
#include "../include/app.hpp"
#include "../include/heli.hpp"
#include "../include/shoot.hpp"
using namespace std;

main()
{
    App app;
    shoot shoot;
    string board[row][column];
    app.createBoard(board);
    app.printBoard(board, 350);
    app.runGame();
}