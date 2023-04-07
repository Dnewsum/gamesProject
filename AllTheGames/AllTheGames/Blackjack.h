#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

struct Card {
	std::string suit;
	std::string rank;
	int value;
};

struct Deck {
	std::vector<Card> cards;
	int top;
};

Deck newDeck();

void shuffleDeck(Deck& deck);

void dealCard(Deck& deck, std::vector<Card>& hand);

int calculateHandValue(std::vector<Card>& hand);

void printCard(Card card);

void printHand(std::vector<Card>& hand);

bool hasBlackjack(std::vector<Card>& hand);

int blackjack();
