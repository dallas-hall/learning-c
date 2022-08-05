#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int number, counter;
	double sum, average;

	sum = 0;
	counter = 0;

	printf("# Average Numbers Before Sentinal\n");
	printf("Enter integers to be averaged on a single line.\nThe value 9999 will signal the end of the number sequence.\n");
	scanf("%d", &number);
	while ( number != 9999) {
		sum += number;
		scanf("%d", &number);
		++counter;
	}

	average = sum / counter;
	printf("The average of all entered integers is: %.2f\n", average);
	return EXIT_SUCCESS;
}
