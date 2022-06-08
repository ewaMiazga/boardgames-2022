#pragma once
#include <vector>
#include "User.h"
#include "Stats.h"
#include <fstream>
#include <string>
#include <iostream>

class database
{
protected:
	std::vector<user_account> users;
	std::vector<user_account> the_best_users;
public:
	database();
	
	explicit database(std::vector<user_account> users);
	
	std::vector<user_account> get_users() { return users; }
	
	std::vector<user_account> get_the_best_users() { return the_best_users; }
	
	user_account find_user(std::string name);
	
	void update_user(user_account act_user);
	
	void add_user(user_account new_user);
	
	void find_the_best_users();

	std::vector<std::string> the_best_stats();

	friend void read_from_file(std::string path, database& obj);

	friend void write_to_file(std::string path, database& obj);

	friend std::ifstream& operator>>(std::ifstream& file, database& obj);
	
	friend std::ofstream& operator<<(std::ofstream& file, database& obj);
};