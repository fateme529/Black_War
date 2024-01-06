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
                createBoard(board_m);
                board_m[ox][0] = " > ";
                runGame(board_m, 0);
            }
            else if (command == "help")
            {
                help();
            }
            else if (command == "load")
            {
                int o = 0;

                loadStringArrayFromFile(board_l, "string_array_data.bin");
                point = loadIntFromFile("point.bin");

                for (size_t i = 0; i < row; i++)
                {
                    for (size_t j = 0; j < column; j++)
                    {
                        if (board_l[i][j] == " < ")
                        {
                            board_l[i][j] = "   ";
                            e.set_enemy_flag(true);
                            e.set_enemy_move(j);
                            flagEnemyHit = true;
                            e.set_enemy_random(i);
                        }

                        if (board_l[i][j] == " > ")
                        {
                            board_l[i][j] = "   ";
                            // ox = i;
                        }

                        if (barrier_1.get_flag_wall() == false && board_l[i][j] == " # ")
                        {
                            board_l[i][j] = "   ";
                            barrier_1.set_flag_wall(true);
                            barrier_1.set_wall_move(j);
                            flagWallHit = true;
                            barrier_1.set_wall_r(i);
                        }
                        if (barrier_1.get_flag_wall() == true && board_l[i][j] == " # ")
                        {
                            board_l[i][j] = "   ";
                            barrier_2.set_flag_wall(true);
                            barrier_2.set_wall_move(j);
                            flagWallHit = true;
                            barrier_2.set_wall_r(i);
                        }
                        if (board_l[i][j] == " * ")
                        {
                            board_l[i][j] = "   ";
                            s.set_fire_flag(true);
                            s.set_fire_move(j);
                            flagEnemyHit = true;
                            flagWallHit = true;
                            o = i;
                        }
                    }
                }
                board_l[ox][0] = " > ";

                runGame(board_l, o);
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
// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------
void App::runGame(string board[][column], int o)
{

    // printBoard(board, 150);

    while (true)
    {
        // ---------- shoot
        try
        {
            if (s.get_fire_flag() && s.get_fire_move() < column && flagEnemyHit && flagWallHit)
            {
                shootStatus(o, board, s.get_fire_move());
                s.set_fire_move(s.get_fire_move() + 1);
            }
            else
            {
                s.set_fire_move(1);
                s.set_fire_flag(false);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        // ---------------- enemy
        if (e.get_enemy_flag() && e.get_enemy_move() != -1 && flagEnemyHit)
        {
            e.enemyStatus(e.get_enemy_random(), board, e.get_enemy_move());
            e.set_enemy_move(e.get_enemy_move() - 1);
            if (e.get_enemy_move() == 5)
            {
                barrier_1.set_flag_wall(true);
            }
            if (e.get_enemy_move() == 12)
            {
                barrier_2.set_flag_wall(true);
            }
        }
        else
        {
            e.set_enemy_random(e.generateRandom());
            e.set_enemy_move(column - 1);
        }
        // ------------------- wall 1
        if (barrier_1.get_flag_wall() && barrier_1.get_wall_move() != -1)
        {
            barrier_1.barrierStatus(barrier_1.get_wall_r(), board, barrier_1.get_wall_move());
            barrier_1.set_wall_move(barrier_1.get_wall_move() - 1);
        }
        else
        {
            barrier_1.set_wall_r(barrier_1.generateRandom());
            barrier_1.set_wall_move(column - 1);
            barrier_1.set_flag_wall(false);
        }

        // ------------------- wall 2
        if (barrier_2.get_flag_wall() && barrier_2.get_wall_move() != -1)
        {
            barrier_2.barrierStatus(barrier_2.get_wall_r(), board, barrier_2.get_wall_move());
            barrier_2.set_wall_move(barrier_2.get_wall_move() - 1);
        }
        else
        {
            barrier_2.set_wall_r(barrier_2.generateRandom());
            barrier_2.set_wall_move(column - 1);
            barrier_2.set_flag_wall(false);
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
                if (!s.get_fire_flag())
                {
                    s.set_fire_flag(true);
                    o = checkHeliPos(board);
                }

                break;
            case 'e':
                printBoard(board, 150);
                saveStringArrayToFile(board, "string_array_data.bin");
                saveIntToFile(point, "point.bin");
                clear();

                exit(1);
                break;
            default:
                break;
            }
        }
        flagWallHit = wallHit(board);
        flagEnemyHit = enemyHit(board);
        checkGameOver(checkHeliPos(board), board);
        printBoard(board, 150);
    }
}
// ---------------------------------------------------------------------------
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
// ---------------------------------------------------------------------------
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

                // SaveGameData(MyFile, board);
                printBoard(board, 100);
                // MyFile.close();
                exit(1);
            }
        }
    }
    return true;
}
// ---------------------------------------------------------------------------
bool App::enemyHit(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            if (board[i][j] == " * " && board[i][j + 1] == " < " || board[i][j] == " * " && board[i][j + 2] == " < ")
            {
                board[i][j] = "   ";

                if (board[i][j + 2] == " < ")
                {
                    board[i][j + 2] = "   ";
                }
                else
                {
                    board[i][j + 1] = "   ";
                }
                ++point;
                return false;
            }
        }
    }
    return true;
}
// ---------------------------------------------------------------------------
bool App::wallHit(string board[][column])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {

            if (board[i][j] == " * " && board[i][j + 1] == " # " || board[i][j] == " * " && board[i][j + 2] == " # ")
            {
                return false;
            }
        }
    }
    return true;
}
// ---------------------------------------------------------------------------
void App::saveStringArrayToFile(const string arr[][column], const string &filename)
{
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open())
    {
        std::cerr << "Unable to open the binary file for writing!" << std::endl;
        return;
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            // Write the length of the string
            size_t len = arr[i][j].size();
            outFile.write(reinterpret_cast<const char *>(&len), sizeof(size_t));

            // Write the string itself
            outFile.write(arr[i][j].c_str(), len);
        }
    }

    outFile.close();
}
// ---------------------------------------------------------------------------
void App::loadStringArrayFromFile(std::string arr[][column], const std::string &filename)
{
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
    {
        std::cerr << "Unable to open the binary file for reading!" << std::endl;
        return;
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            // Read the length of the string
            size_t len;
            inFile.read(reinterpret_cast<char *>(&len), sizeof(size_t));

            // Read the string itself
            arr[i][j].resize(len);
            inFile.read(&arr[i][j][0], len);
        }
    }

    inFile.close();
}
// ---------------------------------------------------------------------------
void App::saveIntToFile(int value, const std::string &filename)
{
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open())
    {
        std::cerr << "Unable to open the binary file for writing!" << std::endl;
        return;
    }

    // Write the integer value to the file
    outFile.write(reinterpret_cast<const char *>(&value), sizeof(int));

    outFile.close();
}
// ---------------------------------------------------------------------------
int App::loadIntFromFile(const std::string &filename)
{
    int value = 0;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
    {
        std::cerr << "Unable to open the binary file for reading!" << std::endl;
        return value; // Return a default value or handle the error as needed
    }

    // Read the integer value from the file
    inFile.read(reinterpret_cast<char *>(&value), sizeof(int));

    inFile.close();

    return value;
}