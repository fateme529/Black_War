#include "../include/app.hpp"
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
