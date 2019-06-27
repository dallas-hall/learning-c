#include <stdlib.h>
#include <stdio.h>
/*
 * Defines platform specific limits to types.
 * Located in /usr/include/limits.h
 * CHAR_BIT is how big a char is on this system, which is 8 bits
 */
#include <limits.h> 

void printBits(unsigned value);
void printBitsReversed(unsigned value);

int main(void)
{
	unsigned x;

	puts("# Binary Printing - Reversed Bits");
	puts("Enter a number: ");
	scanf("%u", &x);

	printBits(x);
	printBitsReversed(x);

	return EXIT_SUCCESS;
}

void printBits(unsigned value)
{
	unsigned c;
	/*
 	 * Left shift << moves the bits across to the left by the specified amount, adding in 0s from the right.
	 * Right shift >> does the opposite, shifts bits across to the right the specified amount, adding 0s from the left.
	 *
	 * Start with 1, which in binary is 00000000 00000000 00000000 00000001
	 * Left shift 1 by 31, which is now 10000000 00000000 00000000 00000000
	 *
	 * unsigned mask = 1 << 31;
	 *
	 * Using CHAR_BIT * sizeof(unsigned) - 1 as the mask, this makes it platform independent.
	 * It does this by using the platforms deinfition of how many bits in a char. In *nix look inside of /usr/include/limits.h
	 * On my machine this is 8.
	 */
	unsigned mask = 1 << (CHAR_BIT * sizeof(unsigned) - 1);
	printf("%10u = ", value);


	/*
	 * In this case, starting the loop at 1 makes it easier to control the printing of byte spaces (every 8 bits on my machine).
	 * It also goes through the correct number of bits for that type.
	 * This loop will walk the bits from left to right. From the most signficant bit (largest number) on the right to the lest significant bit (smallest number) on the left.
	 */
	for(c = 1; c <= CHAR_BIT * sizeof(unsigned); c++) {
		/*
		 * Apply AND bitmask 1 bit at a time.
		 * We could either shift the mask to walk through the bits, of shift the value to walk through the bits. We are shifting the value. The mask would need to be right shifted.
		 *
		 * Use <<= to left shift the inputted number by one, adding 0s from the right.
		 * This allows us to inspect each bit one at a time (iteration). This is because we move each bit along by 1 and inspect that single bit.
		 * When a 1 from value is present, 1 is printed. Otherwise 0.
		 */
		putchar( value & mask ? '1' : '0');
		/*
		 * Left shift by one
		 */
		value <<= 1;

		/*
		 * Place a space between each byte boundary, machine independent.
		 */ 
		if (c % CHAR_BIT == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}

void printBitsReversed(unsigned value)
{
	unsigned c;
	/*
	 * Start with 1, which in binary is 00000000 00000000 00000000 00000001
	 */
	unsigned mask = 1;
	int bitCounter = 0;

	printf("%10u = ", value);

	/*
	 * Starting the loop at the size of an unsigned int and ending it at 1 makes it go through the correct number of bits for that type.
	 * This loop will walk the bits from right to left. From the least signficant bit (smallest number) on the right to the most significant bit (largest number) on the right.
	 */
	for(c = CHAR_BIT * sizeof(unsigned); c > 0; c--) {
		bitCounter++;
		/*
		 * Apply AND bitmask 1 bit at a time.
		 * We could either shift the mask to walk through the bits, or shift the value to walk through the bits. We are shifting the value. The mask would need to be left shifted.
		 *
		 * Use >>= to right shift the inputted number by one, adding 0s from the left.
		 * This allows us to inspect each bit one at a time (iteration). This is because we move each bit along by 1 and inspect that single bit.
		 * When a 1 from value is present, 1 is printed. Otherwise 0.
		 */
		putchar( value & mask ? '1' : '0');
		/*
		 * Right shift by one.
		 */
		value >>= 1;

		/*
		 * Place a space between each byte boundary, machine independent.
		 */ 
		if (bitCounter % CHAR_BIT == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}
