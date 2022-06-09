#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// -------------------------------------------------- Bartlomiej Niewiarowski ----------------------------------------------------------
class Menu
{
public:
	Menu() = default;
	Menu(float width, float height, std::vector<std::string> info);
	~Menu();

	void set_info(int index, std::string info);

	virtual void draw(sf::RenderWindow& window);

    virtual int RunMenu(sf::RenderWindow& window);

    void reupload_info(std::vector<std::string> info);

protected:
	sf::Font font;
	std::vector<sf::Text> text;
	void fill_info(float width, float height, std::vector<std::string> info, size_t sum);
    float width;
    float height;
};

class DecisionMenu
	:public Menu
{
public:
	DecisionMenu() = default;
	DecisionMenu(float width, float height, std::vector<std::string> info, std::vector<std::string> options);
	~DecisionMenu() = default;

	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void draw(sf::RenderWindow& window) override;
	int RunMenu(sf::RenderWindow& window) override;

protected:
	void fill_options(float width, float height, std::vector<std::string> options, size_t sum);
	int selectedItemIndex;
	std::vector<sf::Text> options;
};

class LoginWindow
	:public DecisionMenu
{
public:
    LoginWindow() = default;
	LoginWindow(float width, float height, std::vector<std::string> info, std::vector<std::string> options);
	~LoginWindow();
	void draw(sf::RenderWindow& window) override;
	int RunMenu(sf::RenderWindow& window) override;
	sf::String getInPut() { return nameInPut; }
	std::string get_name() { return name; }

protected:
	sf::String nameInPut;
	sf::Text Name;
	sf::RectangleShape nameRect;
	std::string name;
};

void RunApp(std::vector<Menu> windows, sf::RenderWindow& window);

