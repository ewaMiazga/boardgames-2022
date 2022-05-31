#include <SFML/Graphics.hpp>
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
    this->size = size;
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
            newPos += sf::Vector2f(tileSize, 0);
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
            board[j][i].draw(window);
        }
    }
}

Tile& Board::getTile(sf::Vector2i pos, sf::RenderWindow& window)
{
    //pos -= sf::Vector2i(position);
    sf::Vector2f mousePos = window.mapPixelToCoords(pos);
    mousePos -= position;
    std::cout << "size: " << size << std::endl;
    std::cout << "elemNum: " << elemNum << std::endl;
    unsigned int column = mousePos.y / (size / elemNum);
    unsigned int row = mousePos.x / (size / elemNum);
    std::cout << "column: " << column << std::endl;
    std::cout << "row: " << row << std::endl;
    std::cout << "pos.x: " << pos.x << std::endl;
    std::cout << "pos.y: " << pos.y << std::endl << std::endl;
    return board[column][row];
}
