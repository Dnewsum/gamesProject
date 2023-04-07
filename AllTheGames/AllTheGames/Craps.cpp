#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate rolling a dice
int roll_dice() {
	// generate a random number between 1 and 6
	return rand() % 6 + 1;
}

// Function to play a single game of craps
int play_craps(int bet, int &money) {
	int point = 0;
	// Roll the dice twice and sum the results
	int roll = roll_dice() + roll_dice();
	cout << "You rolled " << roll << endl;

	// Check if the player wins on the first roll
	if (roll == 7 || roll == 11) {
		cout << "You win!" << endl;
		money += bet;
		return 1;
	}
	// Check if the player loses on the first roll
	else if (roll == 2 || roll == 3 || roll == 12) {
		cout << "You lose!" << endl;
		money -= bet;
		return -1;
	}
	// Continue rolling until the player wins or loses
	else {
		cout << "Your point is " << roll << endl;
		point = roll;
		do {
			roll = roll_dice() + roll_dice();
			cout << "You rolled " << roll << endl;
			if (roll == 7) {
				cout << "You lose!" << endl;
				money -= bet;
				return -1;
			}
		} while (roll != point);
		cout << "You win!" << endl;
		money += bet;
		return 1;
	}
}

int crappsCall() {
	srand(time(NULL));
	int money = 50;
	int bet = 0;
	char choice = 'y';
	cout << "Welcome to the craps game!" << endl;
	do {
		cout << "You have $" << money << ". Place your bet (max $" << money << "): ";
		while (!(cin >> bet) || bet > money || bet <= 0) { // Check if input is valid
			cin.clear(); // Clear any error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
			cout << "Invalid input. Please enter a valid bet amount (max $" << money << "): ";
		}
		int result = play_craps(bet, money);
		cout << "You now have $" << money << endl;
		if (money == 0) {
			cout << "You are out of money. Game over." << endl;
			break;
		}
		cout << "Do you want to play again (y/n)? ";
		cin >> choice;
	} while (choice == 'y');
	cout << "Your final amount of money is $" << money << endl;
	return 0;
}
