#include "Sudoku.h"

// sudoku have to have at least 18 squares filled to be solvable
// 19 - 26 hard to solve
// 27 - 36 medium lvl
// >= 37 easy

int myrandom(int i) { return std::rand() % i; }

Sudoku::Sudoku(std::string difficultyLevelValue)
{
	assignDiffcultyLevel(difficultyLevelValue);
	int** array;
	array = new int* [10];
	for (int i = 0; i < 10; i++)
		array[i] = new int[10];
	createEmptyBoard(array);
	board = array;
	for (int i = 0; i < N * N; i++)
	{
		gridPos[i] = i;
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(guessNum), std::end(guessNum), g);
	std::shuffle(std::begin(gridPos), std::end(gridPos), g);
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

void Sudoku::assignDiffcultyLevel(std::string difficultyLevelValue)
{
	std::pair<int, int> diff;
	if (difficultyLevelValue == "easy")
	{
		diff = std::make_pair(medium + 1, N*N);
	}
	else if (difficultyLevelValue == "medium")
	{
		diff = std::make_pair(hard + 1, medium);
	}
	else if(difficultyLevelValue == "hard")
	{
		diff = std::make_pair(solvable, hard);
	}
	difficultyLevel = diff;
}

int Sudoku::calcDifficultyLevel(int** tab)
{
	int emptySquares = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (tab[i][j] == emptySquare)
				emptySquares++;
	return N * N - emptySquares;
}

void Sudoku::createEmptyBoard(int** tab)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
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

void Sudoku::insert(int row, int column, int num)
{
	if (num <= N && num >= 0)
		board[row][column] = num;
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

//void Sudoku::generateSolvedBoard()
//{
//	int i, j;
//	int** temp;
//	temp = new int* [10];
//	for (int i = 0; i < 10; i++)
//		temp[i] = new int[10];
//	createEmptyBoard(temp);
//	while (!isSolved(temp, i, j))
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				//if (i == 0 && j == 0)
//				//	board[0][0] = rand() % N + 1;
//				if (generateNumbers(i, j, temp).size() != 0)
//				{
//					auto it = rand() % generateNumbers(i, j, temp).size();
//					temp[i][j] = generateNumbers(i, j, temp)[it];
//				}
//				else
//				{
//					std::cout << i << j << std::endl;
//					generateSolvedBoard();
//				}
//			}
//		}
//	}
//	fillBoard(temp);
//}

void Sudoku::generateSolvedBoard()
{
	int i, j;
	int** temp;
	temp = new int* [10];
	for (int i = 0; i < 10; i++)
		temp[i] = new int[10];
	createEmptyBoard(temp);
	std::random_device rd;
	std::mt19937 g(rd());
	std::vector<int> num(N * N);
	std::vector<int> num1(N);
	int n = 0;
	int k = 1;
	std::generate(num.begin(), num.end(), [&n] {return n++; });
	std::shuffle(std::begin(num), std::end(num), g);
	std::generate(num1.begin(), num1.end(), [&k] {return k++; });
	std::shuffle(std::begin(num1), std::end(num1), g);
	int numberRow = num[(rand() % num.size())] / N;
	int numberCol = num[(rand() % num.size())] / N;
	int number = num1[rand() % num1.size()];
	temp[numberRow][numberCol] = number;
	while (!solve(0, 0, temp))
		generateSolvedBoard();
	fillBoard(temp);
}

//void Sudoku::generateStartBoard()
//{
//	generateSolvedBoard();
//	int howManySquareLast = difficultyLevel;
//	int howManySquareRemove = N * N - howManySquareLast;
//	std::vector<int> randomRow;
//	std::vector<int> randomColumn;
//	int it = 1;
//	while (it <= howManySquareRemove)
//	{
//		randomRow.push_back(rand() % N);
//		randomColumn.push_back(rand() % N);
//		it++;
//	}
//	int i, j;
//	int** temp;
//	temp = new int* [10];
//	for (int i = 0; i < 10; i++)
//		temp[i] = new int[10];
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (*randomRow.begin() == i && *randomColumn.begin() == j) // check how many solutions is there
//			{
//				if (randomRow.size() != 0 && randomColumn.size() != 0)
//				{
//					temp[i][j] = emptySquare;
//					std::vector<int>::iterator itRow = randomRow.begin();
//					randomRow.erase(itRow);
//					std::vector<int>::iterator itCol = randomRow.begin();
//					randomColumn.erase(itCol);
//				}
//			}
//		}
//	}
//	fillBoard(temp);
//}

void Sudoku::generateStartBoard()
{
	generateSolvedBoard();
	//int** temp;
	//temp = new int* [10];
	//for (int i = 0; i < 10; i++)
	//	temp[i] = new int[10];
	for (int i = 0; i < N * N; i++)
	{
		int x = (gridPos[i]) / 9;
		int y = (gridPos[i]) % 9;
		int temp = board[x][y];
		board[x][y] = emptySquare;

		// If now more than 1 solution , replace the removed cell back.
		int check = 0;
		countSolutions(check, 0, 0);
		if (check != 1)
		{
			board[x][y] = temp;
		}
	}
	//if (!solve(0, 0, board))
	//	generateStartBoard();
	//displaySudoku();
	//std::cout << "solved: " << std::endl;
	//solve(0, 0, board);
	//displaySudoku();
	//fillBoard(temp);
}

void Sudoku::countSolutions(int& number, int row, int col)
{
	//for(int i = 0; i < N; i++)
	//	std::cout << guessNum[i] << std::endl;
	//if (solve(row, col, board))
	//{
	//	number++;
	//	return;
	//}
	//col+= 1;
	//if (solve(row, col, board))
	if (row == rows - 1 && col == columns)
		return;
	if (col == columns)
	{
		col = 0;
		row++;
	}
	if (!isEmpty(row, col, board))
	{
		number++;
		//countSolutions(number, row, col + 1);
		//return;
	}
	for (int i = 0; i < 9 && number < 2; i++)
	{
		if (!checkRepetition(row, col, this->guessNum[i], board))
		//if (!checkRepetition(row, col, generateNumbers(row, col, board)[i], board))
		{
			this->board[row][col] = this->guessNum[i];
			//this->board[row][col] = generateNumbers(row, col, board)[i];
			countSolutions(number, row, col += 1);
		}

		this->board[row][col] = emptySquare;
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


bool Sudoku::solve(int row, int col, int** tab)
{
	if (row == rows - 1 && col == columns)
		return true;
	if (col == columns) 
	{
		col = 0;
		row++;
	}
	if (!isEmpty(row, col, tab))
		return solve(row, col + 1, tab);

	for (int num = 1; num <= N; num++)
	{
		if (!checkRepetition(row, col, num, tab))
		{
			tab[row][col] = num;
			if (solve(row, col + 1, tab))
				return true;
		}
		tab[row][col] = emptySquare;
	}
	return false;
}

void Sudoku::solve1()
{
	for(int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++)
			if (isEmpty(row, col, board))
				for (int num = 1; num <= N; num++)
					if (!checkRepetition(row, col, num, board))
					{
						board[row][col] = num;
						if (!solve(row, col + 1, board))
						{
							board[row][col] = emptySquare;
							solve1();
						}
					}
}

void Sudoku::play()
{
	int k = 0;
	while (!(k >= difficultyLevel.first && k <= difficultyLevel.second))
	{
		generateStartBoard();
		k = calcDifficultyLevel(board);
	}
	int i = 0;
	int j = 0;
	while (!isSolved(board, i, j))
	{
		display();
		int row, col, num;
		std::cout << "Choose the row" << std::endl;
		std::cin >> row;
		std::cout << "Choose the column" << std::endl;
		std::cin >> col;
		std::cout << "Enter the number" << std::endl;
		std::cin >> num;
		insert(row - 1, col - 1, num);
	}
}

void Sudoku::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << board[i][j] << " ";
			if ((j + 1) % 3 == 0 && j != columns - 1)
				std::cout << "| ";
		}
		std::cout << std::endl;
		if ((i + 1) % 3 == 0 && i != rows - 1)
			std::cout << "----------------------" << std::endl;
	}
}
