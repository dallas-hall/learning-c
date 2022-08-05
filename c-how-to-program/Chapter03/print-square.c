#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int size, spaces, stars;
	printf("Enter the squares size as an integer: ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	for(int i = 0; i < size; i++) {
		if( i == 0 || i == size - 1) {
			// We print the last star at the end of the loop.
			stars = size - 1;
			spaces = 0;
		}
		else {
			stars = 1;
			spaces = size - 2;
		}
		for(int j = 0; j < stars; j++) {
			printf("*");
		}
	
		for(int k = 0; k < spaces; k++) {
			printf(" ");
		}
		printf("*\n");
	}
	
	return EXIT_SUCCESS;
}
