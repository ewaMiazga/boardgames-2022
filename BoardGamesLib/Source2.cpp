//#include "Sudoku2.h"
//
//// sudoku have to have at least 18 squares filled to be solvable
//// 19 - 26 hard to solve
//// 27 - 36 medium lvl
//// >= 37 easy
//
//Sudoku::Sudoku(int difficultyLevelValue)
//{
//	difficultyLevel = difficultyLevelValue;
//	createEmptyBoard(board);
//}
//
//void Sudoku::fillBoard(int tab[rows][columns])
//{
//	/*int sudokuBoard[rows][columns] =
//	{
//	{ 0, 0, 6, 5, 0, 8, 4, 0, 0 },
//	{ 5, 2, 0, 0, 0, 1, 0, 0, 0 },
//	{ 0, 7, 8, 0, 0, 0, 0, 0, 1 },
//	{ 0, 0, 4, 0, 1, 0, 0, 8, 0 },
//	{ 9, 0, 0, 8, 2, 3, 0, 0, 5 },
//	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
//	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
//	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
//	};*/
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			board[i][j] = emptySquare;
//	
//}
//
//void Sudoku::createEmptyBoard(int tab[rows][columns])
//{
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++)
//			tab[i][j] = emptySquare;
//}
//
//
//bool Sudoku::usedInRow(int row, int value, int tab[rows][columns])
//{
//	int i = row;
//	for (int j = 0; j < columns; j++)
//	{
//		if (tab[i][j] == value)
//			return true;
//	}
//	return false;
//}
//
//bool Sudoku::usedInColumn(int column, int value, int tab[rows][columns])
//{
//	int j = column;
//	for (int i = 0; i < rows; i++)
//	{
//		if (tab[i][j] == value)
//			return true;
//	}
//	return false;
//}
//
//bool Sudoku::usedInBox(int row, int column, int value, int tab[rows][columns]) //it's enough to enter dimentions in box
//{
//	row -= row % 3;
//	column -= column % 3;
//	for (int i = row; i < row + 3; i++)
//	{
//		for (int j = column; j < column + 3; j++)
//		{
//			if (tab[i][j] == value)
//				return true;
//		}
//	}
//	return false;
//}
//
//bool Sudoku::checkRepetition(int row, int column, int value, int tab[rows][columns]) // returns true if there is repetition
//{
//	if (!usedInBox(row, column, value, tab) && !usedInColumn(column, value, tab) && !usedInRow(row, value, tab) && tab[row][column] == emptySquare)
//		return false;
//	return true;
//}
//
////int Sudoku::generateNumber(int row, int column)
////{
////	bool repetitionFlag = true;
////	int number;
////	while (repetitionFlag)
////	{
////		number = rand() % N + 1;
////		if (!checkRepetition(row, column, number))
////			repetitionFlag = false;
////	}
////	return number;
////}
//
//std::vector<int> Sudoku::generateNumbers(int row, int column, int tab[rows][columns])
//{
//	std::vector<int> numbers;
//	for (int temp = 1; temp <= N; temp++)
//	{
//		if (!checkRepetition(row, column, temp, tab))
//		{
//			numbers.push_back(temp);
//		}
//	}
//	return numbers;
//}
//
//void Sudoku::removeNumber(int row, int column, int tab[rows][columns])
//{
//	generateNumbers(row, column, tab).erase(generateNumbers(row, column, tab).begin());
//}
//
//bool Sudoku::isEmpty(int row, int column, int tab[rows][columns])
//{
//	if (tab[row][column] == emptySquare)
//		return true;
//	return false;
//}
//
//bool Sudoku::isSolved(int tab[rows][columns])
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (isEmpty(i, j, tab))
//				return false;
//		}
//	}
//	return true;
//}
//
//void Sudoku::generateSolvedBoard()
//{
//	int temp[rows][columns];
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			temp[i][j] = emptySquare;
//	createEmptyBoard(temp);
//	while (!isSolved(temp))
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
//					std::cout << generateNumbers(i, j, temp)[it];
//					temp[i][j] = generateNumbers(i, j, temp)[it];
//				}
//				else
//				{
//					std::cout << i << j << std::endl;
//					generateSolvedBoard();
//				}
//			}
//			std::cout << std::endl;
//		}
//	}
//	fillBoard(temp);
//}
//
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
//	int temp[rows][columns];
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (*randomRow.begin() == i && *randomColumn.begin() == j) // check how many solutions is there
//			{
//				if (randomRow.size() != 0 && randomColumn.size() != 0)
//					temp[i][j] = emptySquare;
//				std::vector<int>::iterator itRow = randomRow.begin();
//				//if (randomRow.begin() != randomRow.end())
//				randomRow.erase(itRow);
//				std::vector<int>::iterator itCol = randomRow.begin();
//				//if (randomColumn.begin() != randomColumn.end())
//				randomColumn.erase(itCol);
//			}
//			else
//				temp[i][j] = board[i][j];
//		}
//	}
//}
//
////bool Sudoku::solve()
////{
////	if (isSolved(board))
////		return true;
////	for (int i = 0; i < rows; i++)
////	{
////		for (int j = 0; j < columns; j++) 
////		{
////			if (isEmpty(i, j, board))
////			{
////				while (generateNumbers(i, j, board).size() != 0)
////				{
////					int temp = generateNumbers(i, j, board)[0];
////					board[i][j] = temp;
////					if (isSolved(board))
////						return true;
////					removeNumber(i, j, board);
////					board[i][j] = emptySquare;
////					solve();
////				}
////				return false;
////			}
////		}
////	}
////}
//
////bool Sudoku::solve()
////{
////
////	// If there is no unassigned location,
////	// we are done
////	if (isSolved(board))
////		// success!
////		return true;
////
////	// Consider digits 1 to 9
////	for (int row = 0; row < rows; row++)
////	{
////		for (int col = 0; col < columns; col++)
////		{
////			for (int num = 1; num <= N; num++)
////			{
////
////				// Check if looks promising
////				if (!checkRepetition(row, col, num, board))
////				{
////
////					// Make tentative assignment
////					board[row][col] = num;
////
////					// Return, if success
////					if (solve())
////						return true;
////
////					// Failure, unmake & try again
////					board[row][col] = emptySquare;
////				}
////			}
////		}
////	}
////	// This triggers backtracking
////	return false;
////}
//
//bool Sudoku::solve(int board[rows][columns])
//{
//	int row = 0;
//	int col = 0;
//	// If there is no unassigned location,
//	// we are done
//	if (isSolved(board))
//		// success!
//		return true;
//
//	// Consider digits 1 to 9
//
//	for (int num = 1; num <= N; num++)
//	{
//
//		// Check if looks promising
//		if (!checkRepetition(row, col, num, board))
//		{
//
//			// Make tentative assignment
//			board[row][col] = num;
//
//			// Return, if success
//			if (solve(board))
//				return true;
//
//			// Failure, unmake & try again
//			board[row][col] = emptySquare;
//		}
//
//	}
//	// This triggers backtracking
//	return false;
//}
//
//void Sudoku::displaySudoku()
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			std::cout << board[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
