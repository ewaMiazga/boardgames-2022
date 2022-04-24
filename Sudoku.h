#pragma once
#include <iostream>
#include <random>
#include <vector>

#define emptySquare 0
#define N 9
#define rows  9
#define columns 9

class Sudoku
{
private:
	//int board[N][N];
	//int (*board)[rows];
	int board[rows][columns];
	int difficultyLevel;

public:
	Sudoku(int difficultyLevelValue);

	void fillBoard(int board[][N]);

	bool usedInRow(int row, int value);

	bool usedInColumn(int row, int value);

	bool usedInBox(int row, int column, int value);

	bool checkRepetition(int row, int column, int value);

	std::vector<int> generateNumbers(int row, int column);

	void removeNumber(int row, int column);

	bool isEmpty(int row, int column);

	bool isSolved();

	void generateSolvedBoard();

	void generateStartBoard();

	bool solve();

	void displaySudoku();
};