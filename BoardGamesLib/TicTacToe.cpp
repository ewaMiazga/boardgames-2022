#include <algorithm>
#include "TicTacToe.h"

TicTacToe::TicTacToe(std::string lvl): lvl(lvl)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
        {
            board[i][j] = '_';
        }
}

bool TicTacToe::isEmpty(int row, int column)
{
	if (board[row][column] == emptySquare)
		return true;
	return false;
}

void TicTacToe::insert(int row, int column, char value)
{
	while (isEmpty(row, column))
    {
        board[row][column] = value;
    }
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
		return true;
	}
	else if (!isFullBoard()) // continue to play
		return false;
	else
	{
		winner = ' '; // tie
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
	}
	return std::make_pair(-1, -1);
}

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
			j--;
			return std::make_pair(i, j);

		}
		if (findEmptyLine(0, i, 1, i, 2, i)) // check columns
		{
			int j = 0;
			while (j < N)
			{
				if (chooseSecondMove(value) != notWillWin && chooseSecondMove(value) == std::make_pair(j, i))
					return std::make_pair(j, i);
				j++;
			}
			j--;
			return std::make_pair(i, j);
		}
		if (findEmptyLine(0, i, 1, 1, 2, 2 - i) && (i != 1)) //check diagonals
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
			j--;
			return std::make_pair(i, j);
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

void TicTacToe::moveAIHard(char value, char opponentValue)
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

void TicTacToe::moveAIMedium(char value, char opponentValue)
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
	else if (chooseSecondMove(opponentValue) != notWillWin)
	{
		std::pair<int, int> coordinates = chooseSecondMove(opponentValue);
		insert(coordinates.first, coordinates.second, value);
	}
	else
	{
		std::pair<int, int> coordinates = defaultMove();
		insert(coordinates.first, coordinates.second, value);
	}
}

void TicTacToe::moveAIEasy(char value, char opponentValue)
{
	std::pair<int, int> coordinates = defaultMove();
	insert(coordinates.first, coordinates.second, value);
}

int TicTacToe::chooseStartingPlayer()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::vector nums = { 0, 1 };
	std::shuffle(std::begin(nums), std::end(nums), g);
	return nums[0];
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
		if (lvl == "easy")
			moveAIEasy('O', 'X');
		else if (lvl == "medium")
			moveAIMedium('O', 'X');
		else if (lvl == "hard")
			moveAIHard('O', 'X');
}

char TicTacToe::getValue(int column, int row)
{
    return board[column][row];
}
