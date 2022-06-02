#include "Menu.h"
#include <iostream>


Menu::Menu()
{

}

Menu::Menu(float width, float height, std::vector<std::string> info)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}
	sf::Text information;
	int index = 1;
	size_t number_of_items = info.size();

	information.setFont(font);
	information.setFillColor(sf::Color::Red);
	information.setString(info[0]);
	information.setPosition(sf::Vector2f(width / 2, height / (number_of_items + 1) * index));
	index++;
	menu.push_back(information);

	std::vector<std::string>::iterator it = info.begin();
	it++;
	for (; it < info.end(); it++)
	{
		information.setFont(font);
		information.setFillColor(sf::Color::White);
		information.setString(*it);
		information.setPosition(sf::Vector2f(width / 2, height / (number_of_items + 1) * index));
		menu.push_back(information);
		index++;
	}
	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

LoginWindow::~LoginWindow()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	std::vector<sf::Text>::iterator it = menu.begin();
	for (; it < menu.end(); it++)
	{
		window.draw(*it);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	size_t number_of_items = menu.size();
	if (selectedItemIndex + 1 < number_of_items)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::RunMenu(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;

				case sf::Keyboard::Down:
					MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem())
					{
					case 0:
						return 0;
					case 1:
						return 1;
					case 2:
						window.close();
						return 2;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		draw(window);

		window.display();
	}
}

LoginWindow::LoginWindow(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}
	sf::Text information;
	nameInPut = "";

	information.setFont(font);
	information.setFillColor(sf::Color::White);
	information.setString("Confirm");
	information.setPosition(sf::Vector2f(width / 4, height / (1 + 4) * 3));
	menu.push_back(information);
	
	information.setFont(font);
	information.setFillColor(sf::Color::White);
	information.setString("Exit");
	information.setPosition(sf::Vector2f(width / 4, height / (1 + 4) * 4));
	menu.push_back(information);

	information.setFont(font);
	information.setFillColor(sf::Color::White);
	information.setString("Enter the User's name:");
	information.setPosition(sf::Vector2f(width / 2, height / (1 + 4) * 1));
	menu.push_back(information);

	information.setFont(font);
	information.setFillColor(sf::Color::Black);
	information.setString(nameInPut);
	information.setPosition(sf::Vector2f(width / 2, height / (1 + 4) * 2));
	menu.push_back(information);

	nameRect.setPosition(sf::Vector2f(width / 2, height / (1 + 4) * 2));
	nameRect.setSize(sf::Vector2f(150, 50));
	nameRect.setFillColor(sf::Color::White);

	selectedItemIndex = 0;
}

void LoginWindow::draw(sf::RenderWindow& window)
{
	window.draw(nameRect);
	std::vector<sf::Text>::iterator it = menu.begin();
	for (; it < menu.end(); it++)
	{
		window.draw(*it);
	}
}

void LoginWindow::RunMenu(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::TextEntered:
			{
				nameInPut += event.text.unicode;
				menu[3].setString(nameInPut);
			}
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;

				case sf::Keyboard::Down:
					MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem())
					{
					case 0:
						return;
					case 1:
						return;
					case 2:
						window.close();
						return;
					}

					break;
				}

				break;
			
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		draw(window);

		window.display();
	}
}

Game::Game(float width, float height, user player)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}
	sf::Text information;
	this->width = width;
	this->height = height;
	this->player = player;
	for (int i = 0; i < 11; i++)
	{
		information.setFont(font);
		information.setFillColor(sf::Color::White);
		information.setString("abs");
		information.setPosition(sf::Vector2f(40, (i * 30 + 30)));
		menu.push_back(information);
	}
}

Game::~Game()
{
}

void Game::drawGame(sf::RenderWindow& window)
{
	std::vector<sf::Text>::iterator it = menu.begin();
	for (; it < menu.end(); it++)
	{
		window.draw(*it);
	}
}

void Game::update(std::vector<std::string> sudoku)
{
	int i = 0;
	for (;i < 11; i++)
	{
		menu[i].setString(sudoku[i]);
	}
}

void Game::RunGame(sf::RenderWindow& window, user player, Sudoku level)
{
	window.setFramerateLimit(60);
	level.play(player, window);
	std::vector<std::string> des = {};
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	sf::Event event;
	while (window.isOpen())
	{
		des = level.display();
		update(des);

		window.clear();

		drawGame(window);

		window.display();

		while (window.pollEvent(event))
		{
			player.move(event);
			z = player.get_insert(event);
			if (z != 0)
			{
				level.insert(player.get_x(), player.get_y(), z);
				break;
			}		
		}
	}
}
