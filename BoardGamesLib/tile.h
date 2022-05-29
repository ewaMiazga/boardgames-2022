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
        sf::Font &font,
        double size, 
        bool isVisible,
        char shown = 'e',
        char real = 0
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
    sf::Text displayValue;
};
