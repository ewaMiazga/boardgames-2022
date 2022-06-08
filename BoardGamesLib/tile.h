#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

//utility class representing the smallest element of a Board Game
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
        bool isVisible = true,
        char value = 0
    );

    void draw(sf::RenderWindow& window); //draws tile and its value

    char getValue();
    void setValue(char);
    bool isVisible();
    void setVisibility(bool);

private:
    bool visibility; //determines whether object will be rendered
    sf::Vector2f position; //offset of top left corner in relation to top left corner of current window
    char value;
    sf::Text displayValue; //Text object allowing to display stored value
};
