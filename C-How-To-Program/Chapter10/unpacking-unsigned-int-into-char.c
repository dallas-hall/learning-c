#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printBits(unsigned value);
void printLine(int size);
void unpack4Chars(unsigned chars);

int main(void)
{
	/*
	 * 4 chars of a, b, c, and d.
	 * 1633837924 = 01100001 01100010 01100011 01100100
	 */ 
	unsigned packedChars = 1633837924;

	puts("# Unpacking Chars From Unsigned Int With Right Shift & AND");
	printf("The bits of %u is: \n", packedChars);
	printBits(packedChars);

	unpack4Chars(packedChars);

	return EXIT_SUCCESS;
}

void printBits(unsigned value)
{
	unsigned c;
	/*
 	 * Left shift moves the bits across to the left by the specified amount, adding in 0s from the right.
	 * Right shift does the opposite, shifts bits across to the right the specified amount, adding 0s from the left.
	 * Left shift the bits by 31, which creates
	 * 10000000 00000000 00000000 00000000
	 *
	 * unsigned mask = 1 << 31;
	 *
	 * Using CHAR_BIT * sizeof(unsigned) - 1 as the mask, this makes it platform independent.
	 * It does this by using the platforms deinfition of how many bits in a char.
	 * On my machine this is 8.
	 */
	unsigned mask = 1 << (CHAR_BIT * sizeof(unsigned) - 1);

	printf("%10u = ", value);


	/*
	 * Platform independent swap. Explained above
	 *
	 * for(c = 1; c <= 32; c++) {
	 */
	for(c = 1; c <= CHAR_BIT * sizeof(unsigned); c++) {
		/*
		 * Apply AND bitmask 1 bit at a time.
		 * Use <<= to left shift the inputted number by one, adding 0s from the right.
		 * This allows us to inspect each bit one at a time (iteration). This is because we move each bit along by 1 and inspect that single bit.
		 * When a 1 from value is present, 1 is printed. Otherwise 0.
		 */
		putchar( value & mask ? '1' : '0');
		/*
		 * Left shift by one
		 */
		value <<= 1;

		if (c % 8 == 0) {
			putchar(' ');
		}
	}
	putchar('\n');

}

void printLine(int size)
{
	int i;

	for(i = 0; i < size; i++) {
		putchar('-');
	}
	putchar('\n');
}

void unpack4Chars(unsigned chars)
{
	/*
	 * 4278190080 is 11111111 00000000 00000000 0000000
	 * Will will shift this when moving through the unsigned int containing chars.
	 */ 
	unsigned andMask = 4278190080;
	char c1, c2, c3, c4;

	puts("The original AND mask bits are: ");
	printBits(andMask);

	/*
	 * Use the AND mask to extract the first char, which is the the 8 bits on the left.
	 * Shift the result right 24 bits, so we can fit it into a char type.
	 * Shift the AND mask right 8 bits, so we can get the next char.
	 * Repeat this process, remebering to decrement the result shifting and mask by 8 each step.
	 * Don't shift the last char though, its already correct.
	 */ 
	c1 = (chars & andMask) >> 24;
	puts("After AND mask, char 1 is: ");
	printBits(c1);

	andMask >>= 8;
	c2 = (chars & andMask) >> 16;
	puts("After AND mask, char 2 is: ");
	printBits(c2);

	andMask >>= 8;
	c3 = (chars & andMask) >> 8;
	puts("After AND mask, char 3 is: ");
	printBits(c3);

	andMask >>= 8;
	c4 = chars & andMask;
	puts("After AND mask, char 4 is: ");
	printBits(c4);
}
