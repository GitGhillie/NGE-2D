#include "Application.h"
#include "Display.h"
#include <iostream>

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

    while(Display::isOpen())
    {
        Display::checkWindowEvents();


        Display::clear();

        // draw everything here...
        // window.draw(...);
        Display::draw(text);
        Display::display();
    }
}
