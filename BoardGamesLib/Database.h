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
	
	void find_user(std::string name, user_account& current_user);
	
	void update_user(user_account act_user);
	
	void add_user(user_account new_user);
	
	void find_the_best_users();

	std::vector<std::string> the_best_stats();
	
	friend void update(user_account& current_user, database& obj);

	friend void readFromFile(std::string fileName, database& obj);
	
	friend void writeToFile(std::string fileName, database& obj);

	friend std::istream& operator>>(std::istream& CIN, database& obj);
	
	friend std::ostream& operator<<(std::ostream& file, database& obj);
};