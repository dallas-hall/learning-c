#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_OF_GAMES 1000

/*
 * enums are sequential constant values that by default start at 0 and increment by 1.
 * You can make them start at whatever number you like.
 */
enum Status {
	CONTINUE,
	WON,
	LOST
};

enum Bet {
	PASS, // Bet on the round winning
	DONT_PASS // Bet on the round losing
};

int rollDice(void);
void printWinningRounds(int winningRounds[], size_t length);
void printLosingRounds(int losingRounds[], size_t length);

int main(void)
{
	int roll, dieRollSum, gamePoint;
	enum Status gameStatus;
	int gamesWonRolls[21] = {0};
	int gamesLostRolls[21] = {0};

	printf("# Basic Craps Game.\n");
	/*
	 * Seed rand() so it doesn't roll consecutive numbers.
	 * Seed it with the number of seconds since the Unix Epoch.
	 */
	srand((unsigned int) time(NULL));

	/*
	 * https://en.wikipedia.org/wiki/Craps#Rules_of_play
	 * http://www.fastodds.com/game-rules/craps.htm
	 * https://www.mastersetter.com/craps/#learncraps
	 *
	 * Play n amount of games.
	 * Record how many games were won between the 1 and 20 rolls, or 20 or greater.
	 * Record how many games were lost between the 1 and 20 rolls, or 20 or greater.
	 */
	for(int i = 0; i < AMOUNT_OF_GAMES; i++) {
		enum Bet currentBet;
		int prn = 1 + rand() % 10;
		// Make a bet on the round winning or losing. Not currently being used,
		if (prn <= 5) {
			currentBet = PASS;
		}
		else {
			currentBet = DONT_PASS;
		}

		// First roll
		roll = 0;
		gamePoint = 0;
		dieRollSum = rollDice();

		switch(dieRollSum) {
			case 7:
			case 11:
				gameStatus = WON;
				/*
				if (currentBet == PASS) {
					// Win on the first roll
					gameStatus = WON;
				}
				else {
					// Lose on the first roll
					gameStatus = LOST;
				}*/
				break;
			case 2:
			case 3:
			case 12:
				gameStatus = LOST;
				/*
				if (currentBet == PASS) {
					// Win on the first roll
					gameStatus = WON;
				}
				else {
					// Lose on the first roll
					gameStatus = LOST;
				}
				*/
				break;
				/* Re-roll, if you re-roll the same number you win. */
			default:
				gameStatus = CONTINUE;
				gamePoint = dieRollSum;
				break;
		}
		++roll;

		// Keep rolling, try to roll the Point number before a 7
		while (CONTINUE == gameStatus) {
			dieRollSum = rollDice();
			++roll;

			if (gamePoint == dieRollSum) {
				gameStatus = WON;
			}
			else if (dieRollSum == 7){
				gameStatus = LOST;
			}
		}

		if (WON == gameStatus) {
			if (roll < 21) {
				// Increment the roll that won, <= 20 only
				++gamesWonRolls[roll - 1];
			}
			else {
				// Increment the roll that won, >= 21 only
				++gamesWonRolls[20];
			}
		}
		else {
			if (roll < 21) {
				// Increment the roll that lost, <= 20 only
				++gamesLostRolls[roll - 1];
			}
			else {
				// Increment the roll that lost, >= 21 only
				++gamesLostRolls[20];
			}
		}
	}

	printWinningRounds(gamesWonRolls, 21);
	printLosingRounds(gamesLostRolls, 21);
	return EXIT_SUCCESS;
}

int rollDice(void)
{
	int dice1 = 1 + rand() % 6;
	int dice2 = 1 + rand() % 6;
	int dieSum =  dice1 + dice2;

	return dieSum;
}

void printWinningRounds(int winningRounds[], size_t length)
{
	for (size_t i = 0; i < length; i++) {
		printf("Winning games on roll %lu is %d.\n", i + 1, winningRounds[i]);
	}
}

void printLosingRounds(int losingRounds[], size_t length)
{
	for (size_t i = 0; i < length; i++) {
		printf("Losing games on roll %lu is %d.\n", i + 1, losingRounds[i]);
	}
}


