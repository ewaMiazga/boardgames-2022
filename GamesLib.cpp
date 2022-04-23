#include "GamesLib.h"

Sudoku::Sudoku()
{
	int sudokuBoard[rows][columns] =
	{
		{ 0, 0, 6, 5, 0, 8, 4, 0, 0 },
		{ 5, 2, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 7, 8, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 4, 0, 1, 0, 0, 8, 0 },
		{ 9, 0, 0, 8, 2, 3, 0, 0, 5 },
		{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
		{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
		{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
	};
	board = sudokuBoard;
}

bool Sudoku::usedInRow(int row, int value)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (board[i][j] == value)
				return true;
		}
	}
	return false;
}

bool Sudoku::usedInColumn(int column, int value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == value)
				return true;
		}
	}
	return false;
}

bool Sudoku::usedInBox(int row, int column, int value) //it's enough to enter dimentions in box
{
	row -= row % 3;
	column -= column % 3;
	for (int i = row; i < row + 3; i++)
	{
		for (int j = column; j < column + 3; j++)
		{
			if (board[i][j] == value)
				return true;
		}
	}
	return false;
}

bool Sudoku::checkRepetition(int row, int column, int value)
{
	if (!usedInBox(row, column, value) && !usedInColumn(column, value) && !usedInRow(row, value))
		return false;
	return true;
}
