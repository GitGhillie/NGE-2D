#include "Application.h"
#include "Display.h"
#include <iostream>
#include "SFML/System/Clock.hpp"
#include "States/Playing.h"

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
    const float g = 9.81f;

    while(Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();

        Display::checkWindowEvents();


        Display::clear();

        Playing::input();
        velY += g * dt;
        text.move(0,velY * dt);
        Playing::draw(text);
        // draw everything here...
        // window.draw(...);

        Display::display();
    }
}
