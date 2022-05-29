#include <iostream>
#include <SFML/Graphics.hpp>
#include "../BoardGamesLib/tile.h"

int main()
{
    sf::Font font;
    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
    {
        std::cout<<"error loading the file";
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "TEST");
    Tile square(sf::Vector2f(300.f, 300.f), sf::Color::Red, font, 200, true);


    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(square);
        window.display();
    }
    return 0;
}


