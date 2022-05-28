#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:
    Tile() = default;
    Tile(
        sf::Vector2f position, 
        sf::Color color, 
        double size, 
        bool isVisible,
        char shown,
        char real
    );
    ~Tile();

    void draw(sf::RenderWindow &window);

    char getShown();
    char getReal();

private:
    bool isVisible;
    sf::Vector2f position;
    char shown;
    char real;
};
