#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../BoardGamesLib/board.h"
#include "../BoardGamesLib/App.h"

int main()
{
		sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
		user_account current_user("new_user");
		database users;
		std::string new_info = "What do you want to do";

		sf::Font font;
		
		if (!font.loadFromFile("../resources/fonts/Qarolina.ttf"))
		{
			std::cout << "error loading the file";
			system("pause");
		}
		
		App aplication(font, window);
	
		std::vector<std::string> start_info = { "BOARD GAMES!!!" };
		std::vector<std::string> start_opt = { "Quick Game", "Load User", "Exit" };
		DecisionMenu start(900, 900, start_info, start_opt);

		std::vector<std::string> load_info = { "Enter user's name" };
		std::vector<std::string> load_opt = { "Confirm", "Exit" };
		LoginWindow load(900, 900, load_info, load_opt);

		std::vector<std::string> game_info = { "What do you want to do" };
		std::vector<std::string> game_opt = { "Sudoku", "Tic Tac Toe", "Crosswords", "Stats", "Exit" };
		DecisionMenu game(900, 900, game_info, game_opt);

		std::vector<std::string> stats_info = { "Stats" };
		Menu stats(900, 900, stats_info);

		std::vector<std::string> lvls_info = { "Chose level of game" };
		std::vector<std::string> lvls = { "Easy", "Medium", "Hard"};
		DecisionMenu chose_lvl(900, 900, lvls_info, lvls);
		
		std::vector<std::string> info = { "You Win!", "Press Esc to come back to menu" };
		Menu result_info(900, 900, info);
		

		int result = 0;
		bool go_next = true;
		result = start.RunMenu(window);
		while (window.isOpen())
		{
			if (result == -2)
				result = start.RunMenu(window);
			switch (result)
			{
			case 0:
			
				new_info = "What do you want to do " + current_user.get_name() + "?";
				game.set_info(0, new_info);
				result = game.RunMenu(window);
				switch (result)
				{
				case 0:
					result = chose_lvl.RunMenu(window);
					switch (result)
					{
					case 0:
						aplication.PlaySudoku(current_user, "easy");
						result = 0;
						break;
					case 1:
						aplication.PlaySudoku(current_user, "medium");
						result = 0;
						break;
					case 2:
						aplication.PlaySudoku(current_user, "hard");
						result = 0;
						break;
					case -1:
						result = 0;
						break;
					}
					break;
				case 1:
					result = chose_lvl.RunMenu(window);
					switch (result)
					{
					case 0:
						aplication.PlayTTC(current_user, "easy");
						result = 0;
						break;
					case 1:
						aplication.PlayTTC(current_user, "medium");
						result = 0;
						break;
					case 2:
						aplication.PlayTTC(current_user, "hard");
						result = 0;
						break;
					case -1:
						result = 0;
						break;
					}
					result = 0;
					break;
				case 2:
					aplication.PlayCrosswords(current_user);
					break;
				case 3:
					stats.reupload_info(current_user.show_my_stats());
					result = stats.RunMenu(window);
					result = 0;
					break;
				case 4:
					window.close();
					break;
				case -1:
					result = -2;
					break;
				}
				if (result == -1)
				{
					result = 0;
					break;
				}
				break;
			case 1:
				result = load.RunMenu(window);
				switch (result)
				{
				case 0:
					current_user = users.find_user(load.getInPut());
					new_info = "What do you want to do " + current_user.get_name() + "?";
					game.set_info(0, new_info);
					result = 0;
					break;
				case 1:
					window.close();
					break;
				case -1:
					result = -2;
					break;
				}
				break;
			case 2:
				window.close();
				break;
			case -1:
				result = -2;
				break;
			}
		}
		return 0;
}
