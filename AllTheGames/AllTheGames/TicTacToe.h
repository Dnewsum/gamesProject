// TicTacToe.h
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class TicTacToe {
public:
	TicTacToe();
	void playGame();

private:
	std::vector<std::vector<char>> board;
	int movesPlayed;

	void printBoard();
	void makeMove(char player);
	bool checkForWin(char player);
	bool isFull();
};
