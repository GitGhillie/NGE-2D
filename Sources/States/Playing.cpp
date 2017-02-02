#include "Playing.h"

#include "math.h"
#include "../Display.h"
#include <iostream>
#include "../Background.h"


namespace Playing
{
    float velY = 0.0f;
    bool isPressed = false;
    sf::Event eventKey;
    float rot;

    void input(sf::Sprite* player)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isPressed == false)
        {
            isPressed = true;
            velY = -G; //How does this work...
            player->setRotation(-20);
            std::cout << "Press" << std::endl;
        }
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            isPressed = false;
        }

    }

    void update(float dt, sf::Sprite* player, sf::Sprite* ground1)
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
        velY += G * dt * resistance;
        player->move(0,(velY * dt));

        rot = player->getRotation();
        if ((rot < 361 && rot > 330) || (rot > -1 && rot < 60))
            player->rotate(35 * dt);

        //std::cout << player->getRotation() << std::endl;

        ground1->move(-90 * dt,0);
        if (ground1->getPosition().x < -1 * Display::width)
            ground1->setPosition(0, Display::height - 100);
    }

    void draw(sf::Text text,sf::Sprite sprite,sf::Sprite ground1)
    {
        Display::draw(text, sprite, ground1);
    }
}
