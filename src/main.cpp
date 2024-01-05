#include <iostream>
#include "../include/app.hpp"
#include "../include/heli.hpp"
#include "../include/shoot.hpp"
using namespace std;

main()
{
    
        App app;
    try
    {
        return app.exec();
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }

    return 0;
}