#include "Playing.h"

#include "SFML/Graphics.hpp"
#include "math.h"
#include "../Display.h"
#include <iostream>

namespace Playing
{
    float velY = 0.0f;
    const float g = 200.0f, resistance = 0.9f;

    void input()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            velY = -g;
        }
    }

    void update(float dt, sf::Text* text)
    {


        if(text->getPosition().y < -24)
        {
            text->move(0,(Display::height));
        }
        if(text->getPosition().y > Display::height - 20)
        {
            text->move(0,(-Display::height));
        }
        if(velY > 1000)
        {
            velY = 1000;
        }

        velY += g * dt * resistance;
        text->move(0,(velY * dt));
        std::cout << velY << std::endl;

    }

    void draw(sf::Text text)
    {
        Display::draw(text);
    }
}
