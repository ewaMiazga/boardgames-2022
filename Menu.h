#pragma once
#include "SFML/Graphics.hpp"
#include "Sudoku.h"
#include "User.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu();
	Menu(float width, float height, std::vector<std::string> info);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	int RunMenu(sf::RenderWindow& window);

protected:
	int selectedItemIndex;
	sf::Font font;
	std::vector<sf::Text> menu;

};

class LoginWindow
	:public Menu
{
public:
	LoginWindow(float width, float height);
	~LoginWindow();
	void draw(sf::RenderWindow& window);
	void RunMenu(sf::RenderWindow& window);

protected:
	sf::String nameInPut;
	sf::RectangleShape nameRect;

};

class Game
{
public:
	Game()=default;
	Game(float width, float height, user player);
	~Game();
	void drawGame(sf::RenderWindow& window);
	void RunGame(sf::RenderWindow& window, user player, Sudoku level);
	void update(std::vector<std::string> sudoku);
protected:
	sf::Font font;
	std::vector<sf::Text> menu;
	float width;
	float height;
	user player;
};

