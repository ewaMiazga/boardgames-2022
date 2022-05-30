#include <SFML/Graphics.hpp>
#include "board.h"
#include "tile.h"


Board::Board(
    sf::Vector2f position,
    sf::Color frameColor,
    sf::Color backgroundColor,
    sf::Color displayColor,
    sf::Font& font,
    double size
)
{
    this->position = position;
}

