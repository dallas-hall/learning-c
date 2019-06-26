#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printBits(unsigned value);
void printLine(int size);
void packChars(char c1, char c2);

int main(void)
{
	char c1, c2;

	puts("# Packing 2 char's Into unsigned int Using Leftshift");
	puts("Enter two chars: ");
	scanf("%c%c", &c1, &c2);

	printf("The bits of %c is: \n", c1);
	printBits(c1);
	printf("The bits of %c is: \n", c2);
	printBits(c2);

	packChars(c1, c2);

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

void packChars(char c1, char c2)
{
	/*
	 * Shifting left by 8 and then ORing together will result in both characters.
	 */ 
	unsigned c = c1;
	unsigned inclusiveOrMask = c2;

	/*
	 * Shift 8 bits to the left to allow space for the next char.
	 */ 
	c <<= 8;
	puts("## After c1 <<= 8");
	printBits(c);
	

	c |= inclusiveOrMask;	
	puts("## After c1 | c2");
	printBits(c);

	/*
	 * Repeat the above process until you up your data type.
	 */ 
}
