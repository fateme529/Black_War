#include "../include/app.hpp"
#include "../include/heli.hpp"
#include <time.h>
using namespace std;
ofstream MyFile("filename.txt", ios::app);

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
                runGame();
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
    cout << "+ ---------------------------------------------------------- +" << endl;
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
    cout << "+ ---------------------------------------------------------- +" << endl;
    delay(s);
}
// -------------------------------------------------------
void App::runGame()
{

    int ww[column];
    for (int i = 0; i < column; i++)
    {
        ww[i] = 0;
    }
    string board[row][column];
    createBoard(board);
    board[ox][0] = " > ";
    printBoard(board, 150);

    enemy_r = e.generateRandom();
    wall_r_1 = e.generateRandom();
    wall_r_2 = e.generateRandom();

    int enemy_o = 0;
    int wall_o = 0;

    bool wall_1 = false;
    bool wall_2 = false;
    bool enemy_1 = true;
    bool fire_1 = false;

    int fire_1_move = 1;

    bool wallhit = true;

    while (true)
    {
        // ---------- shoot
        if (fire_1 && fire_1_move < column && flag_s && wallhit)
        {
            shootStatus(enemy_o, board, fire_1_move);
            fire_1_move++;
        }
        else
        {
            fire_1_move = 1;
            fire_1 = false;
        }
        // ---------------- enemy
        if (enemy_1 && enemy_1_move != -1 && flag_s)
        {
            e.enemyStatus(enemy_r, board, enemy_1_move);
            enemy_1_move--;
            if (enemy_1_move == 5)
            {
                wall_1 = true;
            }
            if (enemy_1_move == 12)
            {
                wall_2 = true;
            }
        }
        else
        {
            enemy_r = e.generateRandom();
            enemy_1_move = column - 1;
        }
        // ------------------- wall 1
        if (wall_1 && wall_1_move != -1)
        {
            b.barrierStatus(wall_r_1, board, wall_1_move);
            wall_1_move--;
        }
        else
        {
            wall_r_1 = e.generateRandom();
            wall_1_move = column - 1;
            wall_1 = false;
        }

        // ------------------- wall 2
        if (wall_2 && wall_2_move != -1)
        {
            b.barrierStatus(wall_r_2, board, wall_2_move);
            wall_2_move--;
        }
        else
        {
            wall_r_2 = e.generateRandom();
            wall_2_move = column - 1;
            wall_2 = false;
        }
        // -----------------------

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
                if (!fire_1)
                {

                    fire_1 = true;
                    enemy_o = checkHeliPos(board);
                }

                break;

            default:
                break;
            }
        }
        wallhit = wallHit(board);
        flag_s = hit(board);
        checkGameOver(checkHeliPos(board), board);
        printBoard(board, 150);
    }
}
// ------------------------------------------------------

int App::checkHeliPos(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == " > ")
        {
            return i;
        }
    }
    return 0;
}

// -------------------------------------------------------

bool App::checkGameOver(int o, string board[][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == " > " && board[i][j + 1] == " < ")
            {
                board[i][j + 1] = "   ";
                board[i][j] = " < ";
                printBoard(board, 100);
                exit(1);
            }
            if (board[i][j] == " > " && board[i][j + 1] == " # ")
            {
                board[i][j + 1] = "   ";
                board[i][j] = " # ";

                SaveGameData(MyFile,board);
                printBoard(board, 100);
                MyFile.close();
                exit(1);
            }
        }
    }
    return true;
}

// -------------------------------------------------------
bool App::hit(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            if (board[i][j] == " * " && board[i][j + 1] == " < " || board[i][j] == " * " && board[i][j + 2] == " < ")
            {
                board[i][j] = "   ";
                board[i][j + 1] = "   ";
                board[i][j + 2] = "   ";
                ++point;
                return false;
            }
        }
    }
    return true;
}
// ------------------------------------------------------------
int App::check_randoms(int wall_r, int enemy_r)
{
    if (wall_r == enemy_r)
    {
        wall_r += 2;
        if (wall_r >= row)
        {
            wall_r -= 4;
        }
    }
    else if (wall_r - 1 == enemy_r || wall_r + 1 == enemy_r)
    {
        wall_r += 1;
        if (wall_r >= row)
        {
            wall_r -= 2;
        }
    }
    else
    {
        return wall_r;
    }

    return wall_r;
}
// -----------------------------------------------------------
bool App::wallHit(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            if (board[i][j] == " * " && board[i][j + 1] == " # " || board[i][j] == " * " && board[i][j + 2] == " # ")
            {
                // board[i][j] = " # ";
                // board[i][j + 1] = "   ";
                // board[i][j + 2] = "   ";

                return false;
            }
        }
    }
    return true;
}
//----------------------------------------------------------------
void App::SaveGameData(ofstream &file, string board[][column])
{
    testopen(MyFile);
    int heli_gh = checkHeliPos(board);
    int enemy_r_gh = enemy_r;
    int enemy_1_move_gh = enemy_1_move;
    int wall_r_1_gh = wall_r_1;
    int wall_r_2_gh = wall_r_2;
    int wall_1_move_gh = wall_1_move;
    int wall_2_move_gh = wall_2_move;

     file<<left<<setw(30)<<point<<setw(30)<<heli_gh<<setw(30)<<enemy_1_move_gh<<setw(30)<<enemy_r_gh<<setw(30)<<wall_r_1_gh<<setw(30)<<wall_r_2_gh<<setw(30)<<wall_1_move_gh<<setw(30)<<wall_2_move_gh<<endl;
}
//-------------------------------------------------------------
void App::testopen(ofstream &out) // write in file
{
    if (!out)
    {
        cerr << "Can not open the file!!!" << endl;
        exit(EXIT_FAILURE);
    }
}
//---------------------------------------------------------------
void App::testopen(ifstream &out) // read in file
{
    if (!out)
    {
        cerr << "Can not open the file!!!" << endl;
        exit(EXIT_FAILURE);
    }
}
//--------------------------------------------