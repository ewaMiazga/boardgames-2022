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
        int elemNum,
        sf::RenderWindow &window
) : m_window(window)
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
                    true
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

void Board::set_selected(std::pair<int, int> index)
{
    if(selected.first != -1)
        getTile(selected).setOutlineColor(sf::Color::Black);
    selected = index;
    getTile(selected).setOutlineColor(sf::Color::Red);
}

void Board::draw()
{
    for (int i = 0; i < elemNum; ++i)
    {
        for (int j = 0; j < elemNum; ++j)
        {
            if(board[j][i].isVisible())
            {
                board[j][i].draw(m_window);
            }
        }
    }
}

std::pair<int, int> Board::getIndex(sf::Vector2i pos)
{
    sf::Vector2f mousePos = m_window.mapPixelToCoords(pos);
    mousePos -= position;
    int column = mousePos.y / (size / elemNum);
    int row = mousePos.x / (size / elemNum);
    return std::pair<int, int>(column, row);
}

Tile& Board::getTile(std::pair<int, int> index)
{
    int &column = index.first;
    int &row = index.second;
    return board[column][row];
}

void Board::display(Games& game)
{
    for (int i = 0; i < elemNum; ++i)
    {
        for (int j = 0; j < elemNum; ++j)
        {
            board[j][i].setValue(game.getValue(j, i));
        }
    }
    
    if (game.gameOver())
    {
        //end screen should be called
        m_window.close();
    }
    
    update();
}


void Board::update()
{
    m_window.clear(sf::Color::White);
    draw();
    m_window.display();
}

