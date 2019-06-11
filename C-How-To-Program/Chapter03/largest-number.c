#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int limit = 10;
	float number, largest, secondLargest, smallest;

	printf("Enter %d numbers, 1 per line.\n", limit);
	for (int i = 0; i < limit; i++) {
		scanf("%f", &number);
		if (i == 0) {
			largest = number;
			smallest = number;
		}
		else {
			if (number > largest) {
				secondLargest = largest;
				largest = number;
			}
			else if (number > secondLargest) {
				
				secondLargest = number;
			}
			else if (number < smallest) {
				smallest = number;
			}
		}
	}
	printf("The largest number was: %f\n", largest);
	printf("The second largest number was: %f\n", secondLargest);
	printf("The smallest number was: %f\n", smallest);
	return EXIT_SUCCESS;
}
