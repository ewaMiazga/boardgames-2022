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

    sf::RenderWindow window(sf::VideoMode(800, 800), "Sudoku");
    Board board(
        sf::Vector2f(100.f, 100.f), 
        sf::Color::Black, 
        sf::Color(155, 155, 155, 100),
        sf::Color::Black,
        font, 
        500,
        9
    );

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            switch (unsigned int key = -1;  e.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    key = e.key.code;
                    //send to Game? Game sends back if valid?
                    //board.update();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        //board.getTile(sf::Mouse::getPosition(window)).highlight;
                    }
                    //board.update(); ?
                    break;

                default:
                    break;
            }
        }
        window.clear(sf::Color::White);
        board.draw(window);
        window.display();
    }
    return 0;
}
