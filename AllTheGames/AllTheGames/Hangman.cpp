// Hangman.cpp
#include "Hangman.h"

// Constructor, initializes the game with a word list from a file
Hangman::Hangman(const std::string &filename) {
	loadWords(filename); // Load words from the given file
	secretWord = pickRandomWord(); // Pick a random word as the secret word
	guessedWord = std::string(secretWord.size(), '*'); // Initialize the guessed word with asterisks
	incorrectGuesses = 0; // Set the initial count of incorrect guesses to 0
	maxIncorrectGuesses = 7; // Set the maximum allowed incorrect guesses to 7
	std::srand(std::time(0)); // Seed the random number generator
}

// Main game loop
void Hangman::playGame() {
	// Continue the game until the maximum incorrect guesses are reached or the game is won
	while (incorrectGuesses < maxIncorrectGuesses && !isGameWon()) {
		std::cout << "Secret word: " << guessedWord << std::endl;
		std::cout << "Incorrect guesses: " << incorrectGuesses << std::endl;

		char guess;
		std::cout << "Enter your guess: ";
		std::cin >> guess;

		// Validate the guess and update the guessed word if valid
		if (isGuessValid(guess)) {
			updateGuessedWord(guess);
		}
		else {
			incorrectGuesses++; // Increment incorrect guesses count if the guess is invalid
		}
	}

	// Display the game result
	if (isGameWon()) {
		std::cout << "Congratulations! You won! The secret word was: " << secretWord << std::endl;
	}
	else {
		std::cout << "You lost! The secret word was: " << secretWord << std::endl;
	}
}

// Load words from a file into the words vector
void Hangman::loadWords(const std::string &filename) {
	std::ifstream file(filename);
	std::string word;
	while (file >> word) {
		words.push_back(word);
	}
}

// Pick a random word from the words vector
std::string Hangman::pickRandomWord() {
	int index = std::rand() % words.size();
	return words[index];
}

// Check if the guess is valid (i.e., the guessed character is in the secret word)
bool Hangman::isGuessValid(char guess) {
	return secretWord.find(guess) != std::string::npos;
}

// Update the guessed word with the correctly guessed character
void Hangman::updateGuessedWord(char guess) {
	for (size_t i = 0; i < secretWord.size(); i++) {
		if (secretWord[i] == guess) {
			guessedWord[i] = guess;
		}
	}
}

// Check if the game is won (i.e., the guessed word is the same as the secret word)
bool Hangman::isGameWon() {
	return guessedWord == secretWord;
}
