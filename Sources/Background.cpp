#include "Background.h"
#include <iostream>

Background::Background()
{
    if (!textureBG.loadFromFile("Textures/ground.png"))
    {
        std::cout << "Loading Background texture failed" << std::endl;
    }
    spriteBG.setTexture(textureBG);
    //texture.setSmooth(true);
    std::cout << "Loading Background" << std::endl;
}

Background::~Background()
{
    std::cout << "Deleting Background" << std::endl;
}
