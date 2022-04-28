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

	int** board;
	int difficultyLevel;
	int guessNum[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int gridPos[81];

public:
	Sudoku(int difficultyLevelValue);

	void fillBoard(int** tab);

	void calcDifficultyLevel(int** tab);

	void createEmptyBoard(int** tab);

	bool usedInRow(int row, int value, int** tab);

	bool usedInColumn(int row, int value, int** tab);

	bool usedInBox(int row, int column, int value, int** tab);

	bool checkRepetition(int row, int column, int value, int** tab);

	std::vector<int> generateNumbers(int row, int column, int** tab);

	void removeNumber(int row, int column, int** tab);

	bool isEmpty(int& row, int& column, int** tab);

	bool isSolved(int** tab, int& i, int& j);

	void generateSolvedBoard();

	void generateStartBoard();

	void countSolutions(int& number, int row, int col);

	bool solve(int row, int col, int** tab);

	void displaySudoku();
};
