#include "Application.h"
#include "Display.h"
#include <iostream>
#include "SFML/System/Clock.hpp"
#include "States/Playing.h"
#include "SFML/Window/Keyboard.hpp"

Application::Application()
{
    Display::initialize();
}

void Application::mainGameLoop()
{
    sf::Font font;
    if(!font.loadFromFile("Fonts/LCD_Solid.ttf"))
    {
        std::cout << "error" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Ayy lmao");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setPosition(Display::width/2,Display::height/2);

    sf::Clock clock;

    float velY = 0.0f;
    const float g = 200.0f, resistance = 0.9f;

    while(Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();

        Display::checkWindowEvents();


        Display::clear();


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            velY = -g;
        }

        if(text.getPosition().y < 1)
        {
            velY = 10;
        }
        if(text.getPosition().y > Display::height - 20)
        {
            velY = -40;
        }

        velY += g * dt * resistance;
        text.move(0,(velY * dt));
        std::cout << velY << std::endl; //Move this all into Playing.h functions.
        Playing::draw(text);
        // draw everything here...
        // window.draw(...);

        Display::display();
    }
}
