#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is4DigitsOrLess(unsigned short int);
unsigned short int getNumberOfDigits(unsigned short int);
unsigned short int encrypt(unsigned short int);
unsigned short int decrypt(unsigned short int);

static bool debugging = false;

int main(void)
{
	unsigned short int input, ciphertext, plaintext;

	puts("# Dodgy Encrypt / Decrypt");
	do {
		// Non-digits become 0.
		printf("Enter a 4 digit integer: ");
		scanf("%hu", &input);
	} while(!is4DigitsOrLess(input));

	ciphertext = encrypt(input);
	printf("ciphertext is %hu\n", ciphertext);

	plaintext = decrypt(ciphertext);
	printf("plaintext is %hu\n", plaintext);
	printf("original number is %hu\n", input);

	return EXIT_SUCCESS;
}

/*
 * Check if the input is only 4 digits or less.
 */
bool is4DigitsOrLess(unsigned short int n)
{
	int digitCount = 0;

	while(n != 0) {
		++digitCount;
		n /= 10;
	}

	if(digitCount > 4) {
		fprintf(stderr, "[ERROR] Number greater than 4 digits.\n");
		return false;
	}
	else {
		return true;
	}
}

unsigned short int getNumberOfDigits(unsigned short int n)
{
	unsigned short int digitCount = 0;

	while(n != 0) {
		++digitCount;
		n /= 10;
	}

	return digitCount;
}

/*
 * Encryption scheme
 * 1) Read in 4 digit number
 * 2) Replace each digit with (originalDigit + 7) % 10
 * 3) Swap 1st and 3rd digits and 2nd and 4th digits.
 */
unsigned short int encrypt(unsigned short int n)
{
	unsigned short int firstDigit, secondDigit, thirdDigit, fourthDigit, swapDigit, digitCount, currentNumber, currentDigit;

	// Padding with zereos if necessary.
	firstDigit = 0;
	secondDigit = 0;
	thirdDigit = 0;
	fourthDigit = 0;

	currentNumber = n;
	digitCount = getNumberOfDigits(n);

	// Work our way right to left through the number.
	switch (digitCount) {
		case 0:
			break;
		case 1:
			fourthDigit = currentNumber;
			break;
		case 2:
			// Use division remainder to get the ones number
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			// Use division by 10 to remove the ones number
			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;
			break;
		case 3:
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			secondDigit = currentDigit;
			break;
		case 4:
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			secondDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			firstDigit = currentDigit;
			break;
	}

	if(debugging) {
		puts("[DEBUG] Number values before encryption value shifting.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	// Value shifting
	firstDigit = (firstDigit + 7) % 10;
	secondDigit = (secondDigit + 7) % 10;
	thirdDigit = (thirdDigit + 7) % 10;
	fourthDigit = (fourthDigit + 7) % 10;

	if(debugging) {
		puts("[DEBUG] Number values after encryption value shifting.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	// Position shifting
	swapDigit = firstDigit;
	firstDigit = thirdDigit;
	thirdDigit = swapDigit;

	swapDigit = secondDigit;
	secondDigit = fourthDigit;
	fourthDigit = swapDigit;

	if(debugging) {
		puts("[DEBUG] Number values after encryption value swapping.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	return (firstDigit * 1000) + (secondDigit * 100) + (thirdDigit * 10) + fourthDigit;
}

/*
 * Decryption is the opposite
 * 1) Swap 1st and 3rd digits and 2nd and 4th digits.
 * 2) Replace each digit with (currentDigit + 10) - 7
 */
unsigned short int decrypt(unsigned short int n)
{
	unsigned short int firstDigit, secondDigit, thirdDigit, fourthDigit, swapDigit, digitCount, currentNumber, currentDigit;

	// Padding with zereos if necessary.
	firstDigit = 0;
	secondDigit = 0;
	thirdDigit = 0;
	fourthDigit = 0;

	currentNumber = n;
	digitCount = getNumberOfDigits(n);

	// Work our way right to left through the number.
	switch (digitCount) {
		case 0:
			break;
		case 1:
			fourthDigit = currentNumber;
			break;
		case 2:
			// Use division remainder to get the ones number
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			// Use division by 10 to remove the ones number
			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;
			break;
		case 3:
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			secondDigit = currentDigit;
			break;
		case 4:
			currentDigit = currentNumber % 10;
			fourthDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			thirdDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			secondDigit = currentDigit;

			currentNumber /= 10;
			currentDigit = currentNumber % 10;
			firstDigit = currentDigit;
			break;
	}

	if(debugging) {
		puts("[DEBUG] Number values before decryption value swapping.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	// Position shifting
	swapDigit = firstDigit;
	firstDigit = thirdDigit;
	thirdDigit = swapDigit;

	swapDigit = secondDigit;
	secondDigit = fourthDigit;
	fourthDigit = swapDigit;

	if(debugging) {
		puts("[DEBUG] Number values after decryption value swapping.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	// Value shifting. Need mod 10 incase the number is higher than 10 from encryption.
	firstDigit = ((firstDigit + 10) - 7) % 10;
	secondDigit = ((secondDigit + 10) - 7) % 10;
	thirdDigit = ((thirdDigit + 10) - 7) % 10;
	fourthDigit = ((fourthDigit + 10) - 7) % 10;

	if(debugging) {
		puts("[DEBUG] Number values after decryption value shifting.");
		printf("n was %hu\n", n);
		printf("firstDigit is %hu\n", firstDigit);
		printf("secondDigit is %hu\n", secondDigit);
		printf("thirdDigit is %hu\n", thirdDigit);
		printf("fourthDigit is %hu\n", fourthDigit);
	}

	return (firstDigit * 1000) + (secondDigit * 100) + (thirdDigit * 10) + fourthDigit;
}
