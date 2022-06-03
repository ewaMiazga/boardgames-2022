#include "Database.h"
#include <vector>
#include "User.h"

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
	user_account new_user(name);
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

/*std::ifstream& operator>>(std::ifstream& file, database& obj)
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