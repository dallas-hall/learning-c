#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000

/*
 * https://en.wikipedia.org/wiki/Narcissistic_number
 * An Armstrong number is a number that is equal to the sum of their digits raised to the power of the number of digits in them.
 */
int main(void)
{
	unsigned int currentNumber;
	unsigned int currentNumberDigitAmount;
	unsigned int currentDigit;
	unsigned int total;

	printf("# Armstrong Numbers <= %d\n", LIMIT);

	for(unsigned int i = 0; i <= LIMIT; i++) {
		if(i == 0) {
			continue;
		}

		// Use division by 10 to remove digits and thus count the number of digits.
		currentNumber = i;
		currentNumberDigitAmount = 0;

		while(currentNumber != 0) {
			currentNumber /= 10;
			++currentNumberDigitAmount;
		}

		currentNumber = i;
		total = 0;
		// Go through all the digits invidiually and calcuate the power of currentDigit and currentNumberDigitAmount
		while (currentNumber != 0) {
			// Get the ones digit
			currentDigit = currentNumber % 10;

			// Calculate and add to total
			total += (unsigned int) (pow(currentDigit, currentNumberDigitAmount));

			// Remove the ones digit
			currentNumber /= 10;
		}

		// Check if Armstrong Number
		currentNumber = i;

		if (total == currentNumber) {
			printf("%u is an Armstrong Number.\n", currentNumber);
		}
	}

	puts("Done.");
	return EXIT_SUCCESS;
}
