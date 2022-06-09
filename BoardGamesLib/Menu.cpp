#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// -------------------------------------------------- Bartlomiej Niewiarowski ----------------------------------------------------------
// MENU
Menu::Menu(float width, float height, std::vector<std::string> info)
{
	if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
	{
	}
	fill_info(width, height, info, info.size());
	this->width = width;
	this->height = height;
}

void Menu::fill_info(float width, float height, std::vector<std::string> info, size_t sum)
{
	sf::Text information;
	int index = 1;
	float x;

	std::vector<std::string>::iterator it = info.begin();
	for (; it < info.end(); it++)
	{
		x = width / 2 - ((*it).length() * 10);
		information.setFont(font);
		information.setFillColor(sf::Color::White);
		information.setString(*it);
		information.setPosition(sf::Vector2f(x, height / (sum + 1) * index));
		text.push_back(information);
		index++;
	}
}

void Menu::set_info(int index, std::string info)
{
	float x = width / 2 - (info.length() * 10);
	this->text[index].setString(info);
	this->text[index].setPosition(sf::Vector2f(x, height / (5 + 1)));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	std::vector<sf::Text>::iterator it = text.begin();
	for (; it < text.end(); it++)
	{
		window.draw(*it);
	}
}

int Menu::RunMenu(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					return 0;
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

// DecisionMenu
DecisionMenu::DecisionMenu(float width, float height, std::vector<std::string> info, std::vector<std::string> options)
{
	size_t string_sum = info.size() + options.size();

	if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
	{
	}
	fill_info(width, height, info, string_sum);

	fill_options(width, height, options, string_sum);

	selectedItemIndex = 0;

	this->width = width;
	this->height = height;
}

void DecisionMenu::fill_options(float width, float height, std::vector<std::string> options, size_t sum)
{
	sf::Text information;
	int index = sum - options.size() + 1;
	float x;

	std::vector<std::string>::iterator it = options.begin();
	for (; it < options.end(); it++)
	{
		x = width / 2 - ((*it).length() * 10);
		information.setFont(font);
		information.setFillColor(sf::Color::White);
		information.setString(*it);
		information.setPosition(sf::Vector2f(x, height / (sum + 1) * index));
		this->options.push_back(information);
		index++;
	}
	this->options[0].setFillColor(sf::Color::Red);
}

void DecisionMenu::draw(sf::RenderWindow& window)
{
	std::vector<sf::Text>::iterator it = text.begin();
	for (; it < text.end(); it++)
	{
		window.draw(*it);
	}

	it = options.begin();
	for (; it < options.end(); it++)
	{
		window.draw(*it);
	}
}

void DecisionMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		options[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		options[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void DecisionMenu::MoveDown()
{
	size_t number_of_items = options.size();
	if (selectedItemIndex + 1 < number_of_items)
	{
		options[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		options[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int DecisionMenu::RunMenu(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.isOpen())
	{
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
					return GetPressedItem();

				case sf::Keyboard::Escape:
					return -1;
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

//Login Menu
LoginWindow::LoginWindow(float width, float height, std::vector<std::string> info, std::vector<std::string> options)
{
	if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
	{
		// handle error
	}
	size_t sum = info.size() + options.size();
	sf::Text information;

	fill_info(width, height, info, sum + 1);

	Name.setFont(font);
	Name.setFillColor(sf::Color::Black);
	Name.setString(nameInPut);
	Name.setPosition(sf::Vector2f(width / 2 - width / 8, height / (sum + 1) * (info.size() + 1)));

	nameRect.setPosition(sf::Vector2f(width / 2 - width / 8, height / (sum + 1) * (info.size() + 1)));
	nameRect.setSize(sf::Vector2f(width / 4, height / 18));
	nameRect.setFillColor(sf::Color::White);

	fill_options(width, height, options, sum + 1);

	selectedItemIndex = 0;

	this->width = width;
	this->height = height;
}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::draw(sf::RenderWindow& window)
{
	window.draw(nameRect);
	std::vector<sf::Text>::iterator it = text.begin();
	for (; it < text.end(); it++)
	{
		window.draw(*it);
	}

	it = options.begin();
	for (; it < options.end(); it++)
	{
		window.draw(*it);
	}

	window.draw(Name);
}

int LoginWindow::RunMenu(sf::RenderWindow& window)
{
	name = "";
	nameInPut = "";
	Name.setString("");
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::TextEntered:
			{
				if (event.text.unicode != 2386)
				{
					name += event.text.unicode;
					nameInPut += event.text.unicode;
					Name.setString(nameInPut);
				}
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
						return 0;
					case 1:
						return 1;
					case 2:
						window.close();
						return 2;
					}
				case sf::Keyboard::Escape:
					return -1;
					break;

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


void Menu::reupload_info(std::vector<std::string> info)
{
    text = {};
    fill_info(width, height, info, info.size());
}