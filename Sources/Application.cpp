#include "Application.h"
#include "Display.h"
#include <iostream>
#include "SFML/System/Clock.hpp"
#include "States/Playing.h"
#include "SFML/Window/Keyboard.hpp"

#include "Entity.h"

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
    text.setString("Press Space");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setPosition(Display::width/2,Display::height/2);

    sf::Clock clock;

    Entity player;
    player.sprite.setPosition(Display::width/6, Display::height/3);

    while(Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();

        Display::checkWindowEvents();


        Display::clear();

        Playing::input();
        Playing::update(dt, &player.sprite);
        Playing::draw(text, player.sprite);

        Display::display();
    }
}
