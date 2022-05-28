#include <SFML/Graphics.hpp>
#include "tile.h"

Tile::Tile(){}

Tile::Tile(sf::Vector2f position, sf::Color color, double size)
{
    setPosition(position);
    setFillColor(color);
    setSize(sf::Vector2f(size, size));
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}