// User.cpp : Definiuje funkcje biblioteki statycznej.
//

#include "User.h"
#include <SFML/System.hpp>
#include<SFML/Window.hpp>
#include <stdexcept>
#include <string>
#include <fstream>


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

/*user_account::user_account()
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

user_account::user_account(std::string name, stats sudoku, stats ttc, stats crosswords)
{
	this->x = 0;
	this->y = 0;
	this->points = 0;
	this->current_sesion = 0;
	this->current_game = nullptr;
	this->name = name;
	this->sudoku_stats = sudoku;
	this->ttc_stats = ttc;
	this->crosswords_stats = crosswords;
}

void user_account::start_game(std::string title)
{
	this->current_game = title;
	time(&current_sesion);
}

time_t user_account::stop_game()
{
	time_t stop, add_time;
	add_time = time(&stop) - this->get_current_sesion();
	if (current_game == "Sudoku")
	{
		this->get_sudoku_stats().add_points(this->get_points());
		this->get_sudoku_stats().add_time(add_time);
	}

	if (current_game == "TicTacToe")
	{
		this->get_ttc_stats().add_points(this->get_points());
		this->get_ttc_stats().add_time(add_time);
	}

	if (current_game == "Crosswords")
	{
		this->get_crosswords_stats().add_points(this->get_points());
		this->get_crosswords_stats().add_time(add_time);
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



// STATS
std::string stats::to_string()
{
	std::string str_rep = this->get_title();
	str_rep += " ";
	str_rep += std::to_string(this->get_points());
	str_rep += " ";
	str_rep += std::to_string(this->get_time());
	str_rep += "\n";
	return str_rep;
}

// DATABASE
database::database()
{
	users = {};
	the_best_users = {};
}

database::database(std::vector<user_account> users)
{
	this->users = users;
	the_best_users = {};
}

void database::find_the_best_users()
{
	std::vector<user_account>::iterator i = this->get_users().begin();
	std::vector<user_account>::iterator end = this->get_users().end();

}

user_account database::find_user(std::string name)
{
	std::vector<user_account>::iterator i = this->get_users().begin();
	std::vector<user_account>::iterator end = this->get_users().end();
	for (; i < end; i++)
	{
		if ((*i).get_name() == name)
			return (*i);
	}
	user new_user(name);
	add_user(new_user);
	return new_user;
}

void database::update_user(user_account act_user)
{
	std::vector<user_account>::iterator i = this->get_users().begin();
	std::vector<user_account>::iterator end = this->get_users().end();
	for (; i < end; i++)
	{
		if ((*i).get_name() == act_user.get_name())
			(*i) = act_user;
	}
}

void database::add_user(user_account new_user)
{
	this->users.push_back(new_user);
}

std::ifstream& operator>>(std::ifstream& file, database& obj)
{
	std::string line;
	int n = 1;
	user_account next;
	stats new_stats;
	while (std::getline(file, line))
	{
		if (n == 11)
		{
			n = 1;
			obj.users.push_back(next);
		}
		switch (n)
		{
		case 1:
		{
			next.set_name(line);
			n++;
		}
		case 2:
		{
			std::string title = line;
			new_stats.set_title(title);
			std::getline(file, line);
			int points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			int time = std::stoi(line);
			new_stats.set_time(time);
			next.set_sudoku_stats(new_stats);
			n += 3;
		}
		case 5:
		{
			std::string title = line;
			new_stats.set_title(title);
			std::getline(file, line);
			int points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			int time = std::stoi(line);
			new_stats.set_time(time);
			next.set_ttc_stats(new_stats);
			n += 3;
		}
		case 8:
		{
			std::string title = line;
			new_stats.set_title(title);
			std::getline(file, line);
			int points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			int time = std::stoi(line);
			new_stats.set_time(time);
			next.set_crosswords_stats(new_stats);
			n += 3;
		}
		}
	}
}

std::ofstream& operator<<(std::ofstream& file, database& obj)
{
	std::vector<user_account>::iterator i = obj.get_users().begin();
	std::vector<user_account>::iterator end = obj.get_users().end();
	for (; i < end; i++)
	{
		file << (*i).get_name() << "\n";
		file << (*i).get_sudoku_stats().get_title() << "\n";
		file << (*i).get_sudoku_stats().get_points() << "\n";
		file << (*i).get_sudoku_stats().get_time() << "\n";
		file << (*i).get_ttc_stats().get_title() << "\n";
		file << (*i).get_ttc_stats().get_points() << "\n";
		file << (*i).get_ttc_stats().get_time() << "\n";
		file << (*i).get_crosswords_stats().get_title() << "\n";
		file << (*i).get_crosswords_stats().get_points() << "\n";
		file << (*i).get_crosswords_stats().get_time() << "\n";
	}
	return file;
}*/
