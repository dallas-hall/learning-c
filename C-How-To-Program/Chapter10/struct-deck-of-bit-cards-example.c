#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CARDS_IN_DECK 52
#define FACES_IN_DECK 13
#define SUITS_IN_DECK 4
#define SHUFFLE_AMOUNT 3

/*
 * Declare a stucture that has 2 members.
 * All members have defined an exact amount of bits used for storage.
 */
struct bitCard {
	unsigned face : 4; /* Can hold 0 (0000) to 15 (1111) */ 
	unsigned suit : 2; /* 0 (00) to 3 (11) */
	unsigned colour : 1; /* 0 (0) to 1 (1) */
};

/*
 * Create an alias for struct card which called Card.
 * Everytime we use Card, we really mean struct card.
 */
typedef struct bitCard Card;

void createDeck(Card* const deck);
void shuffleDeck(Card* const deck, int shuffleAmount);
void dealDeck(const Card* const deck, const char* faces[], const char *suits[], const char *colours[]);

int main(void)
{
	Card deck[52];

	/*
	 * Create a constant char [] for card suit strings that will never change.
	 * Create a constant char [] for card face strings that will never change.
	 */
	const char *faces[] = {
		"ACE", "DEUCE", "THREE",
		"FOUR", "FIVE", "SIX",
		"SEVEN", "EIGHT", "NINE",
		"TEN", "JACK", "QUEEN",
		"KING"
	};

	const char *suits[] = {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};
	
	const char *colours[] = {"RED", "BLACK"};

	/*
	 * Randomise rand() with the seconds since the Unix Epoch, unformatted.
	 */
	srand(time(NULL));
	puts("# Bit Card Deck - struct example");
	puts("## Create Deck & Deal Unshuffled Deck");
	createDeck(deck);
	dealDeck(deck, faces, suits, colours);
	printf("\n## Shuffle Deck %d Times", SHUFFLE_AMOUNT);
	shuffleDeck(deck, SHUFFLE_AMOUNT);
	puts("\n## Deal Shuffled Deck");
	dealDeck(deck, faces, suits, colours);

	return EXIT_SUCCESS;
}

void createDeck(Card* const deck)
{
	int i;

	for(i = 0; i < CARDS_IN_DECK; i++) {
		/*
		 * i % 13 will return a number between 0 and 12, which is 13, the amount of indices the faces array has.
		 * i / 13 will return a number between 0 and 3, which is 4, the amount of indices the suits array has.
		 * i / 26 will return a number between 0 and 1, which is 2, the amount of indiecs the colours array has.
		 * Because we are going from 0 to 51, we will initialise all cards in the deck.
		 */
		deck[i].face = (unsigned) i % FACES_IN_DECK;
		deck[i].suit = (unsigned) i / FACES_IN_DECK;
		deck[i].colour = (unsigned) i / (CARDS_IN_DECK / 2);  
	}
}

void shuffleDeck(Card* const deck, int shuffleAmount)
{
	int i, j, k;
	Card tempCard;

	/*
	 * Shuffle the cards n times.
	 */ 
	for(i = 0; i < shuffleAmount; i++) {
		for(j = 0; j < CARDS_IN_DECK; j++) {
			/*
		 	* A random number between 0 and 51, to get a random card.
		 	*/
			k = rand() % 52;

			/*
		 	* Loop through the entire deck and swap each card with another card.
		 	*/
			tempCard = deck[j];
			deck[j] = deck[k];
			deck[k] = tempCard;
		}
	}
}

void dealDeck(const Card* const deck, const char* faces[], const char *suits[], const char *colours[])
{
	int i, cardsPerLine;

	cardsPerLine = 4;
	/*
	 * Print every card in the deck. n per line.
	 */ 
	for (i = 0; i < CARDS_IN_DECK; i++) {
		printf("A %5s %5s of %-8s%s", colours[deck[i].colour], faces[deck[i].face], suits[deck[i].suit], (i + 1) % cardsPerLine ? "\t" : "\n");
	}
}
