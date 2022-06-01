#include <SFML/Graphics.hpp>
#include "game.h"

SudokuWindow::SudokuWindow(double height, double width, sf::Font &font)
{
	gameBoard = Board(
		sf::Vector2f(0, 0),
		sf::Color::Black,
		sf::Color::White,
		sf::Color::Black,
		font,
		std::min(height, width),
		9
	);
}


void SudokuWindow::draw(sf::RenderWindow& window)
{
	gameBoard.draw(window);
}


void SudokuWindow::play(sf::RenderWindow &window)
{
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (unsigned int key = -1;  e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				//User.getKey(e.key.code);
				//send to Game? Game sends back if valid?
				//board.update();
				break;

			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					gameBoard.getTile(sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Red);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					gameBoard.getTile(sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Black);
				}

				//board.update(); ?
				break;

			default:
				break;
			}
		}
		window.clear(sf::Color::White);
		draw(window);
		window.display();
	}

}
