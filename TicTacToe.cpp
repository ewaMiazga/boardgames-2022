#include "TicTacToe.h"
#include "../208.1-gry-planszowe/TicTacToe.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			board[i][j] = '_';
}

TicTacToe::~TicTacToe()
{
	for (int i = 0; i < rows; ++i) 
		delete[] board[i];
	delete[] board;
}

bool TicTacToe::isEmpty(int row, int column)
{
	if (board[row][column] == emptySquare)
		return true;
	return false;
}

void TicTacToe::insert(int row, int column, char value)
{
	if (isEmpty(row, column))
		board[row][column] = value;
	//else exception
}

char TicTacToe::getWinner()
{
	int NumOfWinners = 0;
	char winner = ' ';
	for (int i = 0; i < N; i++)
	{
		if (findWin(i, 0, i, 1, i, 2)) //check rows
		{
			winner = board[i][0];
			NumOfWinners++;
		}
		else if (findWin(0, i, 1, i, 2, i)) // check columns
		{
			winner = board[0][i];
			NumOfWinners++;
		}
		else if (findWin(0, i, 1, 1, 2, 2 - i) && (i != 1)) //check diagonals
		{
			winner = board[0][i];
			NumOfWinners++;
		}
	}
	if (NumOfWinners != 1)
		winner = ' ';
	// else if (NumOfWinners > 2) throw exception	
	return winner;
}

bool TicTacToe::isFullBoard()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (board[i][j] == emptySquare)
				return false;
	return true;
}

bool TicTacToe::gameOver()
{
	char winner;
	//if (!fullBoard()) // continue to play
	//	return false;
	if (getWinner() != ' ')
	{
		winner = getWinner(); // one player win
		std::cout << "The winner is: " << winner << std::endl;
		return true;
	}
	else if (!isFullBoard()) // continue to play
		return false;
	else
	{
		winner = ' '; // tie
		std::cout << "Tie" << std::endl;
		return true;
	}
}

std::pair<int, int> TicTacToe::checkWillWin(char value)
{
	for (int i = 0; i < N; i++)
	{
		if (willWin(i, 0, i, 1, i, 2, value)) //check rows
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(i, j))
					return std::make_pair(i, j);
				j++;
			}
		}
		if (willWin(0, i, 1, i, 2, i, value)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, i))
					return std::make_pair(j, i);
				j++;
			}
		}
		if (willWin(0, i, 1, 1, 2, 2 - i, value) && (i != 1)) // check diagonals
		{
			int j = 0;
			while (j < N && i == 0)
			{
				if (isEmpty(j, j))
					return std::make_pair(j, j);
				j++;
			}
			while (j < N && i == 2)
			{
				if (isEmpty(j, 2 - j))
					return std::make_pair(j, 2 - j);
				j++;
			}
		}
	}
	return std::make_pair(-1, -1);
}

std::pair<int, int> TicTacToe::chooseSecondMove(char value)
{
	for (int i = 0; i < N; i++)
	{
		if (findChanceToWin(0, i, 1, 1, 2, 2 - i, value) && (i != 1)) //diagonals
		{
		int j = 0;
		while (j < N && i == 0)
		{
			if (isEmpty(j, j))
				return std::make_pair(j, j);
			j++;
		}
		while (j < N && i == 2)
		{
			if (isEmpty(j, 2 - j))
				return std::make_pair(j, 2 - j);
			j++;
		}
		}
		else if (findDoubleChanceToWin(i, 0, i, 1, i, 2) && (i != 1))
			return std::make_pair(i, 1);
		else if (findChanceToWin(i, 0, i, 1, i, 2, value)) //check rows
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(i, j))
					return std::make_pair(i, j);
				j++;
			}
		}
		else if (findDoubleChanceToWin(0, i, 1, i, 2, i) && (i != 1))
			return std::make_pair(1, i);
		else if(findChanceToWin(0, i, 1, i, 2, i, value)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, i))
					return std::make_pair(j, i);
				j++;
			}
		}
	}
	return std::make_pair(-1, -1);
}

