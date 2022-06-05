#pragma once
#include <vector>
#include "User.h"

class database
{
protected:
	std::vector<user_account> users;
	std::vector<user_account> the_best_users;
public:
	database();
	
	database(std::vector<user_account> users);
	
	std::vector<user_account> get_users() { return this->users; }
	
	std::vector<user_account> get_the_best_users() { return this->the_best_users; }
	
	user_account find_user(std::string name);
	
	void update_user(user_account act_user);
	
	void add_user(user_account new_user);
	
	void find_the_best_users();

	friend std::ifstream& operator>>(std::ifstream& file, database& obj);
	
	friend std::ofstream& operator<<(std::ofstream& file, database& obj);
};