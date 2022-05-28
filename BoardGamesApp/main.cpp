#include <iostream>
#include <SFML/Graphics.hpp>
#include "../BoardGamesLib/tile.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "TEST");
    //sf::CircleShape shape(400.f);
    //shape.setFillColor(sf::Color::Red);
    ////shape.setOutlineThickness(-10.f);
    //shape.setOutlineColor(sf::Color(250, 150, 100));
    Tile square(sf::Vector2f(300.f, 300.f), sf::Color::Red, 200);

    //sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

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


