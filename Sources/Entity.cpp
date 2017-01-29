#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    if (!texture.loadFromFile("Textures/Sprite.png"))
    {
        std::cout << "Loading entity texture failed." << std::endl;
    }
    sprite.setTexture(texture);
    texture.setSmooth(true);
}

Entity::~Entity()
{
    std::cout << "Deleting Entity" << std::endl;
}
