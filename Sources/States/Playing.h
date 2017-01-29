#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Playing
{
    void input();
    void update(float dt, sf::Sprite* player);
    void draw(sf::Text text,sf::Sprite sprite);

    const float g = 200.0f, resistance = 0.9f;
}

#endif // PLAYING_H_INCLUDED
