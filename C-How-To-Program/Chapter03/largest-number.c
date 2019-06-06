#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int limit = 10;
	float number, largest;

	printf("Enter %d numbers, 1 per line.\n", limit);
	for (int i = 0; i < limit; i++) {
		scanf("%f", &number);
		if (i == 0) {
			largest = number;
		}
		else {
			if (number > largest) {
				largest = number;
			}
		}
	}
	printf("The largest number was: %f\n", largest);
	return EXIT_SUCCESS;
}
