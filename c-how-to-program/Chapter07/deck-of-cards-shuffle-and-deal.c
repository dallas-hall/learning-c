#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

/*
 * The 2d array deck[][] being passed is non-constant. The ordering is updated.
 * The bounds of a multi-dimensional array must be specified, except the first one.
 */
void shuffle(int deck[SUITS][FACES]);
/*
 * The 2d array deck[][] being passed is constant. It is read only.
 * The char array face[] being passed is constsant. It is reading the string pointers inside of it and not updating those strings.
 * The char array suit[] being passed is constsant. It is reading the string pointers inside of it and not updating those strings.
 *
 * C90 complains by sending a non-constant int array to a constant int array.
 */ 
void deal(const int deck[SUITS][FACES], const char *face[FACES], const char *suit[SUITS]);

int main(void)
{
	/*
	 * Create a constant char [] for card suit strings that will never change.
	 * Create a constant char [] for card face strings that will never change.
	 */ 
	const char *suit[SUITS] = {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};
	const char *face[FACES] = {
		"ACE", "DEUCE", "THREE",
		"FOUR", "FIVE", "SIX",
		"SEVEN", "EIGHT", "NINE",
		"TEN", "JACK", "QUEEN",
		"KING"
	};

	/*
	 * Create a 2d int array for all the suits and ranks.
	 * 0-3 is suits, the numbers correspond to suit.
	 * 0-12 is ranks, the numbers correspond to face
	 * Initialise everything to 0.
	 */ 
	int deck[SUITS][FACES] = {0};

	printf("# Basic Shuffle & Deal Playing Cards\n");
	shuffle(deck);
	deal(deck, face, suit);

	return EXIT_SUCCESS;
}

void shuffle(int deck[SUITS][FACES])
{
	int row, column, card;

	/*
	 * Seed rand so results are different each run.
	 */ 
	srand(time(0));

	printf("## Shuffling Cards\n");
	/*
	 * Process every card.
	 */ 
	for(card = 1; card <= CARDS; card++) {
		/*
		 * Choose a random location for each card.
		 * Keep searching until an unused slot is found. 0 means unused.
		 */ 
		do {
			/*
			 * Choose a random row between 0 and 3 - the card suits
			 * Choose a random column between 0 and 12 - the card faces
			 */ 
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);
		
		deck[row][column] = card;
	}

	printf("Done.\n");
}

void deal(const int deck[SUITS][FACES], const char *face[FACES], const char *suit[SUITS])
{
	int row, column, card;

	printf("## Dealing Cards\n");
	/*
	 * Process every card.
	 */ 
	for(card = 1; card <= 52; card++) {
		/*
		 * Process every card suit.
		 */ 
		for(row = 0; row < SUITS; row++) {
			/*
			 * Process every card face.
			 */ 
			for(column = 0; column < FACES; column++) {
				/*
				 * For each card in the deck:
				 * Check the suit[] for the matching suit.
				 * Check the face[] for the matching face.
				 * When a match is found, print it.
				 * Print a newline after every second card.
				 */ 
				if(deck[row][column] == card) {
					printf("%5s of %-8s%c", face[column], suit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
	printf("Done.\n");
}
