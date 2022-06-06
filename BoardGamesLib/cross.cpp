//#include <SFML/Graphics.hpp>
//#include "cross.h"
//#include "tile.h"
//
//Cross::Cross(
//        sf::Vector2f position,
//        sf::Color frameColor,
//        sf::Color backgroundColor,
//        sf::Color displayColor,
//        sf::Font &font,
//        int width,
//        int height,
//        int xSpan,
//        int ySpan,
//        sf::RenderWindow &window
//) : m_window(window), Board()
//{
//    this->position = position;
//    this->xSpan = xSpan;
//    this->ySpan = ySpan;
//    this->width = width;
//    this->height = height;
//    this->board = new Tile* [ySpan];
//    for (int i = 0; i < ySpan; i++)
//    {
//        board[i] = new Tile[xSpan];
//    }
//
//    sf::Vector2f newPos = position;
//
//    double tileSize = size/std::max(xSpan, ySpan);
//    for (int i = 0; i < ySpan; ++i)
//    {
//        for (int j = 0; j < xSpan; ++j)
//        {
//            board[i][j] = Tile(
//                    newPos,
//                    frameColor,
//                    backgroundColor,
//                    displayColor,
//                    font,
//                    tileSize,
//                    true
//            );
//            newPos += sf::Vector2f(tileSize, 0);
//        }
//        newPos += sf::Vector2f(-size, tileSize);
//    }
//}
//
//Cross::~Cross()
//{
//    for (int i = 0; i < ySpan; i++)
//    {
//        delete[] board[i];
//    }
//    delete[] board;
//}
//
//void Cross::draw()
//{
//    for (int i = 0; i < ySpan; ++i)
//    {
//        for (int j = 0; j < xSpan; ++j)
//        {
//            if(board[j][i].isVisible())
//            {
//                board[j][i].draw(m_window);
//            }
//        }
//    }
//}
//
//
