#include <stdlib.h>
#include <stdio.h>
/*
 * Defines platform specific limits to types.
 * Located in /usr/include/limits.h
 * CHAR_BIT is how big a char is on this system, which is 8 bits
 */
#include <limits.h> 


void printBits(unsigned value);
void printLine(int size);

int main(void)
{
	unsigned n1, mask;
	n1 = 65535;
	mask = 1;

	puts("# Bitwise Operators");
	puts("## Bitwise AND Operator &");
	printBits(n1);
	printBits(mask);
	printLine(CHAR_BIT * sizeof(unsigned) + 16);
	printBits(n1 & mask);
	
	puts("\n## Bitwise OR Operator |");
	n1 = 15;
	mask = 241;
	printBits(n1);
	printBits(mask);
	printLine(CHAR_BIT * sizeof(unsigned) + 16);
	printBits(n1 | mask);

	puts("\n## Bitwise exclusive OR Operator ^");
	n1 = 139;
	mask = 199;
	printBits(n1);
	printBits(mask);
	printLine(CHAR_BIT * sizeof(unsigned) + 16);
	printBits(n1 ^ mask);

	/*
	 * Turns all 0s to 1s and all 1s to 0s.
	 */
	puts("\n## One's Complement ~");
	n1 = 21845;
	printBits(n1);
	printLine(CHAR_BIT * sizeof(unsigned) + 16);
	printBits(~n1);
	

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