#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SFML/Graphics.hpp>

class Background
{
    private:
        const float velX = 200.0f;
    public:
        Background();

        sf::Texture textureBG;
        sf::Sprite spriteBG;

        ~Background();
};

#endif // BACKGROUND_H_INCLUDED
