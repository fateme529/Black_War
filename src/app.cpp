#include "../include/app.hpp"
#include "../include/heli.hpp"
#include <time.h>
using namespace std;

// -------------------------------------------------------
App::App()
{
    welcome();
}
// -------------------------------------------------------
void App::welcome() const
{
    cout << "   |=|===================|=|      \n";
    cout << "   |=|     _________     |=|      \n";
    cout << "   |=|    |Black War|    |=|      \n";
    cout << "   |=|                   |=|      \n";
    cout << "   |=======================|      \n";
    cout << "   |=======================|      \n";

    cout << endl;
    cout << "[:)] "
         << "Enter <help> command to guide you\n"
         << endl;
}

// -------------------------------------------------------
void App::help() const
{
    cout << "[:)] "
         << "app commands : (case insensitive)" << endl;

    cout << "for start game enter :  S "<< endl;
}
// -------------------------------------------------------
int App::exec()
{
    string command;
    while (1)
    {
        try
        {
            cout << "> ";
            getline(cin, command);
            lowercase(command);

            if (cin.eof() || command == "s")
            {
               // runGame();
            }
            else if (command == "help")
            {
                help();
            }

            else if (command.empty())
            {
                // to prevent print undefined command in empty command
            }
            else
            {
                throw "undefined command";
            }
        }
        catch (const char *message)
        {
            cerr << "[:)] " << message << endl;
        }
        catch (const std::exception &e)
        {
            cerr << "[:)] " << e.what() << endl;
        }
        catch (...)
        {
            system("cls");
            cerr << "app finished" << endl;
            return EXIT_SUCCESS;
        }
    }

    
}
// -------------------------------------------------------
void App::lowercase(string &str)
{
    if (cin.eof() || str.empty())
    {
        return;
    }

    for (char &ch : str)
    {
        ch = tolower(ch); // حروف برنامه کوچک میکند
    }
}
// -------------------------------------------------------
void App::clear() const
{
#ifdef WINDOWS // windows based OS
    std::system("cls");
#else // unix like OS
    std::system("clear");
#endif

    welcome();
}
// -------------------------------------------------------
void App::delay(int ms)
{
    clock_t start = clock();
    while (clock() < start + ms);
}
// -------------------------------------------------------
void App::createBoard(string board[][column])
{

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            board[i][j] = "   ";
        }
    }
}
// -------------------------------------------------------
void App::printBoard(string board[][column])
{
    system("cls");
    cout << "point : " << point << "\n"
         << endl;
    cout << "+ ---------------------------------- +" << endl;
    for (size_t i = 0; i < row; i++)
    {
        cout << "|";
        for (size_t j = 0; j < column; j++)
        {
            cout << board[i][j];
        }
        cout << "|";
        cout << endl;
    }
    cout << "+ ---------------------------------- +" << endl;
    delay(speed);
    
}
// -------------------------------------------------------
void App::runGame()
{
    string board[row][column];
    createBoard(board);
    printBoard(board);
    board[ox][column-12] = " > ";

     while (1)
    {
       // int random = s.generateRandom();

        for (int i = 0; i < column; i++)
        {
            
            if (_kbhit())
            {
                char ch = _getch();
                h.heli_Status(ch, board);
                
           
          if(ch == 'w') 
            {
                   s.shootStatus(ox, board,i); // i == down
            }

            }
           
           
            printBoard(board);
        }
    }
}


// -------------------------------------------------------
bool App::checkStatus(string board[][column], int OX)
{

    if (board[row - 1][OX] == " ^ " && board[row - 2][OX] == " * ")
    {

        board[row - 2][OX] = "   "; // injori on * pake mishe
        return true;
    }
    else
    {
        for (size_t i = 0; i < column; i++)
        {
            if (board[row - 1][i] == " * ") // mige age be row ==0  resid
            {

                board[row - 2][i] == "   ";
                printBoard(board);
                cout << "GAME OVER" << endl;
                exit(0);
            }
        }
    }
}