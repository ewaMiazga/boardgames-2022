#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include "../BoardGamesLib/board.h"
#include "../BoardGamesLib/App.h"

int main()
{
//    sf::Font font;
//    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
//    {
//        std::cout << "error loading the file";
//        system("pause");
//    }
//
//    std::cout<<"Choose game: \n0 - exit\n1 - sudoku\n2 - tictactoe\n3 - crossword\n";
//    int choice;
//    std::cin>>choice;
//
//    if(!choice)
//    {
//        return 0;
//    }
//    if(choice == 1)
//    {
//        sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
//        //SudokuWindow();
//        Board gboard(sf::Vector2f(0, 0),
//                     sf::Color::Black,
//                     sf::Color(155, 155, 155, 100),
//                     sf::Color::Black,
//                     font,
//                     900,
//                     9,
//                     window);
//        Sudoku sudoku("easy");
//        sf::Thread thread2(&Sudoku::play, &sudoku);
//        window.setActive(false);
//        thread2.launch();
//        gboard.display(sudoku);
//    }
//    if(choice == 2)
//    {
//        sf::RenderWindow window(sf::VideoMode(900, 900), "TicTacToe");
//        Board gboard( sf::Vector2f(0, 0),
//                      sf::Color::Black,
//                      sf::Color(155, 155, 155, 100),
//                      sf::Color::Black,
//                      font,
//                      900,
//                      3,
//                      window);
//
//        TicTacToe tics;
//        sf::Thread thread2(&TicTacToe::play, &tics);
//        window.setActive(false);
//        thread2.launch();
//        gboard.display(tics);
//    }
//    if(choice == 3)
//    {
//        Crossword crossword;
//        sf::RenderWindow window(sf::VideoMode(900, 900), "Crossword");
//        Board gboard( sf::Vector2f(0, 0),
//                      sf::Color::Black,
//                      sf::Color(155, 155, 155, 100),
//                      sf::Color::Black,
//                      font,
//                      900,
//                      20,
//                      window);
//        sf::Thread thread2(&Crossword::play, &crossword);
//        window.setActive(false);
//        thread2.launch();
//        gboard.display(crossword);
//    }
    sf::Font font;
    user_account user1;
    if (!font.loadFromFile("Qarolina.ttf"))
    {
        std::cout << "error loading the file";
        system("pause");
    }
    App game(font);
    game.PlayCrosswords(user1);
    return 0;
}
