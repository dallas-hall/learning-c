#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ODD 0
#define EVEN 1

int even(int n);

int main(void)
{
	int i, prn;

	printf("# Generating Random Numbers & Checking If They Are Even\n");
	srand(time(NULL));

	for (i = 0; i < 10; i++) {
		prn = 1 + (rand() % 100);
		printf("Is %d even? %d.\n", prn, even(prn));
	}
	return EXIT_SUCCESS;
}

int even(int n)
{
	return n % 2 == 0 ? EVEN : ODD;
}