//std::pair<int, int> TicTacToe::chooseThirdMove() // find case when opponet try to get to positions to win
//{
//	std::pair<int, int> notWillWin = std::make_pair(-1, -1);
//	for (int i = 0; i < N; i++)
//	{
//		if (findSameCorners(i, 0, i, 1, i, 2) && i==0)
//			return std::make_pair(2, 2);
//	}
//	return notWillWin;
//}

std::pair<int, int> TicTacToe::emptyLineFullOpponentSq(char value)
{
	std::pair<int, int> notWillWin = std::make_pair(-1, -1);
	for (int i = 0; i < N; i++)
	{
		if (findEmptyLine(i, 0, i, 1, i, 2)) //check rows
		{
			int j = 0;
			while (j < N)
			{
				if (chooseSecondMove(value) != notWillWin && chooseSecondMove(value) == std::make_pair(i, j))
					return std::make_pair(i, j);
				j++;
			}
		}
		if (findWin(0, i, 1, i, 2, i)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (chooseSecondMove(value) != notWillWin && chooseSecondMove(value) == std::make_pair(j, i))
					return std::make_pair(j, i);
				j++;
			}
		}
		if (findWin(0, i, 1, 1, 2, 2 - i) && (i != 1)) //check diagonals
		{
			int j = 0;
			while (j < N && i == 0)
			{
				if (chooseSecondMove(value) != notWillWin && chooseSecondMove(value) == std::make_pair(j, j))
					return std::make_pair(j, j);
				j++;
			}
			while (j < N && i == 2)
			{
				if (chooseSecondMove(value) != notWillWin && chooseSecondMove(value) == std::make_pair(j, 2 - j))
					return std::make_pair(j, 2 - j);
				j++;
			}
		}
	}
	return notWillWin;
}

std::pair<int, int> TicTacToe::defaultMove()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (isEmpty(i, j))
				return std::make_pair(i, j);
		}
	}
}

void TicTacToe::moveAI(char value, char opponentValue)
{
	std::pair<int, int> notWillWin = std::make_pair(-1, -1); // it can be one part in witch i want to enter AI symbol
	if (isEmpty(1, 1))
		insert(1, 1, value);
	else if (checkWillWin(value) != notWillWin)
	{
		std::pair<int, int> coordinates = checkWillWin(value);
		insert(coordinates.first, coordinates.second, value);
	}
	else if (checkWillWin(opponentValue) != notWillWin)
	{
		std::pair<int, int> coordinates = checkWillWin(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else if (chooseSecondMove(opponentValue) == chooseSecondMove(value) && chooseSecondMove(opponentValue) != notWillWin)
	{
		std::pair<int, int> coordinates = chooseSecondMove(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else if (chooseSecondMove(opponentValue) != notWillWin)
	{
		std::pair<int, int> coordinates = chooseSecondMove(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else if (chooseSecondMove(value) != notWillWin)
	{
		std::pair<int, int> coordinates = chooseSecondMove(value);
		insert(coordinates.first, coordinates.second, value);
	}
	//else if (chooseThirdMove() != notWillWin)
	//{
	//	std::pair<int, int> coordinates = chooseThirdMove();
	//	insert(coordinates.first, coordinates.second, value);
	//}
	else if (emptyLineFullOpponentSq(opponentValue) != notWillWin)  // check if is it possible to be this case
	{
		std::pair<int, int> coordinates = emptyLineFullOpponentSq(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else
	{
		std::pair<int, int> coordinates = defaultMove();
		insert(coordinates.first, coordinates.second, value);
	}
}

void TicTacToe::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TicTacToe::play()
{
	char playerCounter;
	char AICounter;
	std::cout << "Choose counter ( 'O' or 'X' )" << std::endl;
	std::cin >> playerCounter;
	if (playerCounter == 'X')
		AICounter = 'O';
	else
		AICounter = 'X';
	int move = 1;
	while (!gameOver())
	{
		if (move % 2 == 1)
		{
			display();
			int row, col;
			std::cout << "Choose row" << std::endl;
			std::cin >> row;
			std::cout << "Choose column" << std::endl;
			std::cin >> col;
			insert(row - 1, col - 1, playerCounter);
		}
		else
			moveAI(AICounter, playerCounter);
		move++;
	}
}