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

void Board::draw()
{
    for (int i = 0; i < elemNum; ++i)
    {
        for (int j = 0; j < elemNum; ++j)
        {
            board[j][i].draw(m_window);
        }
    }
}

Tile& Board::getTile(std::pair<int, int> index)
{
    //sf::Vector2i pos, sf::RenderWindow& window
//    sf::Vector2f mousePos = window.mapPixelToCoords(pos);
//    mousePos -= position;
//    unsigned int column = mousePos.y / (size / elemNum);
//    unsigned int row = mousePos.x / (size / elemNum);
      int &column = index.first;
      int &row = index.second;
      return board[column][row];
}

void Board::display()
{
    while (m_window.isOpen())
    {
        sf::Event e;
        while (m_window.pollEvent(e))
        {
            switch (unsigned int key = -1;  e.type)
            {
                case sf::Event::Closed:
                    m_window.close();
                    break;

                default:
                    break;
            }
        }
        m_window.clear(sf::Color::White);
        draw();
        m_window.display();
        sf::sleep(sf::milliseconds(100));
    }
}
void Board::update()
{
    m_window.clear(sf::Color::White);
    draw();
    m_window.display();
}
