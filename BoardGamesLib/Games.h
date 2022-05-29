#pragma once
#include <iostream>
#include <string>

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

	virtual void play() = 0;

	virtual void display() = 0;

	~Games() {}
};