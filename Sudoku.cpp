#include "Sudoku.h"

// sudoku have to have at least 18 squares filled to be solvable
// 19 - 26 hard to solve
// 27 - 36 medium lvl
// >= 37 easy

Sudoku::Sudoku(int difficultyLevelValue)
{
	difficultyLevel = difficultyLevelValue;
	int** array;
	array = new int* [10];
	for (int i = 0; i < 10; i++)
		array[i] = new int[10];
	createEmptyBoard(array);
	board = array;
}

void Sudoku::fillBoard(int** tab)
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

	board = tab;
}

void Sudoku::createEmptyBoard(int** tab)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tab[i][j] = emptySquare;
}


bool Sudoku::usedInRow(int row, int value, int** tab)
{
	int i = row;
	for (int j = 0; j < columns; j++)
	{
		if (tab[i][j] == value)
			return true;
	}
	return false;
}

bool Sudoku::usedInColumn(int column, int value, int** tab)
{
	int j = column;
	for (int i = 0; i < rows; i++)
	{
			if (tab[i][j] == value)
				return true;
	}
	return false;
}

bool Sudoku::usedInBox(int row, int column, int value, int** tab) //it's enough to enter dimentions in box
{
	row -= row % 3;
	column -= column % 3;
	for (int i = row; i < row + 3; i++)
	{
		for (int j = column; j < column + 3; j++)
		{
			if (tab[i][j] == value)
				return true;
		}
	}
	return false;
}

bool Sudoku::checkRepetition(int row, int column, int value, int** tab) // returns true if there is repetition
{
	if (!usedInBox(row, column, value, tab) && !usedInColumn(column, value, tab) && !usedInRow(row, value, tab) && tab[row][column] == emptySquare)
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

std::vector<int> Sudoku::generateNumbers(int row, int column, int** tab)
{
	std::vector<int> numbers;
	for (int temp = 1; temp <= N; temp++)
	{
		if (!checkRepetition(row, column, temp, tab))
		{
			numbers.push_back(temp);
		}
	}
	return numbers;
}

void Sudoku::removeNumber(int row, int column, int** tab)
{
	generateNumbers(row, column, tab).erase(generateNumbers(row, column, tab).begin());
}

bool Sudoku::isEmpty(int& row, int& column, int** tab)
{
	if (tab[row][column] == emptySquare)
		return true;
	return false;
}

bool Sudoku::isSolved(int** tab, int& i, int& j)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (isEmpty(i, j, tab))
				return false;
		}
	}
	return true;
}

void Sudoku::generateSolvedBoard()
{
	int i, j;
	int** temp;
	temp = new int* [10];
	for (int i = 0; i < 10; i++)
		temp[i] = new int[10];
	createEmptyBoard(temp);
	while (!isSolved(temp, i, j))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				//if (i == 0 && j == 0)
				//	board[0][0] = rand() % N + 1;
				if (generateNumbers(i, j, temp).size() != 0)
				{
					auto it = rand() % generateNumbers(i, j, temp).size();
					temp[i][j] = generateNumbers(i, j, temp)[it];
				}
				else
				{
					std::cout << i << j << std::endl;
					generateSolvedBoard();
				}
			}
		}
	}
	fillBoard(temp);
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
				if (randomRow.size() != 0 && randomColumn.size() != 0)
				temp[i][j] = emptySquare;
				std::vector<int>::iterator itRow = randomRow.begin();
				//if (randomRow.begin() != randomRow.end())
				randomRow.erase(itRow);
				std::vector<int>::iterator itCol = randomRow.begin();
				//if (randomColumn.begin() != randomColumn.end())
				randomColumn.erase(itCol);
			}
			else
				temp[i][j] = board[i][j];
		}
	}
}

//bool Sudoku::solve()
//{
//	if (isSolved(board))
//		return true;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++) 
//		{
//			if (isEmpty(i, j, board))
//			{
//				while (generateNumbers(i, j, board).size() != 0)
//				{
//					int temp = generateNumbers(i, j, board)[0];
//					board[i][j] = temp;
//					solve();
//					if (isSolved(board))
//						return true;
//					else
//						removeNumber(i, j, board);
//				}
//				return false;
//			}
//		}
//	}
//}


bool Sudoku::solve(int row, int col)
{
	if (row == rows - 1 && col == columns)
		return true;
	if (col == columns) 
	{
		col = 0;
		row++;
	}
	if (!isEmpty(row, col, board))
		return solve(row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		if (!checkRepetition(row, col, num, board))
		{
			board[row][col] = num;
			if (solve(row, col + 1))
				return true;
		}
		board[row][col] = emptySquare;
	}
	return false;
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
