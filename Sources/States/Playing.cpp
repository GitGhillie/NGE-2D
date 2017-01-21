#include "Playing.h"

#include "SFML/Graphics.hpp"
#include "math.h"
#include "../Display.h"
#include <iostream>

namespace Playing
{
    void input()
    {

    }

    void update(float dt, sf::Text text)
    {
        std::cout << "Updating" << std::endl;
    }

    void draw(sf::Text text)
    {
        Display::draw(text);
    }
}
