#include "Display.h"
#include <memory>

namespace Display
{
    std::unique_ptr<sf::RenderWindow> window;
    void initialize()
    {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "2d Engine");
        window->setVerticalSyncEnabled(true);

    }

    void checkWindowEvents()
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }

    void clear(sf::Color color)
    {
        window->clear(color);
    }

    void draw(sf::Text thing, sf::Sprite sprite)
    {
        window->draw(thing);
        window->draw(sprite);
    }

    void display()
    {
        window->display();
    }

    bool isOpen()
    {
        return window->isOpen();
    }
}
