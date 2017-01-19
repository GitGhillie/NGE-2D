#include <iostream>
#include "Display.h"

using namespace std;

int main()
{
    cout << "App started" << endl;



    Display::initialize();


     sf::Font font;
    if(!font.loadFromFile("Fonts/LCD_Solid.ttf"))
    {
        std::cout << "error" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Ayy lmao");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
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

    return 0;
}
