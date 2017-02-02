#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    std::cout << "Loading player entity" << std::endl;
    if (!texture.loadFromFile("Textures/Sprite.png"))
    {
        std::cout << "Loading entity texture failed" << std::endl;
    }
    sprite.setTexture(texture);

    //texture.setSmooth(true);
}

Entity::~Entity()
{
    std::cout << "Deleting player entity" << std::endl;
}
