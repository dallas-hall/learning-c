#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int height, width, stars, innerSpaces, outerSpaces;
	printf("Enter the shape's height and width: ");
	scanf("%d %d", &height, &width);

	printf("# Printing shape 1, a rectangle.\n");
	outerSpaces = 0;
	innerSpaces = 0;
	stars = 10;

	for(int i = 0; i < height; i++) {
		if(i == 0 || i == height - 1) {
			stars = width - 1;
			innerSpaces = 0;
		}
		else {
			stars = 1;
			innerSpaces = width - 2;
		}
		for(int j = 0; j < stars; j++) {
			printf("*");
		}
		for(int k = 0; k < innerSpaces; k++) {
			printf(" ");
		}

		printf("*\n");
	}
	printf("\n");

	printf("# Printing shape 2, a circle.\n");
	for(int i = 0; i < height; i++) {
		if(i == 0 || i == height - 1) {
			// These magic numbers came from tweaking after viewing output. Works reasonably well.
			outerSpaces = (int) (width * .25);
			innerSpaces = 0;
			stars = (int) (width * .66) - 1;
			
		}
		else if(i == 1 || i == height - 2) {
			outerSpaces = 1;
			innerSpaces = width - 4; // To remove 2 stars and 2 outter spaces
			stars = 1;
		}
		else {
			outerSpaces = 0;
			innerSpaces = width - 2;
			stars = 1;
		}
		for(int j = 0; j < outerSpaces; j++) {
			printf(" ");
		}
		for(int k = 0; k < stars; k++) {
			printf("*");
		}
		for(int l = 0; l < innerSpaces; l++) {
			printf(" ");
		}
	
		printf("*\n");
	}

	printf("# Printing shape 3, an arrow.\n");
	for(int i = 0; i < height; i++) {
		if(i == 0) {
			outerSpaces = width / 2;
			innerSpaces = 0;
			stars = 1;
		}
		else if(i == 1) {
			outerSpaces = (width / 2) - 1;
			stars = 3;
		}
		else if(i == 2) {
			outerSpaces = (width / 2) - 2;
			stars = 5;
		}
		else {
			outerSpaces = (width / 2);
			stars = 1;
		}
		for(int j = 0; j < outerSpaces; j++) {
			printf(" ");
		}
		for(int k = 0; k < stars; k++) {
			printf("*");
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
