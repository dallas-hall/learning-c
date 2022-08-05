#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int width;
	printf("Enter the width of the triangle to print: ");
	scanf("%d", &width);
	
	printf("# Triangle 1\n");
	for (int i = 0, stars = 1; i < width; i++, stars++) {
		for (int j = 0; j < stars; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n# Triangle 2\n");
	for (int i = 0, stars = width; i < width; i++, stars--) {
		for (int j = 0; j < stars; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n# Triangle 3\n");
	for (int i = 0, stars = width, spaces = 0; i < width; i++, stars--, spaces++) {
		for (int j = 0; j < spaces; j++) {
			printf(" ");
		}

		for (int k = 0; k < stars; k++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n# Triangle 4\n");
	for (int i = 0, spaces = width - 1, stars = 1; i < width; i++, spaces--, stars++) {
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
