#pragma once
#include "User.h"
#include "board.h"
#include "TicTacToe.h"
#include "Sudoku.h"
#include "Crossword.h"
#include "Menu.h"
#include "Database.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class App
{
public:
	explicit App(sf::Font& font, sf::RenderWindow& window);

	~App() = default;

	//void RunApp(sf::RenderWindow& window);

	void RunStartMenu();

	void QuickGame();

	void LoadUser();

	void UserGame(user_account &current_user);

	void PlaySudoku(user &current_user);

	void PlayTTC(user &current_user);

	void PlayCrosswords(user &current_user);

	int get_sudoku_input();

	std::string get_crosswords_input();

	int move(user& current_user);

private:
	DecisionMenu start_window;

	LoginWindow load_window;

	DecisionMenu game_window;

	Menu sudoku_window;

	Menu ttc_window;

	Menu crosswords_window;

	Menu stats_window;

	database users;

	int result;

	sf::Font& font;

	sf::RenderWindow& window;
};