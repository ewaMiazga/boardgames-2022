#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:
    Tile();
    Tile(sf::Vector2f position, sf::Color color, double size);
    ~Tile();

    void draw(sf::RenderWindow &window);

private:

};
