#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:
    Tile() = default;
    Tile(
        sf::Vector2f position,
        sf::Color frameColor,
        sf::Color backgroundColor,
        sf::Color displayColor,
        sf::Font& font,
        double size, 
        bool isVisible,
        char shown = 0,
        char real = 0
    );

    void draw(sf::RenderWindow& window);

    char getShown();
    char getReal();

    void setShown(char);
    void setReal(char);
    void setVisibility(bool);
    

private:
    bool isVisible;
    sf::Vector2f position;
    char shown;
    char real;
    sf::Text displayValue;
};
