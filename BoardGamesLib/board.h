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
        sf::Font& font,
        double size = 0,
        int elemNum = 0
    );
    ~Board();

    void draw(sf::RenderWindow& window);
    Tile& getTile(sf::Vector2i, sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::Text displayValue;
    double size;
    int elemNum;
    Tile** board;

};
