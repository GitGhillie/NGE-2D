#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class Entity
{
    private:
        float velY, velX;
        const float g = 200.0f, resistance = 0.9f;
    public:
        Entity();

        sf::Texture texture;
        sf::Sprite sprite;

        ~Entity();
};

#endif // ENTITY_H_INCLUDED
