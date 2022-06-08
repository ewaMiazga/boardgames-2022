#include "Database.h"


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
	if (users.size() >= 3)
		the_best_users = { users[0], users[1], users[2] };
	//std::vector<user_account>::iterator i = users.begin();
	//std::vector<user_account>::iterator end = users.end();
	//for (; i < end; i++)
	//{

	//}
}

std::vector<std::string> database::the_best_stats()
{
	std::vector<std::string> result;
	result.insert(std::end(result), std::begin(the_best_users[0].show_my_stats()), std::end(the_best_users[0].show_my_stats()));
	result.insert(std::end(result), std::begin(the_best_users[1].show_my_stats()), std::end(the_best_users[1].show_my_stats()));
	result.insert(std::end(result), std::begin(the_best_users[2].show_my_stats()), std::end(the_best_users[2].show_my_stats()));
	return result;
}

void database::find_user(std::string name, user_account& current_user)
{
	current_user.set_name(name);
	for (auto i:users)
	{
		if (i.get_name() == name)
		{
			current_user.set_sudoku_stats(i.get_sudoku_stats());
			current_user.set_ttc_stats(i.get_ttc_stats());
			current_user.set_crosswords_stats(i.get_crosswords_stats());
			return;
		}
	}
	add_user(current_user);
	return;
}

void database::update_user(user_account act_user)
{
    std::vector<user_account> temp = get_users();
	std::vector<user_account>::iterator i = temp.begin();
	std::vector<user_account>::iterator end = temp.end();
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

void update(user_account& current_user, database& obj)
{
	current_user.stop_game();
	obj.update_user(current_user);
	writeToFile("../resources/Database.txt", obj);
}

void readFromFile(std::string fileName, database& obj)
{
	std::ifstream fileHandleOpen(fileName);
	if (!fileHandleOpen)
	{
		std::cerr << "File cannot be open - this path not exist " << std::endl;
	}
	else
	{
		while (!fileHandleOpen.eof())
		{
			fileHandleOpen >> obj;
		}
		fileHandleOpen.close();
	}
}

void writeToFile(std::string fileName, database& obj)
{
	std::ofstream fileHandleOpen(fileName);
	if (!fileHandleOpen)
	{
		std::cerr << "File cannot be open - this path not exist " << std::endl;
	}
	else
	{
		fileHandleOpen << obj;
		fileHandleOpen.close();
	}
}

std::istream& operator>>(std::istream& CIN, database& obj)
{
	
	std::string name;
	std::string title;
	std::string points;
	std::string time;
	std::string clueInfo;
	std::getline(CIN, name);
	std::getline(CIN, title);
	std::getline(CIN, points);
	std::getline(CIN, time);
	stats Sudoku(title, std::stoi(time), std::stoi(points));
	std::getline(CIN, title);
	std::getline(CIN, points);
	std::getline(CIN, time);
	stats TTC(title, std::stoi(time), std::stoi(points));
	std::getline(CIN, title);
	std::getline(CIN, points);
	std::getline(CIN, time);
	stats CR(title, std::stoi(time), std::stoi(points));

	user_account new_user(name, Sudoku, TTC, CR);
	obj.users.push_back(new_user);
	return CIN;
}

std::ostream& operator<<(std::ostream& file, database& obj)
{
	for (int i=0; i < obj.get_users().size(); i++)
	{
		file << obj.get_users()[i].get_name() << std::endl;
		file << "Sudoku" << std::endl;
		file << obj.get_users()[i].get_sudoku_stats().get_points() << std::endl;
		file << obj.get_users()[i].get_sudoku_stats().get_time() << std::endl;
		file << "Tic Tac Toe" << std::endl;
		file << obj.get_users()[i].get_ttc_stats().get_points() << std::endl;
		file << obj.get_users()[i].get_ttc_stats().get_time() << std::endl;
		file << "Crosswords" << std::endl;
		file << obj.get_users()[i].get_crosswords_stats().get_points() << std::endl;
		file << obj.get_users()[i].get_crosswords_stats().get_time() << std::endl;
	}
	return file;
}