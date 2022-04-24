#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			board[i][j] = '_';
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
		else if (findWin(0, i, 1, 1, 2, 2 - i) && (i != 0)) //check diagonals
		{
			winner = board[i][i];
			NumOfWinners++;
		}
	}
	if (NumOfWinners != 1)
		winner = ' ';
	// else if (NumOfWinners > 2) throw exception	
	return winner;
}

bool TicTacToe::fullBoard()
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
	if (!fullBoard()) // continue to play
		return false;
	else if (getWinner() != ' ')
	{
		winner = getWinner(); // one player win
		std::cout << "The winner is: " << winner << std::endl;
		return true;
	}
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
		else if (willWin(0, i, 1, i, 2, i, value)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, i))
					return std::make_pair(j, i);
				j++;
			}
		}
		else if (willWin(0, i, 1, 1, 2, 2 - i, value) && (i != 0)) //check diagonals
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, j))
					return std::make_pair(j, j);
				j++;
			}
			while (j >= 0)
			{
				if (isEmpty(j, 2 - j))
					return std::make_pair(j, 2 - j);
				j--;
			}
		}
	}
	return std::make_pair(-1, -1);
}

std::pair<int, int> TicTacToe::chooseInitialMove(char value)
{
	for (int i = 0; i < N; i++)
	{
		if (findChanceToWin(i, 0, i, 1, i, 2, value)) //check rows
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(i, j))
					return std::make_pair(i, j);
				j++;
			}
		}
		else if (findChanceToWin(0, i, 1, i, 2, i, value)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, i))
					return std::make_pair(j, i);
				j++;
			}
		}
		else if (findChanceToWin(0, i, 1, 1, 2, 2 - i, value) && (i != 0)) //check diagonals
		{
			int j = 0;
			while (j < N)
			{
				if (isEmpty(j, j))
					return std::make_pair(j, j);
				j++;
			}
			while (j >= 0)
			{
				if (isEmpty(j, 2 - j))
					return std::make_pair(j, 2 - j);
				j--;
			}
		}
	}
	return std::make_pair(-1, -1);
}

void TicTacToe::moveAI(char value, char opponentValue)
{
	std::pair<int, int> notWillWin = std::make_pair(-1, -1); // it can be one part in witch i want to enter AI symbol
	if (checkWillWin(value) != notWillWin)
	{
	std::pair<int, int> coordinates = checkWillWin(value);
	insert(coordinates.first, coordinates.second, value);
	}
	else if (checkWillWin(opponentValue) != notWillWin)
	{
		std::pair<int, int> coordinates = checkWillWin(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else if (chooseInitialMove(value) != notWillWin)
	{
		std::pair<int, int> coordinates = chooseInitialMove(value);
		insert(coordinates.first, coordinates.second, value);
	}
	else
	{
		bool inserted = false;
		for (int i = 0; i < rows && !inserted; i++)
		{
			for (int j = 0; j < columns && !inserted; j++)
			{
				if (isEmpty(i, j))
				{
					insert(i, j, value);
					inserted = true;
				}
			}
		}
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