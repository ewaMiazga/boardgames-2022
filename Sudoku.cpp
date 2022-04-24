#include "Sudoku.h"

// sudoku have to have at least 18 squares filled to be solvable
// 19 - 26 hard to solve
// 27 - 36 medium lvl
// >= 37 easy
Sudoku::Sudoku(int difficultyLevelValue)
{
	difficultyLevel = difficultyLevelValue;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			board[i][j] = 0;
	//board = sudokuBoard;
}

void Sudoku::fillBoard(int mat[][N])
{
	/*int sudokuBoard[rows][columns] =
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
	};*/

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = mat[i][j];
		}
	}
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

bool Sudoku::checkRepetition(int row, int column, int value) // returns true if there is repetition
{
	if (!usedInBox(row, column, value) && !usedInColumn(column, value) && !usedInRow(row, value))
		return false;
	return true;
}

//int Sudoku::generateNumber(int row, int column)
//{
//	bool repetitionFlag = true;
//	int number;
//	while (repetitionFlag)
//	{
//		number = rand() % N + 1;
//		if (!checkRepetition(row, column, number))
//			repetitionFlag = false;
//	}
//	return number;
//}

std::vector<int> Sudoku::generateNumbers(int row, int column)
{
	std::vector<int> numbers;
	for (int temp = 1; temp <= N; temp++)
	{
		if (!checkRepetition(row, column, temp))
		{
			numbers.push_back(temp);
		}
	}
	return numbers;
}

void Sudoku::removeNumber(int row, int column)
{
	generateNumbers(row, column).erase(generateNumbers(row, column).begin());
}

bool Sudoku::isEmpty(int row, int column)
{
	if (board[row][column] == emptySquare)
		return true;
	return false;
}

bool Sudoku::isSolved()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (isEmpty(i, j))
				return false;
		}
	}
	return true;
}

void Sudoku::generateSolvedBoard()
{
	while (!isSolved())
	{
		board[0][0] = rand() % N + 1;
		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < columns; j++)
			{
				if (generateNumbers(i, j).begin() != generateNumbers(i, j).end())
				{
					auto it = rand() % generateNumbers(i, j).size();
					board[i][j] = generateNumbers(i, j)[it];
				}
				else
					generateSolvedBoard();
			}
		}
	}
}

void Sudoku::generateStartBoard()
{
	generateSolvedBoard();
	int howManySquareLast = difficultyLevel;
	int howManySquareRemove = N * N - howManySquareLast;
	std::vector<int> randomRow;
	std::vector<int> randomColumn;
	int it = 1;
	while (it <= howManySquareRemove)
	{
		randomRow.push_back(rand() % N);
		randomColumn.push_back(rand() % N);
		it++;
	}
	int temp[rows][columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (*randomRow.begin() == i && *randomColumn.begin() == j) // check how many solutions is there
			{
				temp[i][j] = emptySquare;
				std::vector<int>::iterator itRow = randomRow.begin();
				randomRow.erase(itRow);
				std::vector<int>::iterator itCol = randomRow.begin();
				randomColumn.erase(itCol);
			}
			else
				temp[i][j] = board[i][j];
		}
	}
}

bool Sudoku::solve()
{
	bool solvedFlag = isSolved();
	if (isSolved())
		return true;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (isEmpty(i, j))
			{
				while (generateNumbers(i, j).begin() != generateNumbers(i, j).end())
				{
					int temp = generateNumbers(i, j)[0];
					board[i][j] = temp;
					solve();
					if (isSolved())
						return true;
					else
						removeNumber(i, j);
				}
				return false;
			}
		}
	}
}

void Sudoku::displaySudoku()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
