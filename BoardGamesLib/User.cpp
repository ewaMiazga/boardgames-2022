// User.cpp : Definiuje funkcje biblioteki statycznej.
//

#include <SFML/System.hpp>
#include <stdexcept>
#include <string>
#include <fstream>
#include "User.h"
#include "Stats.h"

int user::get_move(sf::Event button)
{
	switch (button.key.code)
	{
	case sf::Keyboard::Up:
		return 1;
	case sf::Keyboard::Down:
		return 2;
	case sf::Keyboard::Right:
		return 3;
	case sf::Keyboard::Left:
		return 4;
	}
	return 5;
}

// USER
user::user()
{
	this->x = 0;
	this->y = 0;
	this->points = 0;
}

void user::move(sf::Event button)
{
	int res = get_move(button);
	switch (res)
	{
	case 1:
		if (y > 0)
		{
			this->y -= 1;
			return;
		}
		else
			throw std::invalid_argument("A");
	case 2:
		if (y < 9)
		{
			this->y += 1;
			return;
		}
		else
			throw std::invalid_argument("A");
	case 3:
		if (x < 9)
		{
			this->x += 1;
			return;
		}
		else
			throw std::invalid_argument("A");
	case 4:
		if (x > 0)
		{
			this->x -= 1;
			return;
		}
		else
			throw std::invalid_argument("A");
	}
}

bool user::enter(sf::Event button)
{
	if (button.key.code == sf::Keyboard::Enter)
		return true;
	else
		return false;
}

int user::get_insert(sf::Event button)
{
	if (button.key.code == sf::Keyboard::Num0)
		return 0;
	if (button.key.code == sf::Keyboard::Num1)
		return 1;
	if (button.key.code == sf::Keyboard::Num2)
		return 2;
	if (button.key.code == sf::Keyboard::Num2)
		return 3;
	if (button.key.code == sf::Keyboard::Num2)
		return 4;
	if (button.key.code == sf::Keyboard::Num2)
		return 5;
	if (button.key.code == sf::Keyboard::Num2)
		return 6;
	if (button.key.code == sf::Keyboard::Num2)
		return 7;
	if (button.key.code == sf::Keyboard::Num2)
		return 8;
	if (button.key.code == sf::Keyboard::Num2)
		return 9;
	else
		return 0;
}

// Proponuje kilka funkcji aktywowanych klawszami
// W tym U - ustawienia / sterowanie 
char user::get_action()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return 'S';
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		return 'N';
}

std::string user::read_string()
{
	std::string input;
	std::cin >> input;
	return input;
}

// USER ACCOUNT

user_account::user_account()
{
	this->x = 0;
	this->y = 0;
	this->points = 0;
	this->current_sesion = 0;
	stats Sudoku("Sudoku"), TicTacToe("TicTacToe"), Crosswords("Crosswords");
	this->sudoku_stats = Sudoku;
	this->ttc_stats = TicTacToe;
	this->crosswords_stats = Crosswords;
}

user_account::user_account(std::string name)
{
	this->x = 0;
	this->y = 0;
	this->points = 0;
	this->current_sesion = 0;
	this->name = name;
	stats Sudoku("Sudoku"), TicTacToe("TicTacToe"), Crosswords("Crosswords");
	this->sudoku_stats = Sudoku;
	this->ttc_stats = TicTacToe;
	this->crosswords_stats = Crosswords;
}

user_account::user_account(std::string name, stats sudoku, stats ttc, stats crosswords)
{
	x = 0;
	y = 0;
	points = 0;
	current_sesion = 0;
	current_game = nullptr;
	this->name = name;
	sudoku_stats = sudoku;
	ttc_stats = ttc;
	crosswords_stats = crosswords;
}

void user_account::start_game(std::string title)
{
	this->current_game = title;
	time(&current_sesion);
}

void user_account::stop_game()
{
	time_t stop, add_time;
	add_time = time(&stop) - this->get_current_sesion();
	if (current_game == "Sudoku")
	{
		sudoku_stats.add_points(this->get_points());
		sudoku_stats.add_time(add_time);
	}

	if (current_game == "TicTacToe")
	{
		ttc_stats.add_points(this->get_points());
		ttc_stats.add_time(add_time);
	}

	if (current_game == "Crosswords")
	{
		crosswords_stats.add_points(this->get_points());
		crosswords_stats.add_time(add_time);
	}
	current_sesion = 0;
	current_game = nullptr;
	points = 0;
}

std::string user_account::show_my_stats()
{
	std::string str_rep;
	str_rep += sudoku_stats.to_string();
	str_rep += ttc_stats.to_string();
	str_rep += crosswords_stats.to_string();
}

// Premium user

