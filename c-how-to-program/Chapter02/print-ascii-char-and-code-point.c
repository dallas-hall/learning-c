#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int startUpperCase = 65;
	int endUpperCase = startUpperCase + 25;
	int startLowerCase = 97;
	int endLowerCase = startLowerCase + 25;
	int startNumber = 48;
	int endNumber = startNumber + 9;
	int row = 1;

	printf("# Printing Upper Case ASCII\n");
	for (int i = startUpperCase; i <= endUpperCase; i++) {
		printf("%d:%c\t", i, i);
		if (row % 10 == 0) {
			printf("\n");
		}
		row++;
	}
	printf("\n\n");
	row = 1;

	printf("# Printing Lower Case ASCII\n");
	for (int i = startLowerCase; i <= endLowerCase; i++) {
		printf("%d:%c\t", i, i);
		if (row % 10 == 0) {
			printf("\n");
		}
		row++;
	}
	printf("\n\n");
	row = 1;

	printf("# Printing Numbers ASCII\n");
	for (int i = startNumber; i <= endNumber; i++) {
		printf("%d:%c\t", i, i);
		if (row % 10 == 0) {
			printf("\n");
		}
		row++;
	}
	printf("\n");

	return EXIT_SUCCESS;
}
