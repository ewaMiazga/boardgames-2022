#include <iostream>
#include <utility>
#include <ctime>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

#pragma once

class user
{
protected:
	int x;
	int y;
	int points;
	int get_move(sf::Event button);

public:
	user();
	int get_points() { return this->points; }
	void add_point() { this->points++; }
	int get_x() { return this->x; }
	int get_y() { return this->y; }
	bool enter(sf::Event button);
	int get_insert(sf::Event button);
	char get_action();
	void move(sf::Event button);
	std::string read_string();
};

/*class user_account
	:public user
{
protected:
	std::string name;
	time_t current_sesion;
	std::string current_game;
	stats sudoku_stats;
	stats ttc_stats;
	stats crosswords_stats;
public:
	user_account();
	user_account(std::string name, stats sudoku, stats ttc, stats crosswords);
	std::string get_name() { return this->name; }
	void set_name(std::string new_name) { this->name = name; }
	stats get_sudoku_stats() { return this->sudoku_stats; }
	void set_sudoku_stats(stats new_stats) { this->sudoku_stats = new_stats; }
	stats get_ttc_stats() { return this->ttc_stats; }
	void set_ttc_stats(stats new_stats) { this->ttc_stats = new_stats; }
	stats get_crosswords_stats() { return this->crosswords_stats; }
	void set_crosswords_stats(stats new_stats) { this->crosswords_stats = new_stats; }
	time_t get_current_sesion() { return this->current_sesion; }
	void start_game(std::string title);
	time_t stop_game();
	std::string show_my_stats();
};

class premium_user
	:public user_account
{
	premium_user();
	premium_user(std::string name, stats sudoku, stats ttc, stats crosswords);
};

class stats
{
	std::string title;
	time_t total_time;
	int	points;
public:
	stats();
	stats(std::string title);
	stats(std::string title, time_t total_time, int points);
	std::string get_title() { return this->title; }
	time_t get_time() { return this->total_time; }
	void set_title(std::string title) { this->title = title; }
	void set_time(time_t time) { this->total_time = time; }
	int get_points() { return this->points; }
	void set_points(int points) { this->points = points; }
	void add_time(time_t time) { this->total_time += time; }
	void add_points(int points) { this->points += points; }
	friend std::ostream& operator<<(std::ostream& cout, stats& obj)
	{
		cout << obj.get_title() << ' ' << obj.get_points() << ' ' << obj.get_time();
		return cout;
	}
	std::string to_string();
};

class database
{
protected:
	std::vector<user_account> users;
	std::vector<user_account> the_best_users;
	void find_the_best_users();
public:
	database();
	database(std::vector<user_account> users);
	std::vector<user_account> get_users() { return this->users; }
	std::vector<user_account> get_the_best_users() { return this->the_best_users; }
	user_account find_user(std::string name);
	void update_user(user_account act_user);
	void add_user(user_account new_user);
	friend std::ifstream& operator>>(std::ifstream& file, database& obj);
	friend std::ofstream& operator<<(std::ofstream& file, database& obj);
};*/