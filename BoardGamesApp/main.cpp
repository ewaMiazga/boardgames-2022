#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../BoardGamesLib/User.h"
#include "../BoardGamesLib/board.h"
#include "../BoardGamesLib/tile.h"
#include "../BoardGamesLib/TicTacToe.h"
#include "../BoardGamesLib/Sudoku.h"
#include "../BoardGamesLib/Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Sudoku");
    std::vector<std::string> start_info = { "BOARD GAMES!!!"};
    std::vector<std::string> start_opt = { "Quick Game", "Load User", "Exit" };
    DecisionMenu start(900, 900, start_info, start_opt);

    std::vector<std::string> load_info = { "Enter user's name" };
    std::vector<std::string> load_opt = { "Confirm", "Exit"};
    LoginWindow load(900, 900, load_info, load_opt);

    std::vector<std::string> game_info = { "What do you want to do?" };
    std::vector<std::string> game_opt = { "Sudoku", "Tic Tac Toe", "Crosswords", "Stats", "Exit"};
    DecisionMenu game(900, 900, game_info, game_opt);

    std::vector<std::string> sudoku_info = { "Sudoku" };
    Menu sudoku(900, 900, sudoku_info);

    std::vector<std::string> ttc_info = { "Tic Tac Toe" };
    Menu ttc(900, 900, ttc_info);

    std::vector<std::string> crosswords_info = { "Sudoku" };
    Menu cr(900, 900, crosswords_info);

    std::vector<std::string> stats_info = { "Stats" };
    Menu stats(900, 900, sudoku_info);

    std::vector<Menu> windows = { start, load, game, sudoku, ttc, cr, stats };

	user 

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
		{
			result = game.RunMenu(window);
			switch (result)
			{
			case 0:
				result = sudoku.RunMenu(window);
				break;
			case 1:
				result = ttc.RunMenu(window);
				break;
			case 2:
				result = cr.RunMenu(window);
				break;
			case 3:
				result = stats.RunMenu(window);
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
		}
		case 1:
			result = load.RunMenu(window);
			switch (result)
			{
			case 0:
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
			
		case -1:
			result = -2;
		}
	}

	//result = game.RunMenu(window);

	/*while (window.isOpen())
	{
		switch (result)
		{
		case 0:
			result = sudoku.RunMenu(window);
			std::cout << result << std::endl;
		case 1:
			result = ttc.RunMenu(window);
			std::cout << result << std::endl;
		case 2:
			result = cr.RunMenu(window);
			std::cout << result << std::endl;
		case 3:
			result = stats.RunMenu(window);
			std::cout << result << std::endl;
		case 4:
			window.close();
			break;
		case -1:
			result = game.RunMenu(window);
			std::cout << result << std::endl;
		}
	}*/
    return 0;
}
