#include "Playing.h"

#include "math.h"
#include "../Display.h"
#include <iostream>


namespace Playing
{
    float velY = 0.0f;
    bool isPressed = false;
    sf::Event eventKey;

    void input(sf::Sprite* player)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isPressed == false)
        {
            isPressed = true;
            velY = -g; //How does this work...
            player->setRotation(-20);
        }
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            isPressed = false;
        }

    }

    void update(float dt, sf::Sprite* player)
    {


        if(player->getPosition().y < -40)
        {
            player->setPosition(player->getPosition().x,Display::height / 3);
            velY = 0;
        }
        if(player->getPosition().y > Display::height - 20)
        {
            player->setPosition(player->getPosition().x,Display::height / 3);
            velY = 0;
        }
        if(velY > 1000)
        {
            velY = 1000;
        }

        velY += g * dt * resistance;
        player->move(0,(velY * dt));
        player->rotate(sin(velY / 1000 - g / 4));
    }

    void draw(sf::Text text,sf::Sprite sprite)
    {
        Display::draw(text, sprite);
    }
}
