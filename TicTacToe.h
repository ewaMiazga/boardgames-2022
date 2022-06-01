#pragma once
#include <iostream>
#include <utility>
#include <random>
#include <vector>
#include "Games.h"

#define N 3
#define rows  3
#define columns 3
#define emptySquare '_'

#define findWin(row1, col1, row2, col2, row3, col3) ((board[row1][col1] == board[row2][col2]) && (board[row2][col2] == board[row3][col3]) && (board[row1][col1] != emptySquare))

#define willWin(row1, col1, row2, col2, row3, col3, value) ((board[row1][col1] == board[row2][col2] && board[row1][col1] == value) || (board[row2][col2] == board[row3][col3] && board[row3][col3] == value) || (board[row1][col1] == board[row3][col3] && board[row1][col1] == value))

#define findChanceToWin(row1, col1, row2, col2, row3, col3, value) (((board[row1][col1] == value) && (board[row2][col2] == board[row3][col3] && board[row2][col2] == emptySquare)) || ((board[row2][col2] == value) && (board[row1][col1] == board[row3][col3] && board[row1][col1] == emptySquare))  || ((board[row3][col3] == value) && (board[row2][col2] == board[row1][col1] && board[row2][col2] == emptySquare)))

#define findEmptyLine(row1, col1, row2, col2, row3, col3)  ((board[row1][col1] == board[row2][col2]) && (board[row2][col2] == board[row3][col3]) && (board[row1][col1] == emptySquare))

class TicTacToe:public Games
{
private:
	char board[rows][columns];
public:
	TicTacToe();

	~TicTacToe();

	bool isEmpty(int row, int column);

	void insert(int row, int column, char value);

	char getWinner();

	bool isFullBoard();

	bool gameOver();

	std::pair<int, int> checkWillWin(char value);

	std::pair<int, int> chooseSecondMove(char value);

	std::pair<int, int> emptyLineFullOpponentSq(char value);

	std::pair<int, int> defaultMove();

	void moveAIHard(char value, char opponentValue);

	void moveAIMedium(char value, char opponentValue);

	void moveAIEasy(char value, char opponentValue);

	int chooseStartingPlayer();

	void display() override;

	void play() override;
};