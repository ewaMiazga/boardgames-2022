#include <SFML/Graphics.hpp>
#include "game.h"

SudokuWindow::SudokuWindow(double height, double width)
{
	this->height = height;
	this->width = width;
	font = new sf::Font;
	if (!font->loadFromFile("../resources/fonts/Qarolina.ttf"))
	{
		std::cout << "error loading the file";
		system("pause");
	}
	sf::Font bont = *font;

	gameBoard = Board(
		sf::Vector2f(0, 0),
		sf::Color::Black,
		sf::Color::White,
		sf::Color::Black,
		bont,
		std::max(height, width),
		9
	);
}


void SudokuWindow::draw(sf::RenderWindow& window)
{
	gameBoard.draw(window);
}

SudokuWindow::~SudokuWindow()
{
	delete font;
}

void SudokuWindow::play()
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
					gameBoard.getTile(
						sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Red);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					gameBoard.getTile(
						sf::Mouse::getPosition(window), window).setOutlineColor(sf::Color::Black);
				}

				//board.update(); ?
				break;

			default:
				break;
			}
		}
		window.clear(sf::Color::White);
		gameBoard.draw(window);
		window.display();
	}

}

void SudokuWindow::setup()
{
	window.create(sf::VideoMode(height, width), "Sudoku");
}
