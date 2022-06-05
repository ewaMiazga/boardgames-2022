#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"
#include "TicTacToe.h"

class Board
{
public:
    Board(
            sf::Vector2f position,
            sf::Color frameColor,
            sf::Color backgroundColor,
            sf::Color displayColor,
            sf::Font &font,
            double size,
            int elemNum,
            sf::RenderWindow &window
    );
    ~Board();

    sf::RenderWindow &m_window;

    void draw();
    std::pair<int, int> getIndex(sf::Vector2i);
    Tile& getTile(std::pair<int, int> index);
    void display(TicTacToe &game);
    void update();


private:
    sf::Vector2f position;
    double size;
    Tile ** board;
    int elemNum;
    std::pair<int, int> selected = std::make_pair(-1, -1);
};
