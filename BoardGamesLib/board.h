#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"

class Board
{
public:
    Board() = default;
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
    Tile& getTile(std::pair<int, int> index);
    void display();
    void update();

private:
    sf::Vector2f position;
    sf::Text displayValue;
    double size;
    int elemNum;
    Tile ** board;

};
