#pragma once
#include <iostream>

#define rows  9
#define columns 9

class Sudoku
{
private:
	//int board[N][N];
	int (*board)[rows];

public:
	Sudoku();

	bool usedInRow(int row, int value);

	bool usedInColumn(int row, int value);

	bool usedInBox(int row, int column, int value);

	bool checkRepetition(int row, int column, int value);
};