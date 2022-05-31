/*#include <SFML/Graphics.hpp>
#include "board.h"
#include "tile.h"


Board::Board(
    sf::Vector2f position,
    sf::Color frameColor,
    sf::Color backgroundColor,
    sf::Color displayColor,
    sf::Font &font,
    double size,
    int elemNum
)
{
    this->position = position;
    this->elemNum = elemNum;
    this->board = new Tile* [elemNum];
    for (int i = 0; i < elemNum; i++)
    {
        board[i] = new Tile[elemNum];
    }

    sf::Vector2f newPos = position;

    double tileSize = size / elemNum;
    for (int i = 0; i < elemNum; ++i)
    {
        for (int j = 0; j < elemNum; ++j)
        {
            newPos += sf::Vector2f(tileSize, 0);
            board[i][j] = Tile(
                newPos,
                frameColor,
                backgroundColor,
                displayColor,
                font,
                tileSize,
                true,
                '6'
            );
        }
        newPos += sf::Vector2f(-size, tileSize);
    }
}

Board::~Board()
{
    for (int i = 0; i < elemNum; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Board::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < elemNum; ++i)
    {
        for (int j = 0; j < elemNum; ++j)
        {
            board[i][j].draw(window);
        }
    }
}*/


