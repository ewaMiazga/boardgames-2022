#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"

class GameWindow
{
public:
    const GameWindow() = default;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    Board gameBoard;
    std::pair<int, int> selected;
};

class SudokuWindow : public GameWindow
{
public:
    SudokuWindow() = default;
    SudokuWindow(double height, double width, sf::Font& font);

    void draw(sf::RenderWindow& window);
    void play(sf::RenderWindow& window);
    
};
