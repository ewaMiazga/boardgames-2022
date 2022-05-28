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

	int board[rows][columns];
	int difficultyLevel;

public:
	Sudoku(int difficultyLevelValue);

	void fillBoard(int tab[rows][columns]);

	void createEmptyBoard(int tab[rows][columns]);

	bool usedInRow(int row, int value, int tab[rows][columns]);

	bool usedInColumn(int row, int value, int tab[rows][columns]);

	bool usedInBox(int row, int column, int value, int tab[rows][columns]);

	bool checkRepetition(int row, int column, int value, int tab[rows][columns]);

	std::vector<int> generateNumbers(int row, int column, int tab[rows][columns]);

	void removeNumber(int row, int column, int tab[rows][columns]);

	bool isEmpty(int row, int column, int tab[rows][columns]);

	bool isSolved(int tab[rows][columns]);

	void generateSolvedBoard();

	void generateStartBoard();

	bool solve(int board[rows][columns]);

	void displaySudoku();
};