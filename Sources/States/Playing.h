#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Playing
{
    void input();
    void update(float dt, sf::Text* text);
    void draw(sf::Text text);
}

#endif // PLAYING_H_INCLUDED
