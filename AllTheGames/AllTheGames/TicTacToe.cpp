// TicTacToe.cpp
#include "TicTacToe.h"

// Constructor initializes the TicTacToe game board and sets the movesPlayed to 0
TicTacToe::TicTacToe() {
	board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
	movesPlayed = 0;
	std::srand(std::time(0));
}

// Main method that handles the game loop
void TicTacToe::playGame() {
	while (!isFull()) {
		printBoard();
		makeMove('X');
		if (checkForWin('X')) {
			std::cout << "Player wins!" << std::endl;
			break;
		}
		if (!isFull()) {
			makeMove('O');
			if (checkForWin('O')) {
				std::cout << "Computer wins!" << std::endl;
				break;
			}
		}
		else {
			std::cout << "It's a draw!" << std::endl;
		}
	}
	printBoard();
}

// Prints the current game board
void TicTacToe::printBoard() {
	for (const auto &row : board) {
		for (const auto &cell : row) {
			std::cout << '|' << cell;
		}
		std::cout << "|\n";
	}
	std::cout << std::endl;
}

// Handles the player's or computer's move
void TicTacToe::makeMove(char player) {
	int row, col;
	bool isValidMove = false;

	while (!isValidMove) {
		if (player == 'X') {
			std::cout << "Enter the row and column (1-3) to make your move: ";
			std::cin >> row >> col;

			// Validate user input
			if (std::cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter valid numbers between 1 and 3." << std::endl;
				continue;
			}

			row--;
			col--;
		}
		else {
			// Computer randomly chooses a cell
			row = std::rand() % 3;
			col = std::rand() % 3;
		}

		// Check if the cell is empty
		if (board[row][col] == ' ') {
			board[row][col] = player;
			movesPlayed++;
			isValidMove = true;
		}
		else if (player == 'X') {
			std::cout << "Invalid move. Try again." << std::endl;
		}
	}
}

// Checks if the given player has won
bool TicTacToe::checkForWin(char player) {
	// Check rows and columns for a win
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
	}
	// Check diagonals for a win
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
	return false;
}

// Checks if the game board is full
bool TicTacToe::isFull() {
	return movesPlayed == 9;
}


