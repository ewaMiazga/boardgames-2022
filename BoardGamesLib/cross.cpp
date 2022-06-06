#include <SFML/Graphics.hpp>
#include "cross.h"
#include "tile.h"

Cross::Cross(
        sf::Vector2f position,
        sf::Color frameColor,
        sf::Color backgroundColor,
        sf::Color displayColor,
        sf::Font &font,
        int width,
        int height,
        int xSpan,
        int ySpan,
        sf::RenderWindow &window
) : m_window(window)
{
    this->position = position;
    this->xSpan = xSpan;
    this->ySpan = ySpan;
    this->width = width;
    this->height = height;
    this->board = new Tile* [ySpan];
    for (int i = 0; i < ySpan; i++)
    {
        board[i] = new Tile[xSpan];
    }

    sf::Vector2f newPos = position;

    double tileSize = size / std::min;
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

void Board::display(TicTacToe &game)
{
    m_window.setActive(true);

    while (m_window.isOpen())
    {
        sf::sleep(sf::milliseconds(100));
        sf::Event e;

        while (m_window.pollEvent(e)) {
            switch (unsigned int key = -1;  e.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        std::pair<int, int> index(getIndex(sf::Mouse::getPosition(m_window)));
                        getTile(index).setOutlineColor(sf::Color::Red);
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    {
                        std::pair<int, int> index(getIndex(sf::Mouse::getPosition(m_window)));
                        getTile(index).setOutlineColor(sf::Color::Black);
                    }
                default:
                    break;
            }
        }
        for (int i = 0; i < elemNum; ++i)
        {
            for (int j = 0; j < elemNum; ++j)
            {
                board[j][i].setValue(game.getValue(j, i));
            }
        }

        if(game.gameOver())
        {
            //end screen should be called
            m_window.close();
        }
        update();
    }
}

void Board::display(Sudoku &game)
{
    m_window.setActive(true);

    while (m_window.isOpen())
    {
        sf::sleep(sf::milliseconds(100));
        sf::Event e;

        while (m_window.pollEvent(e)) {
            switch (unsigned int key = -1;  e.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        std::pair<int, int> index(getIndex(sf::Mouse::getPosition(m_window)));
                        getTile(index).setOutlineColor(sf::Color::Red);
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    {
                        std::pair<int, int> index(getIndex(sf::Mouse::getPosition(m_window)));
                        getTile(index).setOutlineColor(sf::Color::Black);
                    }
                default:
                    break;
            }
        }
        for (int i = 0; i < elemNum; ++i)
        {
            for (int j = 0; j < elemNum; ++j)
            {
                board[j][i].setValue(game.getValue(j, i));
            }
        }

        if(game.gameOver())
        {
            //end screen should be called
            m_window.close();
        }
        update();
    }
}

void Board::update()
{
    m_window.clear(sf::Color::White);
    draw();
    m_window.display();
}

