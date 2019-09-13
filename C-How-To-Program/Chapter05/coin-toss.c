#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

int main(void)
{
	int headsCount, tailsCount, prn;
	headsCount = 0;
	tailsCount = 0;
	
	enum CoinFace {
		HEADS,
		TAILS
	};

	puts("# Coin Tossing Distribution");

	for (unsigned int i = 0; i < LIMIT; i++) {
		// Random number between 0 and 1 inclusive
		prn = rand() % 2;
		printf("Current coin face is %s\n", prn == 0? "Heads": "Tails");

		if(prn == HEADS) {
			++headsCount;
		}
		else {
			++tailsCount;
		}
	}

	printf("Total number of heads was %d\n", headsCount);
	printf("Total number of tails was %d\n", tailsCount);

	return EXIT_SUCCESS;
}
