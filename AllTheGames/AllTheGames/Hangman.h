// Hangman.h
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

class Hangman {
public:
	Hangman(const std::string &filename);
	void playGame();

private:
	std::vector<std::string> words;
	std::string secretWord;
	std::string guessedWord;
	int incorrectGuesses;
	int maxIncorrectGuesses;

	void loadWords(const std::string &filename);
	std::string pickRandomWord();
	bool isGuessValid(char guess);
	void updateGuessedWord(char guess);
	bool isGameWon();
};
