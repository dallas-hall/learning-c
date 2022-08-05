#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int height, middle, spaces, stars;
	printf("# Diamond Printing\nEnter height of diamond. Even numbers will be converted to odd (+1): ");
	scanf("%d", &height);
	middle = (height / 2) + 1;
	if (height % 2 == 0) {
		height++;
	}

	spaces = 0;
	stars = 0;
	for (int i = 0; i < height; i++) {
	if (i == 0 || i == height - 1) {
			// Need middle - 1 because the number of stars at the start and end is always this.
			spaces = middle - 1;
			stars = 1;
		}
		// Need middle - 1 because we start at 0
		else if (i < middle - 1) {
			spaces -= 1;
			stars += 2;
		}
		else if (i == middle - 1) {
			spaces = 0;
			// The number of stars in the middle is always this.
			stars = middle + (middle - 1);
		}
		else {
			spaces += 1;
			stars -= 2;
		}

		for (int j = 0; j < spaces; j++) {
			printf(" ");
		}

		for (int k = 0; k < stars; k++) {
			printf("*");
		}

		printf("\n");
	}
	return EXIT_SUCCESS;
}
