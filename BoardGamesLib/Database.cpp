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

user_account database::find_user(std::string name)
{
    std::vector<user_account> temp = get_users();
	std::vector<user_account>::iterator i = temp.begin();
	std::vector<user_account>::iterator end = temp.end();
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
	write_to_file("Database.txt", obj);
}

void read_from_file(std::string path, database& obj)
{
	std::ifstream plik;
	plik.open(path);
	if (plik)
	{
		plik >> obj;
	}
	plik.close();
}

void write_to_file(std::string path, database& obj)
{
	std::ofstream plik;
	plik.open(path);
	if (plik)
	{
		plik << obj;
	}
	plik.close();
}

std::ifstream& operator>>(std::ifstream& file, database& obj)
{
	std::string line;
	int n = 1;
	user_account next;
	stats new_stats;
	std::string title;
	int points, time;

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
			next.set_name(line);
			n++;
			break;
		case 2:
			new_stats.set_title(title);
			std::getline(file, line);
			points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			time = std::stoi(line);
			new_stats.set_time(time);
			next.set_sudoku_stats(new_stats);
			n += 3;
			break;
		case 5:
			title = line;
			new_stats.set_title(title);
			std::getline(file, line);
			 points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			time = std::stoi(line);
			new_stats.set_time(time);
			next.set_ttc_stats(new_stats);
			n += 3;
			break;
		case 8:
			title = line;
			new_stats.set_title(title);
			std::getline(file, line);
			points = std::stoi(line);
			new_stats.set_points(points);
			std::getline(file, line);
			time = std::stoi(line);
			new_stats.set_time(time);
			next.set_crosswords_stats(new_stats);
			n += 3;
			break;
		}
	}
	return file;
}

std::ofstream& operator<<(std::ofstream& file, database& obj)
{
	std::string line;
	for (int i=0; i < obj.get_users().size(); i++)
	{
		file << obj.get_users()[i].get_name();
		file << "Sudoku" << "\n";
		file << obj.get_users()[i].get_sudoku_stats().get_points() << "\n";
		file << obj.get_users()[i].get_sudoku_stats().get_time() << "\n";
		file << "Tic Tac Toe" << "\n";
		file << obj.get_users()[i].get_ttc_stats().get_points() << "\n";
		file << obj.get_users()[i].get_ttc_stats().get_time() << "\n";
		file << "Crosswords" << "\n";
		file << obj.get_users()[i].get_crosswords_stats().get_points() << "\n";
		file << obj.get_users()[i].get_crosswords_stats().get_time() << "\n";
	}
	return file;
}