#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../BoardGamesLib/board.h"
#include "../BoardGamesLib/tile.h"
#include "../BoardGamesLib/TicTacToe.h"
#include "../BoardGamesLib/Sudoku.h"
#include "../BoardGamesLib/Menu.h"

int main()
{
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

    TicTacToe tics;
    sf::Thread thread2(&TicTacToe::play, &tics);
    window.setActive(false);
    thread2.launch();
    gboard.display(tics);

//    std::vector<std::string> text = { "Quick Game", "Load User", "Exit" };
//    Menu menu(900, 900, text);
//    menu.RunMenu(window);
//
//    Sudoku sudoku("easy", gboard);
////    sf::Thread thread(&Board::display, &gboard);
//    sf::Thread thread2(&Sudoku::play, &sudoku);
////    thread.launch();
//
//    window.setActive(false);
////    gboard.display();
//    thread2.launch();
//    gboard.display();
//   // tics.play();

   return 0;
}
