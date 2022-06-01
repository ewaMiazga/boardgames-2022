#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../BoardGamesLib/board.h"
#include "../BoardGamesLib/tile.h"
#include "../BoardGamesLib/TicTacToe.h"

int main()
{
//    sf::Font font;
//    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
//    {
//        std::cout << "error loading the file";
//        system("pause");
//    }
//
//    sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
//    Board board(
//        sf::Vector2f(0, 0),
//        sf::Color::Black,
//        sf::Color(155, 155, 155, 100),
//        sf::Color::Black,
//        font,
//        900,
//        9,
//        window
//    );
//
//    while (window.isOpen())
//    {
//        sf::Event e;
//        while (window.pollEvent(e))
//        {
//            switch (unsigned int key = -1;  e.type)
//            {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//
//                case sf::Event::KeyPressed:
//                    key = e.key.code;
//                    //send to Game? Game sends back if valid?
//                    //board.update();
//                    break;
//
//                case sf::Event::MouseButtonPressed:
//                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
//                    {
//                        board.getTile(
//                            sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Red);
//                    }
//                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
//                    {
//                        board.getTile(
//                            sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Black);
//                    }
//
//                    //board.update(); ?
//                    break;
//
//                default:
//                    break;
//            }
//        }
//        window.clear(sf::Color::White);
//        board.draw();
//        window.display();
//    }

    sf::Font font;
    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
    {
        std::cout << "error loading the file";
        system("pause");
    }
    sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
    Board gboard( sf::Vector2f(0, 0),
        sf::Color::Black,
        sf::Color(155, 155, 155, 100),
        sf::Color::Black,
        font,
        900,
        3,
        window);
    TicTacToe tics(gboard);
    sf::Thread thread(&Board::display, &gboard);
    //sf::Thread thread(&TicTacToe::play, &tics);
    thread.launch();
    //gboard.display();
    window.setActive(false);
    Tile &tile = gboard.getTile(std::pair(2, 2));
    std::cout<<tile.getValue();
//    gboard.display();

    tics.play();

   return 0;
}