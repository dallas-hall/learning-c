#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * https://en.wikipedia.org/wiki/Floyd%27s_triangle - Floyd's Triangle is a right-angled triangluar array of natural numbers.
	 * https://www.mathsisfun.com/definitions/natural-number.html - A natural number is a positive integer only. Sometimes includes 0.
	 * Row 1 is 1.
	 * Row 2 is 2, 3
	 * Row 3 is 4, 5, 6
	 * etcetera
	 */

	int n = 1;
	int lines;

	puts("# Floyd's Triangle");
	printf("Enter how many lines of Floyd's Triangle to print: ");
	scanf("%d", &lines);

	for (int i = 0; i < lines; i++) {
		int numbersToPrint = i + 1;
		printf("[");
		for (int j = 0; j < numbersToPrint; j++) {
			printf("%d, ", n);
			++n;
		}
		// Remove the last space and comma and replace with a ]
		printf("\b\b]\n");
	}

	return EXIT_SUCCESS;
}
