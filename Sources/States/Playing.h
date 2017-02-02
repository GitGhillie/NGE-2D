#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Playing
{
    void input(sf::Sprite* player);
    void update(float dt,
                sf::Sprite* player,
                sf::Sprite* ground1);
    void draw(sf::Text text,
              sf::Sprite sprite,
              sf::Sprite ground1);

    const float G = 200.0f, resistance = 0.9f;
}

#endif // PLAYING_H_INCLUDED
