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

    cout << "for start game enter :  S " << endl;
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
    while (clock() < start + ms)
        ;
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
void App::printBoard(string board[][column], int s)
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
    delay(s);
}
// -------------------------------------------------------
void App::runGame()
{
    string board[row][column];
    createBoard(board);
    board[ox][column - 12] = " > ";
    printBoard(board, 150);

    int enemy = 0;
    while (true)
    {
        if (enemy == 1)
        {
            enemy = 0;
            checkInput(board, true);
        }
        else
        {
            checkInput(board, false);
        }

        enemy++;
    }
}
void App::checkInput(string board[][column], bool flag)
{

    int r = e.generateRandom();
    int O = 0;

    for (int c = column - 1; c >= 0; c--)
    {
        if (flag)
        {
            e.enemyStatus(r, board, c);
        }
        if (!checkGameOver(O, board))
        {
            printBoard(board, 150);
            exit(1);
        }
        printBoard(board, 200);
        if (_kbhit())
        {

            switch (getch())
            {
            case 'a':
                h.heli_Status('a', board);
                break;
            case 'd':
                h.heli_Status('d', board);
                break;
            case 'w':
                O = checkHeliPos(board);

                for (int i = 1; i < column; i++)
                {
                    if (flag)
                    {
                        e.enemyStatus(r, board, c);
                    }

                    s.shootStatus(O, board, i);

                    if (_kbhit())
                    {
                        switch (getch())
                        {
                        case 'a':
                            h.heli_Status('a', board);
                            break;
                        case 'd':
                            h.heli_Status('d', board);
                            break;

                        default:
                            break;
                        }
                    }
                    if (c != 0)
                    {
                        c--;
                    }
                    if (!checkGameOver(O, board))
                    {
                        printBoard(board, 150);
                        exit(1);
                    }

                    printBoard(board, 150);
                }

                break;

            default:
                break;
            }
        }
    }
}
int App::checkHeliPos(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == " > ")
        {
            return i;
        }
    }
}

// -------------------------------------------------------
bool App::checkGameOver(int o, string board[][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == " > " && board[i][j + 1] == " @ ")
            {
                return false;
            }
        }
    }
    return true;
}