#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Display
{
    void initialize();
    void checkWindowEvents();
    void clear(sf::Color color);
    void draw(sf::Text thing,
              sf::Sprite sprite,
              sf::Sprite ground1);
    void display();
    bool isOpen();

    constexpr int width = 1280, height = 720;
}

#endif // DISPLAY_H_INCLUDED
