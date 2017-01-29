#include "Playing.h"

#include "math.h"
#include "../Display.h"
#include <iostream>


namespace Playing
{
    float velY = 0.0f;

    void input()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            velY = -g; //How does this work...
        }

    }

    void update(float dt, sf::Sprite* player)
    {


        if(player->getPosition().y < -24)
        {
            player->move(0,(Display::height));
        }
        if(player->getPosition().y > Display::height - 20)
        {
            player->move(0,(-Display::height));
        }
        if(velY > 1000)
        {
            velY = 1000;
        }

        velY += g * dt * resistance;
        player->move(0,(velY * dt));
        //std::cout << velY << std::endl;

    }

    void draw(sf::Text text,sf::Sprite sprite)
    {
        Display::draw(text, sprite);
    }
}
