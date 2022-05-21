#pragma once
#include <iostream>
#include <string>

#define emptySquare

class Games
{
private:
	std::string game;
	char** board;
	int rows;
	int columns;

public:
	Games(std::string gameValue);

	void calc_emptySquare();

	void insert(int row = 0, int column = 0, char value = '_', int num = 0, std::string clueValue = "_");

	bool isEmpty(int& num, int& row, int& column, int** tab); // there should be default arguments

	void play();

	void display();

};