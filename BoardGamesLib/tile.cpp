#include <SFML/Graphics.hpp>
#include "tile.h"



Tile::Tile(
    sf::Vector2f position,
    sf::Color color,
    sf::Font &font,
    double size,
    bool isVisible,
    char shown,
    char real
)
{
    setPosition(position);
    setFillColor(sf::Color::White);
    setSize(sf::Vector2f(size, size));
    setOutlineThickness(-10.f * size * 0.01);
    setOutlineColor(color);
    
    displayValue.setFont(font);
    displayValue.setString(std::to_string(shown));
    displayValue.setCharacterSize(10.f);
    if (isVisible)
    {
        displayValue.setFillColor(sf::Color::Blue);
    }
    else
    {
        displayValue.setFillColor(sf::Color::Green);
    }
    displayValue.setPosition(position + sf::Vector2f(12.0f, 2.0f));
  
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
    window.draw(displayValue);
}

char Tile::getShown()
{
    return this->shown;
}

char Tile::getReal()
{
    return this->real;
}