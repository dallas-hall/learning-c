#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>

void signalHandler(int signalValue);

int main(void)
{
	int i, n, print;

	puts("# Signal Handling Example");

	signal(SIGINT, signalHandler);
	srand(time(NULL));

	printf("[");
	print = 0;
	for(i = 0; i < 100; i++) {
		++print;
		/*
		 * Random number between 0 and 50
		 */ 
		n = rand() % 50;

		if(n == 25) {
			raise(SIGINT);
		}

		printf("%2d, ", n);

		if(print % 10 == 0 && i != 99) {
			printf("\n");
		}
	}
	/*
	 * Use backspace to delete the last , and space
	 */ 
	printf("\b\b]\n");

	return EXIT_SUCCESS;
}


void signalHandler(int signalValue)
{
	char c;

	do {
		printf("\nInterupt signal %d received.\nDo you want to continue? (y/n)\n", signalValue);
		scanf("%c", &c);
	}
	while(tolower(c) != 'y' && tolower(c) != 'n');

	if(tolower(c) == 'y') {
		signal(SIGINT, signalHandler);
	}
	else {
		exit(EXIT_SUCCESS);
	}
}
