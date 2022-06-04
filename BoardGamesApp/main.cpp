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
    sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
    std::vector<std::string> info = { "BOARD GAMES!!!"};
    std::vector<std::string> text = { "Quick Game", "Load User", "Exit" };
    DecisionMenu win(900, 900, info, text);
    
    win.RunMenu(window);
    return 0;
}
