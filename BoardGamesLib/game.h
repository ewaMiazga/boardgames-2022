#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"

class GameWindow
{
public:
    const GameWindow() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
   // sf::Font& loadFont();


protected:
    Board gameBoard;
    sf::RenderWindow window;
    std::pair<int, int> selected;
    double height = 0;
    double width = 0;
    sf::Font *font = nullptr;
};

class SudokuWindow : public GameWindow
{
public:
    SudokuWindow() = default;
    SudokuWindow(double, double);
    ~SudokuWindow();

    void setup();
    void draw(sf::RenderWindow& window);
    void play();
    
};
