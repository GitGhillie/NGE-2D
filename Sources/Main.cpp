#include <iostream>
#include "Application.h"

int main()
{
    std::cout << "App started" << std::endl;

    Application app;

    app.mainGameLoop();

    return 0;
}
