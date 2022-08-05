#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Need -lm in the compiler flags

#define DIVISOR 10
#define BASE 2
#define START_EXPONENT 0

unsigned int myPower(unsigned int exponent, unsigned int base);

int main(void)
{
	/*
	 * https://www.mathsisfun.com/binary-number-system.html - Convert binary to decimal.
	 * This program handles 1 byte only, so numbers between 0 - 255.
	 * Any numbers missing are presumed 0.
	 */
	 // Can easily store an 8 digit number.
	unsigned int binaryDigits;
	unsigned int currentBinaryDigit;
	unsigned int decimalNumber;
	unsigned short currentExponent = START_EXPONENT;

	decimalNumber = 0;

	puts("# Binary To Decimal");
	do {
		printf("Enter a binary number, up to 8 digits (11111111). Missing leading digits are assumed as 0.\n");
		scanf("%d", &binaryDigits);
	}
	// Basic shitty test. Program probably is undefined on non-numeric inputs.
	while (binaryDigits > 11111111);
	printf("Base2 %u", binaryDigits);

	// We only try extracting digits if there is at least one 1 in the byte. If not, it is just 0.
	if(binaryDigits) {
		do {
			// Use modulo to extract the digit
			currentBinaryDigit = binaryDigits % DIVISOR;

			// Use division to remove the extract digit for the next run.
			binaryDigits /= DIVISOR;

			// If necessary, add the current power of 2 to the decimal total.
			if(currentBinaryDigit == 1) {
				// math.h pow uses doubles. Need brackets for precedence. needs -lm in compiler flags.
				//decimalNumber += ((unsigned int) (pow(BASE, currentExponent)));
				decimalNumber += ((unsigned int) (myPower(BASE, currentExponent)));
			}
			++currentExponent;
		}
		while(binaryDigits != 0);
	}

	printf(" is Base10 %d.\n", decimalNumber);
	return EXIT_SUCCESS;
}

unsigned int myPower(unsigned int base, unsigned int exponent)
{
	unsigned int result = 1;

	// The base case is when the base number is 0, always return 1.
	if (exponent != 0) {
		for (unsigned int i = 0; i < exponent; i ++) {
			result *= base;
		}
	}

	return result;
}
