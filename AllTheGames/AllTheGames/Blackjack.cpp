#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

// Define the card structure
struct Card {
	string suit;
	string rank;
	int value;
};

// Define the deck structure
struct Deck {
	vector<Card> cards;
	int top;
};

// Initialize a new deck of 52 cards
Deck newDeck() {
	Deck deck;
	string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
	int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card card = { suits[i], ranks[j], values[j] };
			deck.cards.push_back(card);
		}
	}
	deck.top = 0;
	return deck;
}

// Shuffle the cards in the deck using this random generation built in thing
void shuffleDeck(Deck& deck) {
	random_device rd;
	mt19937 g(rd());
	shuffle(deck.cards.begin(), deck.cards.end(), g);
	deck.top = 0;
}

// Deal a card from the top of the deck and add it to a hand
void dealCard(Deck& deck, vector<Card>& hand) {
	hand.push_back(deck.cards[deck.top]);
	deck.top++;
}

// Calculate the total value of a hand
int calculateHandValue(vector<Card>& hand) {
	int total = 0;
	int numAces = 0;
	for (int i = 0; i < hand.size(); i++) {
		total += hand[i].value;
		if (hand[i].rank == "Ace") {
			numAces++;
		}
	}
	while (numAces > 0 && total > 21) {
		total -= 10;
		numAces--;
	}
	return total;
}

// Print a card in a nice format
void printCard(Card card) {
	cout << card.rank << " of " << card.suit;
}

// Print a hand in a nice format
void printHand(vector<Card>& hand) {
	for (int i = 0; i < hand.size(); i++) {
		printCard(hand[i]);
		cout << ", ";
	}
	cout << "Total: " << calculateHandValue(hand) << endl;
}

// Check if a hand has a blackjack 
bool hasBlackjack(vector<Card>& hand) {
	if (hand.size() != 2) {
		return false;
	}
	if (hand[0].rank == "Ace" && (hand[1].value == 10 || hand[1].rank == "10")) {
		return true;
	}
	if (hand[1].rank == "Ace" && (hand[0].value == 10 || hand[0].rank == "10")) {
		return true;
	}
	return false;
}

// The main function for playing the game
int blackjack() {
	// Initialize a new deck and shuffle it
	Deck deck = newDeck();
	shuffleDeck(deck);

	// Start the game by dealing 2 cards

	// Create the player and computer hands
	vector<Card> playerHand;
	vector<Card> computerHand;

	// Deal 2 cards to each hand
	dealCard(deck, playerHand);
	dealCard(deck, computerHand);
	dealCard(deck, playerHand);
	dealCard(deck, computerHand);

	// Print the initial hands
	cout << "Player hand: ";
	printHand(playerHand);
	cout << "Computer hand: ";
	cout << "<hidden card>, ";
	printCard(computerHand[1]);
	cout << endl;

	// Check for player blackjack
	if (hasBlackjack(playerHand)) {
		cout << "Blackjack!" << endl;
		return 0;
	}

	// Player turn
	char choice;
	while (true) {
		cout << "Do you want to hit (H) or stand (S)? ";
		cin >> choice;
		choice = toupper(choice); // Convert user input to uppercase
		if (choice == 'H') {
			dealCard(deck, playerHand);
			cout << "Player hand: ";
			printHand(playerHand);
			if (calculateHandValue(playerHand) > 21) {
				cout << "Bust! You lose." << endl;
				return 0;
			}
		}
		else if (choice == 'S') {
			break;
		}
		else {
			cout << "Invalid input. Please enter 'H' or 'S'." << endl;
		}
	}

	// Computer turn
	cout << "Computer hand: ";
	printHand(computerHand);
	while (calculateHandValue(computerHand) <= 17) {
		dealCard(deck, computerHand);
		cout << "Computer hits: ";
		printCard(computerHand.back());
		cout << endl;
		if (calculateHandValue(computerHand) > 21) {
			cout << "Computer busts! You win." << endl;
			return 0;
		}
	}

	// Evaluate who won the game
	int playerValue = calculateHandValue(playerHand);
	int computerValue = calculateHandValue(computerHand);
	cout << "Player hand: ";
	printHand(playerHand);
	cout << "Computer hand: ";
	printHand(computerHand);
	if (playerValue > computerValue || computerValue > 21) {
		cout << "You win!" << endl;
	}
	else if (playerValue < computerValue) {
		cout << "You lose." << endl;
	}
	else {
		cout << "Push." << endl;
	}

}
