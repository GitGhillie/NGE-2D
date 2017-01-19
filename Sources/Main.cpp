#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    cout << "App started" << endl;

    int width = 1280, height = 720; //Resolution.

    sf::RenderWindow window(sf::VideoMode(width, height), "2d Engine");
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    if(!font.loadFromFile("Fonts/LCD_Solid.ttf"))
    {
        cout << "error" << endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Ayy lmao");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setPosition(width/2,height/2);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(text);
        window.display();
    }

    return 0;
}
