#include <iostream>
#include "../include/app.hpp"
#include "../include/heli.hpp"
using namespace std;


main()
{
 App app;
 string board[row][column];
 app.createBoard(board);
 app.printBoard(board);
 app.runGame();

    
}