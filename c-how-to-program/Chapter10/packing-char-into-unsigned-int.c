#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printBits(unsigned value);
void printLine(int size);
void pack4Chars(char c1, char c2, char c3, char c4);

int main(void)
{
	char c1, c2, c3, c4;

	puts("# Packing Chars Into Unsigned Int With Leftshift & Inclusive OR");
	puts("Enter four chars: ");
	scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

	printf("The bits of %c is: \n", c1);
	printBits(c1);
	printf("The bits of %c is: \n", c2);
	printBits(c2);
	printf("The bits of %c is: \n", c3);
	printBits(c1);
	printf("The bits of %c is: \n", c4);
	printBits(c2);


	pack4Chars(c1, c2, c3, c4);

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

void printLine(int size)
{
	int i;

	for(i = 0; i < size; i++) {
		putchar('-');
	}
	putchar('\n');
}

void pack4Chars(char c1, char c2, char c3, char c4)
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
	c <<= 8;
	c |= c3;
	puts("## After c1+c2 | c3");
	printBits(c);
	
	c <<= 8;
	c |= c4;
	puts("## After c1+c2+c3 | c4");
	printBits(c);
	
}

