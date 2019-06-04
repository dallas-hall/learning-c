#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int counter = 0;
	int total = 0;
	// The book suggests declaring these variables and not initialising them, but the compiler warns against this.
	int grade = 0;
	double average = 0;

	// Could easily replace this with a do while loop
	printf("Enter a grade, or -1 to end: ");
	scanf("%d", &grade);

	while (grade != -1) {
		total += grade;
		counter += 1;

	printf("Enter a grade, or -1 to end: ");
	scanf("%d", &grade);
	}

	if (counter != 0) {
		/*
		 * I explicitly casted this int to a float.
		 * C implicitly converts counter to a float under the hood, so this is a float / float operation.
		 * This operation is done in memory.
		 */
		average = (double) total / counter;
	} else {
		printf("No grades were entered.");
	}

	printf("%d grades were entered with a total of %d,\nAnd an average of %.2f.\n", counter, total, average);

	return EXIT_SUCCESS;
}
