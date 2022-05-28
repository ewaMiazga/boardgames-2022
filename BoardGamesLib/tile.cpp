#include <SFML/Graphics.hpp>
#include "tile.h"


Tile::Tile(
    sf::Vector2f position, 
    sf::Color color, 
    double size, 
    bool isVisible, 
    char shown = 0,
    char real = 0
)
{
    setPosition(position);
    setFillColor(sf::Color::White);
    setSize(sf::Vector2f(size, size));
    setOutlineThickness(-10.f*size*0.01);
    setOutlineColor(sf::Color(250, 150, 100));
    
    this->isVisible = isVisible;
    this->position = position;
    this->shown = shown;
    this->real = real;
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

char Tile::getShown()
{
    return this->shown;
}

char Tile::getReal()
{
    return this->real;
}