// AllTheGames.cpp : This file contains the 'main' function. Program execution begins and ends there.
// I used GeeksForGeeks.com for all of these program for help.
// Daniel Newsum

#include <iostream>
#include "Blackjack.h"
#include "craps.h"
#include "Hangman.h"
#include "TicTacToe.h"

int main()
{
	int choice = 0;
	std::cout << "Please pick one of the games to play: " << std::endl;
	std::cout << "1. Blackjack" << std::endl;	
	std::cout << "2. Craps" << std::endl;
	std::cout << "3. Hangman" << std::endl;
	std::cout << "4. TicTacToe" << std::endl;
	std::cout << "5. Quit" << std::endl;

	while (choice != 5)
	{
		std::cin >> choice;
		if (choice==1)
		{
			blackjack();
			choice = 0;
			std::cout << endl;
			std::cout << "Please pick one of the games to play: " << std::endl;
			std::cout << "1. Blackjack" << std::endl;
			std::cout << "2. Craps" << std::endl;
			std::cout << "3. Hangman" << std::endl;
			std::cout << "4. TicTacToe" << std::endl;
			std::cout << "5. Quit" << std::endl;
			
		}
		else if (choice==2)
		{
			int money = 50; // starting amount of money
			int bet = 0;
			crappsCall();
			choice = 0;
			std::cout << endl;
			std::cout << "Please pick one of the games to play: " << std::endl;
			std::cout << "1. Blackjack" << std::endl;
			std::cout << "2. Craps" << std::endl;
			std::cout << "3. Hangman" << std::endl;
			std::cout << "4. TicTacToe" << std::endl;
			std::cout << "5. Quit" << std::endl;
			
			
		}
		else if (choice == 3)
		{
			string fileName = "text1.txt";
			Hangman hangmanGame(fileName);
			hangmanGame.playGame();
			choice = 0;
			std::cout << endl;
			std::cout << "Please pick one of the games to play: " << std::endl;
			std::cout << "1. Blackjack" << std::endl;
			std::cout << "2. Craps" << std::endl;
			std::cout << "3. Hangman" << std::endl;
			std::cout << "4. TicTacToe" << std::endl;
			std::cout << "5. Quit" << std::endl;
			
		}
		else if (choice == 4)
		{
			TicTacToe game;
			game.playGame();
			
			choice = 0;
			std::cout << endl;
			std::cout << "Please pick one of the games to play: " << std::endl;
			std::cout << "1. Blackjack" << std::endl;
			std::cout << "2. Craps" << std::endl;
			std::cout << "3. Hangman" << std::endl;
			std::cout << "4. TicTacToe" << std::endl;
			std::cout << "5. Quit" << std::endl;
			

		}
		else if (choice == 5)
		{
			return 0;
		}
		else {
			std::cout << "Please enter a valid choice" << std::endl;
			return 0;
		}
	}
}

