#pragma once
#include <iostream>
#include <string>
#include "User.h"

#define emptySquare

class Games
{
protected:
	std::string game;
	char** board;
	int rows;
	int columns;

	static int** r;

public:
	Games() = default;

	//Games(std::string gameValue);

	//void calc_emptySquare();

	//void insert(int row = 0, int column = 0, char value = '_', int num = 0, std::string clueValue = "_");

	//virtual bool isEmpty(int row, int column, char value = ' ', int** tab = r); // there should be default arguments

	virtual void play(user& player, sf::RenderWindow& window) = 0;

	virtual std::vector<std::string> display() = 0;

	~Games() {}
};