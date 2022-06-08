#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"
#include "TicTacToe.h"
#include "Sudoku.h"
#include "Crossword.h"

//representation of a square game Board consisting of Tiles
class Board
{
public:
    Board(
            sf::Vector2f position,
            sf::Color frameColor,
            sf::Color backgroundColor,
            sf::Color displayColor,
            sf::Font &font,
            double size,
            int elemNum,
            sf::RenderWindow &window
    );
    ~Board();

    sf::RenderWindow &m_window; //reference to window used to render

    virtual std::pair<int, int> getIndex(sf::Vector2i); //returns index of 2D array based on mouse position
    virtual Tile& getTile(std::pair<int, int> index);

    virtual void draw(); //draws all stored Tiles
    virtual void update(); //window_clear-draw-window_display sequence required by SFML
    virtual void display(Games &game); //acquisition of board data and singular render of contents
    void display2(Games& game); //legacy method used in Crossword display
    virtual void set_selected(std::pair<int, int> index);

protected:
    sf::Vector2f position; //offset of top left corner in relation to top left corner of current window
    double size;
    Tile ** board; //2D array of Tiles
    std::pair<int, int> selected = std::make_pair(-1, -1);

private:
    int elemNum; //number of elements in one side
};
