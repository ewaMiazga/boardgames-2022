#pragma once
#include <string>

class Games
{
	void insert(int row, int column, int num);

	void insert(int num, std::string clueValue);

	bool isEmpty(int& row, int& column);

	bool isEmpty(int& row, int& column, int** tab);


};