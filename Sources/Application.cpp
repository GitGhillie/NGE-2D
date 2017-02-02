#include "Application.h"
#include "Display.h"
#include <iostream>
#include "SFML/System/Clock.hpp"
#include "States/Playing.h"
#include "SFML/Window/Keyboard.hpp"

#include "Entity.h"
#include "Background.h"

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
    text.setPosition(Display::width - 200, 10);

    sf::Clock clock;

    Entity player;
    player.sprite.setPosition(Display::width/6, Display::height/3);
    player.sprite.scale(2,2);
    player.sprite.setOrigin(15,24);

    Background ground1;
    ground1.spriteBG.setOrigin(0,3818);
    ground1.spriteBG.setPosition(0, Display::height - 100);


    sf::Color sky(204,255,255);

    while(Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();

        Display::checkWindowEvents();


        Display::clear(sky);

        Playing::input(&player.sprite);
        Playing::update(dt,
                        &player.sprite,
                        &ground1.spriteBG);
        Playing::draw(text,
                      player.sprite,
                      ground1.spriteBG);

        Display::display();
    }
}
