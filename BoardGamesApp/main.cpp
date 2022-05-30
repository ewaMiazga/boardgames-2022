#include <iostream>
#include <SFML/Graphics.hpp>
//#include "../BoardGamesLib/tile.h"
#include "../BoardGamesLib/board.h"

int main()
{
    sf::Font font;
    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
    {
        std::cout << "error loading the file";
        system("pause");
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "TEST");
    Board square(
        sf::Vector2f(100.f, 100.f), 
        sf::Color::Yellow, 
        sf::Color::White,
        sf::Color::Blue,
        font, 
        500,
        9
    );

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
        square.draw(window);
        window.display();
    }
    return 0;
}
