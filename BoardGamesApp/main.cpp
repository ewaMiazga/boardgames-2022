#include <iostream>
#include <SFML/Graphics.hpp>
#include "../BoardGamesLib/game.h"

int main()
{
    sf::Font font;
    if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
    {
        std::cout << "error loading the file";
        system("pause");
    }

    sf::RenderWindow win;
    SudokuWindow sudoku(900, 900, font);
    win.create(sf::VideoMode(900, 900), "Sudoku");
    sudoku.play(win);

    return 0;
}
