#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"
#include "board.h"
#include "Crossword.h"

class Cross : public Board
{
public:
    Cross(
            sf::Vector2f position,
            sf::Color frameColor,
            sf::Color backgroundColor,
            sf::Color displayColor,
            sf::Font &font,
            int width,
            int height,
            int xSpan,
            int ySpan,
            sf::RenderWindow &window
    );
    ~Cross();

    sf::RenderWindow &m_window;

private:
    int xSpan;
    int ySpan;
    int width;
    int height;
};
